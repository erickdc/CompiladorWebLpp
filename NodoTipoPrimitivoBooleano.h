#ifndef NODOTIPOPRIMITIVOBOOLEANO
#define NODOTIPOPRIMITIVOBOOLEANO
#include "NodoSentencia.h"


class NodoTipoPrimitivoBooleano : public NodoSentencia
{
public:


    NodoTipoPrimitivoBooleano(NodoBasico * basico)
	{
        this->basico =basico;
         this->basico->nombreNodo = "NodoTipoPrimitivoBooleano";
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
