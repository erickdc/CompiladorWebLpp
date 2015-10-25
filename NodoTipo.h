#ifndef NODOTIPO
#define NODOTIPO
#include "NodoSentencia.h"
#include "NodoLiteralCadena.h"
#include "tablasimbolos.h"


class NodoTipo : public NodoSentencia
{
public:
	NodoLiteralCadena *nombre;
    TipoV * tipoVariable;
    NodoTipo(NodoLiteralCadena * nombre,TipoV* tipo,NodoBasico * basico)
	{
		this->nombre = nombre;
		this->tipoVariable = tipo;
        this->basico = basico;
        this->basico->nombreNodo = "NodoTipo";


	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        TablaSimbolos::obtenerInstancia()->definirTipos(nombre->valor,tipoVariable);
    }

    // NodoSentencia interface
public:
    void interpretar()
    {

    }
};
#endif
