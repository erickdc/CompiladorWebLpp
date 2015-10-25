#ifndef NODOLISTALITERALENTEROS
#define NODOLISTALITERALENTEROS
#include "NodoSentencia.h"
#include <list>
#include "NodoLiteralEntero.h"




class NodoListaLiteralEnteros : public NodoSentencia
{
public:
	std::list<NodoLiteralEntero*> *lista;

    NodoListaLiteralEnteros(std::list<NodoLiteralEntero*> *lista, NodoBasico * basico)
	{
		this->lista = lista;
        this->basico = basico;
        this->basico->nombreNodo = "NodoListaLiteralEnteros";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {

    }

    // NodoSentencia interface
public:
    void interpretar()
    {

    }
};
#endif
