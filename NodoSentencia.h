#ifndef NODOSENTENCIA
#define NODOSENTENCIA
#include "nodobasico.h"
#include <iterator>
#include <string>

class NodoSentencia
{
public:
    NodoBasico * basico;
	NodoSentencia()
	{

	}

    virtual void validarSemantica() =0;
    virtual void interpretar()=0;
};
#endif
