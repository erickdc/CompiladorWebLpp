#ifndef NODODECLARACIONSUBPROGRAMA
#define NODODECLARACIONSUBPROGRAMA
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"
#include "tablasimbolos.h"


class NodoDeclaracionSubPrograma : public NodoSentencia
{
public:


	std::list<NodoSentencia*>* listaProposiciones;

	std::list<NodoSentencia*>* listaDeclaraciones;

	NodoSentencia* encabezado;

    NodoDeclaracionSubPrograma(NodoSentencia  * encabezado, std::list<NodoSentencia* > *listaDeclaraciones, std::list<NodoSentencia *> * listaProposiciones,NodoBasico * basico)
	{
		this->encabezado = encabezado;
		this->listaDeclaraciones = listaDeclaraciones;
		this->listaProposiciones = listaProposiciones;
        this->basico = basico;
        this->basico->nombreNodo = "NodoDeclaracionSubPrograma";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        TablaSimbolos::obtenerInstancia()->status =1;
        encabezado->validarSemantica();
        for (list<NodoSentencia*>::iterator it = listaDeclaraciones->begin();it!=listaDeclaraciones->end();++it){
           (*it)->validarSemantica();
        }
        for (list<NodoSentencia*>::iterator it2 = listaProposiciones->begin();it2!=listaProposiciones->end();++it2){
           (*it2)->validarSemantica();
        }
         TablaSimbolos::obtenerInstancia()->status =0;
         TablaSimbolos::obtenerInstancia()->infoF.nombreFuncion =" ";


    }

    // NodoSentencia interface
public:
    void interpretar()
    {

    }
};
#endif
