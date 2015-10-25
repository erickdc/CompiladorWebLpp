#ifndef NODOLITERALENTERO
#define NODOLITERALENTERO
#include "NodoExpression.h"
#include "tipoentero.h"
#include "valorentero.h"

class NodoLiteralEntero : public NodoExpression
{
public:
	int valor;

    NodoLiteralEntero(int valor, NodoBasico * basico)
	{
		this->valor = valor;
        this->nodoBasico = basico;
        this->nodoBasico->nombreNodo = "NodoLiteralEntero";

	}

    // NodoExpression interface
public:
    TipoV* validarSemantica()
    {
        return new TipoEntero(nodoBasico);
    }

    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        return new ValorEntero(valor);
    }
};
#endif
