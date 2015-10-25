#ifndef NODOVERDADERO
#define NODOVERDADERO
#include "NodoExpression.h"
#include "tipobooleano.h"
#include "valorbooleano.h"

class NodoVerdadero : public NodoExpression
{
public:
	

    NodoVerdadero(NodoBasico * basico)
	{
        this->nodoBasico = basico;
         this->nodoBasico->nombreNodo = "NodoVerdadero";
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
        return new ValorBooleano(true);
    }
};
#endif
