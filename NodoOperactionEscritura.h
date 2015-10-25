#ifndef NODOOPERACIONESCRITURA
#define NODOOPERACIONESCRITURA
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"


class NodoOperacionEscritura : public NodoSentencia
{
public:




    NodoOperacionEscritura(NodoBasico * basico)
	{
        this->basico = basico;
        this->basico->nombreNodo = "NodoOperacionEscritura";

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
