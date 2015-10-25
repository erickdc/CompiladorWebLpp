#ifndef NODOREGISTRO
#define NODOREGISTRO
#include "NodoSentencia.h"
#include "NodoLiteralCadena.h"
#include "tablasimbolos.h"
#include <list>


class NodoRegistro : public NodoSentencia
{
public:
	NodoLiteralCadena *nombre;
	std::list<NodoSentencia*>* declaraciones;
    NodoRegistro(NodoLiteralCadena * nombre, std::list<NodoSentencia*>* declaraciones,NodoBasico * basico)
	{
		this->nombre = nombre;
		this->declaraciones = declaraciones;
        this->basico =basico;
        this->basico->nombreNodo = "NodoRegistro";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        TablaSimbolos::obtenerInstancia()->status =2;
        TablaSimbolos::obtenerInstancia()->declararRegistro(nombre->valor);
        for (list<NodoSentencia*>::iterator it = declaraciones->begin();it!=declaraciones->end();++it){
           (*it)->validarSemantica();
        }
         TablaSimbolos::obtenerInstancia()->status =0;

    }

    // NodoSentencia interface
public:
    void interpretar()
    {

    }
};
#endif
