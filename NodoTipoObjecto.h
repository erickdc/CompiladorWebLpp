#ifndef NODOTIPOOBJECTO
#define NODOTIPOOBJECTO
#include "NodoLiteralCadena.h"
#include "NodoSentencia.h"




class NodoTipoObjecto : public TipoV
{
public:
    NodoLiteralCadena * nombreObjecto;

    NodoTipoObjecto(NodoLiteralCadena * nombre, NodoBasico * basico) :TipoV(basico)
	{

        this->nombreObjecto = nombre;
           this->nombre = nombre->valor;
        this->nodoBasico->nombreNodo = nombre->valor;


	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {

    }

    // TipoV interface
public:
    ValorInterpretado *valorInterpretadoDefault()
    {

    }
};
#endif
