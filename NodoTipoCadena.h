#ifndef NODOTIPOCADENA
#define NODOTIPOCADENA
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"
#include "NodoLiteralEntero.h"


class NodoTipoCadena : public TipoV
{
public:

	NodoLiteralEntero * cantidad;

    NodoTipoCadena(NodoLiteralEntero * cantidad,NodoBasico * basico):TipoV(basico)
	{
		this->cantidad = cantidad;
        this->nombre = "TipoCadena";
        this->nodoBasico->nombreNodo = "TipoCadena";

	}






    // TipoV interface
public:
    ValorInterpretado *valorInterpretadoDefault()
    {
        return new ValorCadena(" ");
    }
};
#endif
