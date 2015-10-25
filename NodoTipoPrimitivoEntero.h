#ifndef NODOTIPOPRIMITIVOENTERO
#define NODOTIPOPRIMITIVOENTERO
#include "NodoSentencia.h"


class NodoTipoPrimitivoEntero : public NodoSentencia
{
public:


    NodoTipoPrimitivoEntero(NodoBasico *basico)
	{
		
        this->basico = basico;
        this->basico->nombreNodo = "NodoTipoPrimitivoEntero";
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
