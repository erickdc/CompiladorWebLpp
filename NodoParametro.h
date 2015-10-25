#ifndef NODOPARAMETRO
#define NODOPARAMETRO
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"
#include "tablasimbolos.h"


class NodoParametro : public NodoSentencia
{
public:


    TipoV* tipoVariable;

	NodoLiteralCadena* literalCadena;

    NodoParametro(TipoV * tipoVariable, NodoLiteralCadena  *literalCadena, NodoBasico * basico)
	{
		this->tipoVariable = tipoVariable;
        this->literalCadena = literalCadena;
        this->basico = basico;
        this->basico->nombreNodo = "NodoParametro";

    }

    // NodoSentencia interface
public:
    void validarSemantica()
    {

        TablaSimbolos::obtenerInstancia()->declararVariableFuncion(TablaSimbolos::obtenerInstancia()->infoF.nombreFuncion,literalCadena->valor, tipoVariable);
        TablaSimbolos::obtenerInstancia()->declararParametroFuncion(TablaSimbolos::obtenerInstancia()->infoF.nombreFuncion,literalCadena->valor, tipoVariable);
    }

    // NodoSentencia interface
public:
    void interpretar()
    {

    }
};
#endif
