#ifndef NODOMULTIPLICACION
#define NODOMULTIPLICACION
#include "NodoExpression.h"
#include "NodoOperacionBinaria.h"
#include "tipobooleano.h"
#include "tipoentero.h"
#include "tiporeal.h"
#include "valorcadena.h"
#include "valorentero.h"
#include "valorflotante.h"

class NodoMultiplicacion : public NodoOperacionBinaria
{
public:
    NodoMultiplicacion(NodoExpression* izquierdo, NodoExpression* derecho,NodoBasico * basico) :NodoOperacionBinaria(izquierdo, derecho,basico)
	{
        this->nodoBasico->nombreNodo = "NodoMultiplicacion";
        this->reglas["TipoEnteroxTipoEntero"] = new TipoEntero(basico);
        this->reglas["TipoRealxTipoReal"] = new TipoReal(basico);
        this->reglas["TipoEnteroxTipoReal"] = new TipoReal(basico);
        this->reglas["TipoRealxTipoEntero"] = new TipoReal(basico);
        this->reglas["TipoBooleanoxTipoBooleano"] = new TipoBooleano(basico);

	}



    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        ValorInterpretado *tipoIzquierdo = izquierdo->evaluar();
        ValorInterpretado *tipoDerecha = derecho->evaluar();
        if (tipoIzquierdo->nombreTipo=="TipoEntero" && tipoDerecha->nombreTipo=="TipoEntero")
        {

             return new ValorEntero((dynamic_cast<ValorEntero*>(tipoIzquierdo))->valor * (dynamic_cast<ValorEntero*>(tipoDerecha))->valor);
        }
        else if (tipoIzquierdo->nombreTipo=="TipoReal" && tipoDerecha->nombreTipo=="TipoReal")
        {
            return new ValorFlotante((dynamic_cast<ValorFlotante*>(tipoIzquierdo))->valor * (dynamic_cast<ValorFlotante*>(tipoDerecha))->valor);
        }
        else if (tipoIzquierdo->nombreTipo=="TipoReal" && tipoDerecha->nombreTipo=="TipoEntero")
        {
            return new ValorFlotante((dynamic_cast<ValorFlotante*>(tipoIzquierdo))->valor * (dynamic_cast<ValorEntero*>(tipoDerecha))->valor);
        }
        else if (tipoIzquierdo->nombreTipo=="TipoEntero" && tipoDerecha->nombreTipo=="TipoReal")
        {
            return new ValorFlotante((dynamic_cast<ValorEntero*>(tipoIzquierdo))->valor * (dynamic_cast<ValorFlotante*>(tipoDerecha))->valor);
        }
        return NULL;


    }
};
#endif
