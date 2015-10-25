#ifndef NODOPROPSI
#define NODOPROPSI
#include "NodoSentencia.h"
#include "NodoExpression.h"
#include "excepcionsemantica.h"
#include "valorbooleano.h"
#include "valorentero.h"
#include <list>


class NodoPropSi : public NodoSentencia
{
public:


    NodoExpression* condicion;

    std::list<NodoSentencia*>*codigo;

	NodoSentencia* nodoElse;

    NodoPropSi(NodoExpression *exp, std::list<NodoSentencia*>*lista, NodoSentencia* nodoElse,NodoBasico * basico)
	{

        this->condicion = exp;
        this->codigo = lista;
		this->nodoElse = nodoElse;
        this->basico = basico;
        this->basico->nombreNodo = "NodoPropSi";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        if (!(condicion->validarSemantica()->nombre=="TipoBooleano"))
              throw ExcepcionSemantica("Se esperaba expresion booleana en la sentencia SI");

        for (list<NodoSentencia*>::iterator it = codigo->begin();it!=codigo->end();++it){
           (*it)->validarSemantica();
        }
        if(nodoElse!=NULL){
            nodoElse->validarSemantica();

        }
    }

    // NodoSentencia interface
public:
    void interpretar()
    {

        if((dynamic_cast<ValorBooleano*>(condicion->evaluar()))->tipo)
        {
            for (list<NodoSentencia*>::iterator it = codigo->begin();it!=codigo->end();++it){
               (*it)->interpretar();
            }
        }else{
            if(nodoElse!=NULL){
                nodoElse->interpretar();
            }
        }

    }
};
#endif
