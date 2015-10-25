#ifndef NODOSINOCASO
#define NODOSINOCASO
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"


class NodoSinoCaso : public NodoSentencia
{
public:


	std::list<NodoSentencia*>* lista;
    NodoSinoCaso(std::list<NodoSentencia*>* lista, NodoBasico * basico)
	{
		this->lista = lista;
        this->basico = basico;
        this->basico->nombreNodo = "NodoSinoCaso";
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
