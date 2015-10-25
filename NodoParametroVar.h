#ifndef NODOPARAMETROVAR
#define NODOPARAMETROVAR
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"


class NodoParametroVar : public NodoSentencia
{
public:


    TipoV* tipoVariable;

	NodoLiteralCadena* literalCadena;

    NodoParametroVar(TipoV * tipoVariable, NodoLiteralCadena  *literalCadena,NodoBasico * basico)
	{
		this->tipoVariable = tipoVariable;
		this->literalCadena = literalCadena;
        this->basico = basico;
        this->basico->nombreNodo = "NodoParametroVar";

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
