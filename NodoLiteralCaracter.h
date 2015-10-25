#pragma once
#ifndef NODOLITERALCARACTER
#define NODOLITERALCARACTER
#include "NodoExpression.h"
#include "tipocaracter.h"
#include "valorcaracter.h"

class NodoLiteralCaracter : public NodoExpression
{
public:
	char valor;

    NodoLiteralCaracter(char valor ,NodoBasico *basico)
	{
		this->valor = valor;
        this->nodoBasico = basico;
        this->nodoBasico->nombreNodo = "NodoLiteralCaracter";

	}

    // NodoExpression interface
public:
    TipoV* validarSemantica()
    {
        return new TipoCaracter(nodoBasico);
    }

    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        return new ValorCaracter(valor);
    }
};
#endif
