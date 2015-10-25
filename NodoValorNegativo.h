#ifndef NODOVALORNEGATIVO
#define NODOVALORNEGATIVO
#include "NodoExpression.h"
#include "valorentero.h"
#include "valorflotante.h"
#include <list>
class NodoValorNegativo : public NodoExpression
{
public:

	NodoExpression * valor;
    NodoValorNegativo(NodoExpression * valor, NodoBasico * basico)
	{
		this->valor = valor;
        this->nodoBasico= basico;
         this->nodoBasico->nombreNodo = "NodoValorNegativo";
	}

	list<NodoExpression*>* lista;

    NodoValorNegativo(list<NodoExpression*>* lista,NodoBasico * basico)
	{
		this->lista = lista;
        this->nodoBasico = basico;
         this->nodoBasico->nombreNodo = "NodoValorNegativo";
	}

    // NodoExpression interface
public:
    TipoV* validarSemantica()
    {
         TipoV * tipo ;
        if(valor!=NULL){
            tipo  = valor->validarSemantica();
        }else{
            for (list<NodoExpression*>::iterator it = lista->begin();it!=lista->end();++it){
               tipo =(*it)->validarSemantica();
            }
        }
        if(tipo->nombre =="TipoEntero" || tipo->nombre=="TipoReal"){
            return tipo;
        }
        throw ExcepcionSemantica("Tipo es incompatible debe ser entero o real ");


    }

    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        ValorInterpretado * val ;
        if(valor!=NULL){
            val= valor->evaluar();
        }else{
            for (list<NodoExpression*>::iterator it = lista->begin();it!=lista->end();++it){
               val =(*it)->evaluar();
            }
        }
        if(val->nombreTipo=="TipoEntero")
        {
            return new ValorEntero(-1*((dynamic_cast<ValorEntero*>(val))->valor));
        }
        if(val->nombreTipo== "TipoReal"){
            return new ValorFlotante(-1*((dynamic_cast<ValorFlotante*>(val))->valor));
        }

        return NULL;
    }
};
#endif
