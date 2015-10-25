#ifndef NODOPROPLEER
#define NODOPROPLEER
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"


class NodoPropLeer : public NodoSentencia
{
public:


	std::list<NodoExpression*>* listaVariable;

	NodoExpression* variable;

    NodoPropLeer(NodoExpression * variable, std::list<NodoExpression*> * listaVariable,NodoBasico * basico)
	{
		this->variable = variable;
		this->listaVariable = listaVariable;
        this->basico = basico;
        this->basico->nombreNodo = "NodoPropLeer";
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
