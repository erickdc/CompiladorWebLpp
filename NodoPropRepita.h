#ifndef NODOPROPREPITA
#define NODOPROPREPITA
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "valorbooleano.h"


class NodoPropRepita : public NodoSentencia
{
public:


    NodoExpression* condicion;

    list<NodoSentencia*>* codigo;

    NodoPropRepita(list<NodoSentencia*>* lista, NodoExpression* exp,NodoBasico* basico )
	{
        this->codigo = lista;
        this->condicion = exp;
        this->basico = basico;
        this->basico->nombreNodo = "NodoPropRepita";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        for (list<NodoSentencia*>::iterator it = codigo->begin();it!=codigo->end();++it){
           (*it)->validarSemantica();
        }
        if (!(condicion->validarSemantica()->nombre=="TipoBooleano"))
              throw ExcepcionSemantica("Se esperaba expresion booleana en la sentencia REPITA HASTA");


    }

    // NodoSentencia interface
public:
    void interpretar()
    {
        do{
            for (list<NodoSentencia*>::iterator it = codigo->begin();it!=codigo->end();++it){
               (*it)->interpretar();
            }
        }while((dynamic_cast<ValorBooleano*>(condicion->evaluar()))->tipo);
    }
};
#endif
