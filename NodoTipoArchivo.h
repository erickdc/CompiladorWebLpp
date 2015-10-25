#ifndef NODOTIPOARCHIVO
#define NODOTIPOARCHIVO
#include "NodoSentencia.h"
#include "tipov.h"


class NodoTipoArchivo : public TipoV
{
public:
    TipoV * tipoVariable;

    NodoTipoArchivo(TipoV * tipoVariable, NodoBasico * basico):TipoV(basico)
	{
        this->nombre = "TipoArchivo";
		this->tipoVariable = tipoVariable;

        this->nodoBasico->nombreNodo = "TipoArchivo";

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
