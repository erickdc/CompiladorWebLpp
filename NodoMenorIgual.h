#ifndef NODOMENORIGUAL
#define NODOMENORIGUAL
#include "NodoExpression.h"
#include "NodoOperacionBinaria.h"
#include "tipobooleano.h"

class NodoMenorIgual : public NodoOperacionBinaria
{
public:
    NodoMenorIgual(NodoExpression* izquierdo, NodoExpression* derecho,NodoBasico * basico) :NodoOperacionBinaria(izquierdo, derecho,basico)
	{
        this->nodoBasico->nombreNodo = "NodoMenorIgual";
        this->reglas["TipoEnteroxTipoEntero"] = new TipoBooleano(basico);


        this->reglas["TipoRealxTipoReal"] = new TipoBooleano(basico);

	}



    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        ValorInterpretado *tipoIzquierdo = izquierdo->evaluar();
        ValorInterpretado *tipoDerecha = derecho->evaluar();
        if (tipoIzquierdo->nombreTipo=="TipoEntero" && tipoDerecha->nombreTipo=="TipoEntero")
        {

             return new ValorBooleano((dynamic_cast<ValorEntero*>(tipoIzquierdo))->valor <= (dynamic_cast<ValorEntero*>(tipoDerecha))->valor);
        }
        else if (tipoIzquierdo->nombreTipo=="TipoReal" && tipoDerecha->nombreTipo=="TipoReal")
        {
            return new ValorBooleano((dynamic_cast<ValorFlotante*>(tipoIzquierdo))->valor <= (dynamic_cast<ValorFlotante*>(tipoDerecha))->valor);
        }
        else if (tipoIzquierdo->nombreTipo=="TipoReal" && tipoDerecha->nombreTipo=="TipoEntero")
        {
            return new ValorBooleano((dynamic_cast<ValorFlotante*>(tipoIzquierdo))->valor <= (dynamic_cast<ValorEntero*>(tipoDerecha))->valor);
        }
        else if (tipoIzquierdo->nombreTipo=="TipoEntero" && tipoDerecha->nombreTipo=="TipoReal")
        {
            return new ValorBooleano((dynamic_cast<ValorEntero*>(tipoIzquierdo))->valor <= (dynamic_cast<ValorFlotante*>(tipoDerecha))->valor);
        }
        return NULL;

    }
};
#endif
