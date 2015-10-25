#ifndef NODOTIPOVARIABLEARREGLO
#define NODOTIPOVARIABLEARREGLO
#include "NodoSentencia.h"
#include "nodobasico.h"
#include "tipov.h"


class NodoTipoVariableArreglo : public TipoV
{
public:
	NodoSentencia * listaEnteros;
    TipoV * tipoVariable;
	
    NodoTipoVariableArreglo(NodoSentencia * listaEnteros, TipoV * tipoVariable,NodoBasico * basico):TipoV(basico)
	{
		this->listaEnteros = listaEnteros;
		this->tipoVariable = tipoVariable;
        this->nombre = "TipoArreglo";
         this->nodoBasico->nombreNodo = "TipoArreglo";
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
