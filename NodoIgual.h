#ifndef NODOIGUAL
#define NODOIGUAL
#include "NodoExpression.h"
#include "NodoOperacionBinaria.h"
#include "tipobooleano.h"
#include "tipocadena.h"
#include "tipocaracter.h"
#include "valorbooleano.h"
#include "valorcadena.h"
#include "valorcaracter.h"
#include "valorentero.h"

class NodoIgual : public NodoOperacionBinaria
{
public:
    NodoIgual(NodoExpression* izquierdo, NodoExpression* derecho,NodoBasico * basico) :NodoOperacionBinaria(izquierdo, derecho,basico)
	{
        this->nodoBasico->nombreNodo = "NodoIgual";
        this->reglas["TipoBooleanoxTipoBooleano"] = new TipoBooleano(basico);
        this->reglas["TipoEnteroxTipoEntero"] = new TipoBooleano(basico);
        this->reglas["TipoCadenaxTipoCadena"] = new TipoBooleano(basico);
        this->reglas["TipoRealxTipoReal"] = new TipoBooleano(basico);
        this->reglas["TipoCaracterxTipoCaracter"] = new TipoBooleano(basico);

	}



    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        ValorInterpretado *tipoIzquierdo = izquierdo->evaluar();
        ValorInterpretado *tipoDerecha = derecho->evaluar();
        if (tipoIzquierdo->nombreTipo=="TipoEntero" && tipoDerecha->nombreTipo=="TipoEntero")
        {

             return new ValorBooleano((dynamic_cast<ValorEntero*>(tipoIzquierdo))->valor == (dynamic_cast<ValorEntero*>(tipoDerecha))->valor);
        }
        else if (tipoIzquierdo->nombreTipo=="TipoReal" && tipoDerecha->nombreTipo=="TipoReal")
        {
            return new ValorBooleano((dynamic_cast<ValorFlotante*>(tipoIzquierdo))->valor == (dynamic_cast<ValorFlotante*>(tipoDerecha))->valor);
        }
        else if (tipoIzquierdo->nombreTipo=="TipoCaracter" && tipoDerecha->nombreTipo=="TipoCaracter")
        {
            return new ValorBooleano((dynamic_cast<ValorCaracter*>(tipoIzquierdo))->valor == (dynamic_cast<ValorCaracter*>(tipoDerecha))->valor);
        }
        else if (tipoIzquierdo->nombreTipo=="TipoCadena" && tipoDerecha->nombreTipo=="TipoCadena")
        {
            return new ValorBooleano((dynamic_cast<ValorCadena*>(tipoIzquierdo))->valor == (dynamic_cast<ValorCadena*>(tipoDerecha))->valor);
        }
        return NULL;

    }
};
#endif
