#ifndef NODOLITERALCADENA
#define NODOLITERALCADENA
#include "NodoExpression.h"
#include "tipocadena.h"
#include "valorcadena.h"

class NodoLiteralCadena : public NodoExpression
{
public:
	std::string valor;

    NodoLiteralCadena(std::string valor,NodoBasico * basico)
	{
		this->valor = valor;
        this->nodoBasico = basico;
        this->nodoBasico->nombreNodo = "NodoLiteralCadena";

	}

    // NodoExpression interface
public:
    TipoV* validarSemantica()
    {
        return new TipoCadena(nodoBasico);
    }

    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        return new ValorCadena(valor);
    }
};
#endif
