#ifndef NODORETORNE
#define NODORETORNE
#include <string>
#include "NodoSentencia.h"
#include "NodoExpression.h"
#include "tablasimbolos.h"


class NodoRetorne : public NodoSentencia
{
public:
	NodoExpression *valorRetorno;
	
    NodoRetorne(NodoExpression * valor,NodoBasico *basico)
	{
		this->valorRetorno = valor;
        this->basico = basico;
        this->basico->nombreNodo = "NodoRetorne";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        TipoV * valor = valorRetorno->validarSemantica();
        if(TablaSimbolos::obtenerInstancia()->infoF.tipoRetorno->nombre != valor->nombre)
        {
            throw ExcepcionSemantica("El tipo a retonar no es el mismo");
        }
    }

    // NodoSentencia interface
public:
    void interpretar()
    {
      //  TablaSimbolos::obtenerInstancia()->tablaValores.valorRetorno:
    }
};
#endif
