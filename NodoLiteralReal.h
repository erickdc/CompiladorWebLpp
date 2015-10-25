#ifndef NODOLITERALREAL
#define NODOLITERALREAL
#include "NodoExpression.h"
#include "tiporeal.h"
#include "valorflotante.h"

class NodoLiteralReal : public NodoExpression
{
public:
	float valor;

    NodoLiteralReal(float valor,NodoBasico * nodo)
	{
		this->valor = valor;
        this->nodoBasico = nodo;
        this->nodoBasico->nombreNodo = "NodoLiteralReal";

	}

    // NodoExpression interface
public:
    TipoV *validarSemantica()
    {
        return new TipoReal(nodoBasico);
    }

    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        return new ValorFlotante(valor);
    }
};
#endif
