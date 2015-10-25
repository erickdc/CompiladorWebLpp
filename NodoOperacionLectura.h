#ifndef NODOOPERACIONLECTURA
#define NODOOPERACIONLECTURA
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"


class NodoOperacionLectura : public NodoSentencia
{
public:


	

    NodoOperacionLectura(NodoBasico * basico)
	{
        this->basico = basico;
        this->basico->nombreNodo = "NodoOperacionLectura";

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
