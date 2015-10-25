#ifndef NODOPROPABRIR
#define NODOPROPABRIR
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"


class NodoPropAbrir : public NodoSentencia
{
public:

	NodoExpression * exp;
	NodoExpression* variable;
	std::list<NodoSentencia *>* listaOperaciones;
    NodoPropAbrir(NodoExpression * exp, NodoExpression* variable, std::list<NodoSentencia *>* listaOperaciones,NodoBasico * basico)
	{
		this->exp = exp;
		this->variable = variable;
		this->listaOperaciones = listaOperaciones;
        this->basico = basico;
        this->basico->nombreNodo = "NodoPropAbrir";

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
