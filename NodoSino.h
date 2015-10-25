#ifndef NODOSINO
#define NODOSINO
#include "NodoSentencia.h"
#include <list>


class NodoSino : public NodoSentencia
{
public:


    std::list<NodoSentencia*>* codigo;

    NodoSino(std::list<NodoSentencia*>* lista,NodoBasico * basico)
	{
        this->codigo = lista;
        this->basico = basico;
        this->basico->nombreNodo = "NodoSino";
	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        for (list<NodoSentencia*>::iterator it = codigo->begin();it!=codigo->end();++it){
           (*it)->validarSemantica();
        }
    }

    // NodoSentencia interface
public:
    void interpretar()
    {
        for (list<NodoSentencia*>::iterator it = codigo->begin();it!=codigo->end();++it){
           (*it)->interpretar();
        }
    }
};
#endif
