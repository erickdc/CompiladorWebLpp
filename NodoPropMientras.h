#ifndef NODOPROPMIENTRAS
#define NODOPROPMIENTRAS
#include "NodoSentencia.h"
#include "NodoExpression.h"
#include "excepcionsemantica.h"
#include "valorbooleano.h"
#include <list>


class NodoPropMientras : public NodoSentencia
{
public:


    NodoExpression* condicion;

    std::list<NodoSentencia*>*codigo;

    NodoPropMientras(NodoExpression *exp, std::list<NodoSentencia*>*lista,NodoBasico * basico)
	{

        this->condicion = exp;
        this->codigo = lista;
        this->basico  = basico;
        this->basico->nombreNodo = "NodoPropMientras";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        if(!(condicion->validarSemantica()->nombre=="TipoBooleano"))
                 throw  ExcepcionSemantica("Se esperaba expresion booleana en la sentencia while");

        for (list<NodoSentencia*>::iterator it = codigo->begin();it!=codigo->end();++it){
           (*it)->validarSemantica();
        }
    }

    // NodoSentencia interface
public:
    void interpretar()
    {
           while((dynamic_cast<ValorBooleano*>(condicion->evaluar()))->tipo){
            for (list<NodoSentencia*>::iterator it = codigo->begin();it!=codigo->end();++it){
               (*it)->interpretar();
            }
        }

    }
};
#endif
