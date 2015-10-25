#ifndef NODOO
#define NODOO
#include "NodoOperacionBinaria.h"
#include "tipobooleano.h"
#include "valorbooleano.h"

class NodoO : public NodoOperacionBinaria
{
public:
    NodoO(NodoExpression* izquierdo, NodoExpression* derecho,NodoBasico * basico) : NodoOperacionBinaria(izquierdo, derecho,basico)
	{

        this->nodoBasico->nombreNodo = "NodoO";
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
        if(valorIzquierdo  || valorDerecho){
            return new ValorBooleano(true);
        }
        return new ValorBooleano(false);
    }
};
#endif
