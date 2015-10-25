#ifndef NODOVARIABLEARREGLO
#define NODOVARIABLEARREGLO
#include <string>
#include "NodoExpression.h"
#include "excepcionsemantica.h"
#include "tipoarreglo.h"
#include <list>

class NodoVariableArreglo : public NodoExpression
{
public:
    NodoExpression * variable;
    std::list<NodoExpression* > *dimensiones;

    NodoVariableArreglo(NodoExpression* izquierdo, std::list<NodoExpression *>*derecho,NodoBasico * basico)
	{
        this->variable = izquierdo;
        this->dimensiones = derecho;
        this->nodoBasico =basico;
         this->nodoBasico->nombreNodo = "NodoVariableArreglo";
	}

    // NodoExpression interface
public:
    TipoV* validarSemantica()
    {
        TipoV* tipo = variable->validarSemantica();
        TipoArreglo* tipoA = dynamic_cast<TipoArreglo*>(tipo);
        if (!(tipoA->nombre=="TipoArreglo"))
        {
                        throw  ExcepcionSemantica("Se esperaba una variable de tipo arreglo");
        }

        if(tipoA->dimensiones->size() != this->dimensiones->size())
        {
           throw  ExcepcionSemantica("Se esperaba una dimension de: "+(tipoA->dimensiones->size()));
        }

        for (list<NodoExpression*>::iterator it = dimensiones->begin();it!=dimensiones->end();++it)
        {
            if (!((*it)->validarSemantica()->nombre == "TipoEntero"))
            {
                throw  ExcepcionSemantica("Se esperaba expresion de tipo entero");
            }

        }



         return tipoA->tipo;

    }

    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {

    }
};
#endif
