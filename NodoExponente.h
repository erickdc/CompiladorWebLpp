#ifndef NODOEXPONENTE
#define NODOEXPONENTE
#include "NodoExpression.h"
#include "NodoOperacionBinaria.h"
#include "tipoentero.h"
#include "tiporeal.h"
#include "valorentero.h"
#include "valorflotante.h"
#include <math.h>
class NodoExponente : public NodoOperacionBinaria
{
public:
    NodoExponente(NodoExpression* izquierdo, NodoExpression* derecho, NodoBasico * basico) :NodoOperacionBinaria(izquierdo, derecho,basico)
	{
        this->nodoBasico->nombreNodo = "NodoExponente";
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

             return new ValorEntero(pow((dynamic_cast<ValorEntero*>(tipoIzquierdo))->valor ,(dynamic_cast<ValorEntero*>(tipoDerecha))->valor));
        }
        else if (tipoIzquierdo->nombreTipo=="TipoReal" && tipoDerecha->nombreTipo=="TipoReal")
        {
            return new ValorFlotante(pow((dynamic_cast<ValorFlotante*>(tipoIzquierdo))->valor ,(dynamic_cast<ValorFlotante*>(tipoDerecha))->valor));
        }
        else if (tipoIzquierdo->nombreTipo=="TipoReal" && tipoDerecha->nombreTipo=="TipoEntero")
        {
            return new ValorFlotante(pow((dynamic_cast<ValorFlotante*>(tipoIzquierdo))->valor ,(dynamic_cast<ValorEntero*>(tipoDerecha))->valor));
        }
        else if (tipoIzquierdo->nombreTipo=="TipoEntero" && tipoDerecha->nombreTipo=="TipoReal")
        {
            return new ValorFlotante(pow((dynamic_cast<ValorEntero*>(tipoIzquierdo))->valor ,(dynamic_cast<ValorEntero*>(tipoDerecha))->valor));
        }

        return NULL;
    }
};
#endif
