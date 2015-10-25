#ifndef NODODIVISIONENTERA
#define NODODIVISIONENTERA
#include "NodoExpression.h"
#include "NodoOperacionBinaria.h"
#include "tipoentero.h"
#include "valorentero.h"

class NodoDivisionEntera : public NodoOperacionBinaria
{
public:
    NodoDivisionEntera(NodoExpression* izquierdo, NodoExpression* derecho, NodoBasico * basico) :NodoOperacionBinaria(izquierdo, derecho,basico)
	{
        this->nodoBasico->nombreNodo = "NodoDivisionEntera";
        this->reglas["TipoEnteroxTipoEntero"] = new TipoEntero(basico);
	}




    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        ValorInterpretado *tipoIzquierdo = izquierdo->evaluar();
        ValorInterpretado *tipoDerecha = derecho->evaluar();
        if (tipoIzquierdo->nombreTipo=="TipoEntero" && tipoDerecha->nombreTipo=="TipoEntero")
        {

             return new ValorEntero((dynamic_cast<ValorEntero*>(tipoIzquierdo))->valor / (dynamic_cast<ValorEntero*>(tipoDerecha))->valor);
        }

        return NULL;
    }
};
#endif
