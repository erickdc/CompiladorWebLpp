#ifndef NODOFUNCION
#define NODOFUNCION
#include "NodoExpression.h"
#include <list>

class NodoFuncion : public NodoExpression
{
public:

	NodoExpression * izquierdo;
	std::list<NodoExpression* > *lista;
    NodoFuncion(NodoExpression * izquierdo , std::list<NodoExpression*>*lista,NodoBasico * basico)
	{
		this->izquierdo = izquierdo;
		this->lista = lista;
        this->nodoBasico =basico;
        this->nodoBasico->nombreNodo = "NodoFuncion";

	}

    // NodoExpression interface
public:
    TipoV* validarSemantica()
    {

    }

    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {

    }
};
#endif
