#ifndef NODOTIPOPRIMITIVOCARACTER
#define NODOTIPOPRIMITIVOCARACTER
#include "NodoSentencia.h"


class NodoTipoPrimitivoCaracter : public NodoSentencia
{
public:


    NodoTipoPrimitivoCaracter(NodoBasico *basico)
	{
        this->basico = basico;
          this->basico->nombreNodo = "NodoTipoPrimitivoCaracter";

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
