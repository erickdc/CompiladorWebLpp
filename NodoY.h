#ifndef NODOY
#define NODOY
#include "NodoOperacionBinaria.h"
#include "tipobooleano.h"
#include "valorbooleano.h"

class NodoY : public NodoOperacionBinaria
{
public:
    NodoY(NodoExpression* izquierdo, NodoExpression* derecho,NodoBasico * basico): NodoOperacionBinaria(izquierdo, derecho,basico)
	{
        this->nodoBasico->nombreNodo = "NodoY";
         this->reglas["TipoBooleanoxTipoBooleano"] = new TipoBooleano(basico);
	}



    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        ValorInterpretado *tipoIzquierdo = izquierdo->evaluar();
        ValorInterpretado *tipoDerecha = derecho->evaluar();
        bool  valorIzquierdo =(dynamic_cast<ValorBooleano*>(tipoIzquierdo))->tipo;
        bool  valorDerecho =(dynamic_cast<ValorBooleano*>(tipoDerecha))->tipo;
        if(!valorIzquierdo  || !valorDerecho){
            return new ValorBooleano(false);
        }
        return new ValorBooleano(true);
    }
};
#endif
