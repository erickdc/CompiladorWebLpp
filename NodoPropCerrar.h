#ifndef NODOPROPCERRAR
#define NODOPROPCERRAR
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"


class NodoPropCerrar : public NodoSentencia
{
public:




	NodoExpression* variable;

    NodoPropCerrar(NodoExpression* variable,NodoBasico  * basico)
	{
		this->variable = variable;
        this->basico = basico;
        this->basico->nombreNodo = "NodoPropCerrar";

		
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
