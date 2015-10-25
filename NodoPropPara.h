#ifndef NODOPROPPARA
#define NODOPROPPARA

#include "NodoExpression.h"
#include "NodoId.h"
#include "NodoSentencia.h"




class NodoPropPara : public NodoSentencia
{
public:


	NodoExpression* variable;

    NodoExpression* valorInicial;

    NodoExpression* valorFinal;

    std::list<NodoSentencia*>* codigo;

    NodoPropPara(NodoExpression * variable, NodoExpression *exp, NodoExpression * expr2, std::list<NodoSentencia*> *lista,NodoBasico * basico)
	{
		this->variable = variable;
        this->valorInicial = exp;
        this->valorFinal = expr2;
        this->codigo = lista;
        this->basico = basico;
        this->basico->nombreNodo = "NodoPropPara";

	}

public:
    void validarSemantica()
    {
        if(!(variable->validarSemantica()->nombre == "TipoEntero"))
        {
             throw ExcepcionSemantica("Se esperaba  variable entero");
        }
        if (!(valorInicial->validarSemantica()->nombre == "TipoEntero"))
        {
           throw ExcepcionSemantica("Se esperaba  Expresion inicial entero");
        }
       if (!(valorFinal->validarSemantica()->nombre == "TipoEntero"))
       {
           throw  ExcepcionSemantica("Se esperaba  Expresion final entero");
       }
        for (list<NodoSentencia*>::iterator it = codigo->begin();it!=codigo->end();++it){
           (*it)->validarSemantica();
        }
    }




    // NodoSentencia interface
public:
    void interpretar()
    {
        NodoId* nodoId = (dynamic_cast<NodoId*>(variable));
       TablaSimbolos::obtenerInstancia()->tablaValores.AsignarValorVariable(nodoId->id,valorInicial->evaluar());
        ValorEntero* valorFinal = (dynamic_cast<ValorEntero*>(this->valorFinal->evaluar()));
        while ((dynamic_cast<ValorEntero*>(nodoId->evaluar()))->valor<=valorFinal->valor)
        {

            for (list<NodoSentencia*>::iterator it = codigo->begin();it!=codigo->end();++it){
               (*it)->interpretar();
            }

            TablaSimbolos::obtenerInstancia()->tablaValores.AsignarValorVariable(nodoId->id,new ValorEntero(((dynamic_cast<ValorEntero*>(nodoId->evaluar())->valor+1))));
        }
    }
};
#endif
