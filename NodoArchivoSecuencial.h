#ifndef NODOARCHIVOSECUENCIAL
#define NODOARCHIVOSECUENCIAL
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"
#include "NodoLiteralEntero.h"


class NodoArchivoSecuencial : public TipoV
{
public:


    NodoArchivoSecuencial(NodoBasico * basico) :TipoV(basico)
	{
        this->nombre = "TipoArchivoSecuencial";

        this->nodoBasico->nombreNodo = "TipoArchivoSecuencial";

	}



    // TipoV interface
public:
    ValorInterpretado *valorInterpretadoDefault()
    {

    }
};
#endif
