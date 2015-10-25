#ifndef NODOEXPRESSION
#define NODOEXPRESSION
#include "nodobasico.h"
#include "tipov.h"
#include "valorinterpretado.h"
#include <iterator>
#include <string>

class NodoExpression
{
public:
    NodoBasico*nodoBasico;
    NodoExpression()
	{

	}

     virtual TipoV* validarSemantica()=0;
     virtual ValorInterpretado* evaluar() =0;
};
#endif
