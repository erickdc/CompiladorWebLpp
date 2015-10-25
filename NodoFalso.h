#ifndef NODOFALSO
#define NODOFALSO
#include "NodoExpression.h"
#include "tipobooleano.h"
#include "valorbooleano.h"

class NodoFalso : public NodoExpression
{
public:


    NodoFalso(NodoBasico * basico)
	{
        this->nodoBasico = basico;
        this->nodoBasico->nombreNodo = "NodoFalso";

	}

    // NodoExpression interface
public:
    TipoV* validarSemantica()
    {
        return new TipoBooleano(nodoBasico);
    }

    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        return new ValorBooleano(false);
    }
};
#endif
