#ifndef NODOPROPOSICIONCASO
#define NODOPROPOSICIONCASO
#include "NodoSentencia.h"
#include <list>
#include "NodoCaso.h"
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"
#include "NodoSinoCaso.h"


class NodoProposicionCaso : public NodoSentencia
{
public:


	NodoExpression* variable;
    std::list<NodoCaso*>* listaCasos;
    NodoSinoCaso * sino;
    NodoProposicionCaso(NodoExpression* variable, std::list<NodoCaso*>* listaCasos, NodoSinoCaso * sino,NodoBasico * basico )
	{
		this->variable = variable;
		this->listaCasos = listaCasos;
		this->sino = sino;
        this->basico = basico;
        this->basico->nombreNodo = "NodoProposicionCaso";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        TipoV * tipo  = variable->validarSemantica();
        for (list<NodoCaso*>::iterator it = listaCasos->begin();it!=listaCasos->end();++it){
           (*it)->validarSemantica(tipo);
        }
        if(sino!=NULL)
        {
            sino->validarSemantica();
        }

    }

    // NodoSentencia interface
public:
    void interpretar()
    {

    }
};
#endif
