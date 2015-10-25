#ifndef NODOHTML
#define NODOHTML
#include <string>
#include "NodoSentencia.h"
#include <iostream>
class NodoHtml : public NodoSentencia
{
public:
	std::string  codigo;
    NodoHtml(std::string codigo,NodoBasico * basico)
	{
		this->codigo = codigo;
        this->basico = basico;
        this->basico->nombreNodo = "NodoHtml";

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
        cout << codigo << "\n";
    }
};
#endif
