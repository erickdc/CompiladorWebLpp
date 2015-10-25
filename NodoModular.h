#ifndef NODOMODULAR
#define NODOMODULAR
#include "NodoExpression.h"
#include "NodoOperacionBinaria.h"
#include "tipobooleano.h"
#include "valorentero.h"

class NodoModular : public NodoOperacionBinaria
{
public:
    NodoModular(NodoExpression* izquierdo, NodoExpression* derecho,NodoBasico * basico) :NodoOperacionBinaria(izquierdo, derecho,basico)
	{
        this->nodoBasico->nombreNodo = "NodoModular";
        this->reglas["TipoEnteroxTipoEntero"] = new TipoBooleano(basico);



	}



    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        ValorInterpretado *tipoIzquierdo = izquierdo->evaluar();
        ValorInterpretado *tipoDerecha = derecho->evaluar();
        if (tipoIzquierdo->nombreTipo=="TipoEntero" && tipoDerecha->nombreTipo=="TipoEntero")
        {

             return new ValorEntero((dynamic_cast<ValorEntero*>(tipoIzquierdo))->valor % (dynamic_cast<ValorEntero*>(tipoDerecha))->valor);
        }
        return NULL;
    }
};
#endif
