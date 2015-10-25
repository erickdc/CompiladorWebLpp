#ifndef NODOCASO
#define NODOCASO
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"
#include "excepcionsemantica.h"


class NodoCaso
{
public:


	std::list<NodoSentencia*>* listaProposiciones;

	std::list<NodoExpression*>* listaLiterales;
    NodoBasico *basico;
    NodoCaso(std::list<NodoExpression*>*listaLiterales, std::list<NodoSentencia*>* listaProposiciones,NodoBasico * basico)
	{
		this->listaLiterales = listaLiterales;
		this->listaProposiciones = listaProposiciones;
        this->basico = basico;
        this->basico->nombreNodo = "NodoCaso";

	}

    // NodoSentencia interface
public:
    void validarSemantica(TipoV *tipo)
    {
        for (list<NodoExpression*>::iterator it2 = listaLiterales->begin();it2!=listaLiterales->end();++it2){

            if(tipo->nombre!= (*it2)->validarSemantica()->nombre){
                throw  ExcepcionSemantica("Tipo no coincide con el tipo de caso");
            }
        }
        for (list<NodoSentencia*>::iterator it = listaProposiciones->begin();it!=listaProposiciones->end();++it){
           (*it)->validarSemantica();
        }


    }
};
#endif
