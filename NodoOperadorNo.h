#ifndef NODOOPERADORNO
#define NODOOPERADORNO
#include "NodoExpression.h"
#include "excepcionsemantica.h"
#include "tipobooleano.h"
#include "valorbooleano.h"

class NodoOperadorNo : public NodoExpression
{
public:
	NodoExpression* termino;

    NodoOperadorNo(NodoExpression* termino,NodoBasico * basico)
	{
		this->termino = termino;
        this->nodoBasico = basico;
        this->nodoBasico->nombreNodo = "NodoOperadorNo";

	}

    // NodoExpression interface
public:
    TipoV* validarSemantica()
    {
        if(termino->validarSemantica()->nombre !="TipoBooleano"){
            throw ExcepcionSemantica("Tipo es incompatible debe ser booleano ");
        }
        return new TipoBooleano(nodoBasico);

    }

    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        return new ValorBooleano((dynamic_cast<ValorBooleano*>(termino->evaluar()))->tipo?false:true);
    }
};
#endif
