#ifndef NODOVARIABLEREGISTRO
#define NODOVARIABLEREGISTRO
#include <string>
#include "NodoExpression.h"

class NodoVariableRegistro : public NodoExpression
{
public:
	NodoExpression * izquierdo, *derecho;

    NodoVariableRegistro(NodoExpression* izquierdo, NodoExpression *derecho,NodoBasico * basico)
	{
		this->izquierdo = izquierdo;
		this->derecho = derecho;
        this->nodoBasico =basico;
         this->nodoBasico->nombreNodo = "NodoVariableRegistro";
	}

    // NodoExpression interface
public:
    TipoV *validarSemantica()
    {

    }

    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {

    }
};
#endif
