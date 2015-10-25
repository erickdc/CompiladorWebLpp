#ifndef NODOPROPESCRIBIR
#define NODOPROPESCRIBIR
#include "NodoSentencia.h"
#include "NodoExpression.h"
#include <list>


class NodoPropEscribir : public NodoSentencia
{
public:


	NodoExpression* expr;

	std::list<NodoExpression*>*listaExp;

    NodoPropEscribir(NodoExpression *exp, std::list<NodoExpression*>*listaExp,NodoBasico* basico)
	{

		this->expr = exp;
		this->listaExp = listaExp;
        this->basico = basico;
        this->basico->nombreNodo = "NodoPropEscribir";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {

    }

    // NodoSentencia interface
public:
    void interpretar()
    {

    }
};
#endif
