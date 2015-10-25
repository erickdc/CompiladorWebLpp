#ifndef NODODIVISION
#define NODODIVISION
#include "NodoExpression.h"
#include "NodoOperacionBinaria.h"
#include "tipoentero.h"
#include "tiporeal.h"
#include "valorentero.h"
#include "valorflotante.h"

class NodoDivision : public NodoOperacionBinaria
{
public:
    NodoDivision(NodoExpression* izquierdo, NodoExpression* derecho,NodoBasico * basico) :NodoOperacionBinaria(izquierdo, derecho,basico)
	{
        this->nodoBasico->nombreNodo = "NodoDivision";
        this->reglas["TipoEnteroxTipoEntero"] = new TipoEntero(basico);
        this->reglas["TipoRealxTipoReal"] = new TipoReal(basico);
        this->reglas["TipoEnteroxTipoReal"] = new TipoReal(basico);
        this->reglas["TipoRealxTipoEntero"] = new TipoReal(basico);

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
        else if (tipoIzquierdo->nombreTipo=="TipoReal" && tipoDerecha->nombreTipo=="TipoReal")
        {
            return new ValorFlotante((dynamic_cast<ValorFlotante*>(tipoIzquierdo))->valor / (dynamic_cast<ValorFlotante*>(tipoDerecha))->valor);

        }  else if (tipoIzquierdo->nombreTipo=="TipoReal" && tipoDerecha->nombreTipo=="TipoEntero")
        {
            return new ValorFlotante((dynamic_cast<ValorFlotante*>(tipoIzquierdo))->valor / (dynamic_cast<ValorEntero*>(tipoDerecha))->valor);

        }  else if (tipoIzquierdo->nombreTipo=="TipoEntero" && tipoDerecha->nombreTipo=="TipoReal")
        {
            return new ValorFlotante((dynamic_cast<ValorEntero*>(tipoIzquierdo))->valor / (dynamic_cast<ValorFlotante*>(tipoDerecha))->valor);

        }
        else if (tipoIzquierdo->nombreTipo=="TipoCadena"  && tipoDerecha->nombreTipo=="TipoCadena" )
        {
            string i = (dynamic_cast<ValorCadena*>(tipoIzquierdo))->valor;
            string d = (dynamic_cast<ValorCadena*>(tipoDerecha))->valor;

            return new ValorCadena(i+d);
        }
        return NULL;
    }
};
#endif
