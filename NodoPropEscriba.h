#ifndef NODOPROPESCRIBA
#define NODOPROPESCRIBA
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"


class NodoPropEscriba : public NodoSentencia
{
public:


	NodoExpression* exp;
	list<NodoExpression*>* listaExpresiones;
    NodoPropEscriba(NodoExpression* exp,list<NodoExpression*>* listaExpresiones,NodoBasico * basico)
	{
		this->exp = exp;
		this->listaExpresiones = listaExpresiones;
        this->basico = basico;
        this->basico->nombreNodo = "NodoPropEscriba";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
            exp->validarSemantica();
            for (list<NodoExpression*>::iterator it = listaExpresiones->begin();it!=listaExpresiones->end();++it){
               (*it)->validarSemantica();
            }
    }

    // NodoSentencia interface
public:
    void interpretar()
    {
        ValorInterpretado * valor = exp->evaluar();
        cout << valor->aCadena()<<"\n";
    }
};
#endif
