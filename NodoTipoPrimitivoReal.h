#ifndef NODOTIPOPRIMITIVOREAL
#define NODOTIPOPRIMITIVOREAL
#include "NodoSentencia.h"


class NodoTipoPrimitivoReal : public NodoSentencia
{
public:


    NodoTipoPrimitivoReal(NodoBasico * basico)
	{

        this->basico = basico;
            this->basico->nombreNodo = "NodoTipoPrimitivoReal";
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
