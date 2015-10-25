#ifndef NODOFUNCIONENCABEZADO
#define NODOFUNCIONENCABEZADO
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"
#include "tablasimbolos.h"


class NodoFuncionEncabezado : public NodoSentencia
{
public:


    TipoV* tipoVariable;

	NodoLiteralCadena* nombre;

	std::list<NodoSentencia*>* listaArgumentos;

    NodoFuncionEncabezado(NodoLiteralCadena * nombre, std::list<NodoSentencia * >* listaArgumentos, TipoV * tipoVariable,NodoBasico * basico)
	{
		this->nombre = nombre;
		this->listaArgumentos = listaArgumentos;
		this->tipoVariable = tipoVariable;
        this->basico = basico;
        this->basico->nombreNodo = "NodoFuncionEncabezado";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        TablaSimbolos::obtenerInstancia()->infoF.tipoRetorno = tipoVariable;
        TablaSimbolos::obtenerInstancia()->infoF.nombreFuncion = nombre->valor;
        TablaSimbolos::obtenerInstancia()->declararFuncion(TablaSimbolos::obtenerInstancia()->infoF.nombreFuncion,TablaSimbolos::obtenerInstancia()->infoF.tipoRetorno);

        for (list<NodoSentencia*>::iterator it = listaArgumentos->begin();it!=listaArgumentos->end();++it){
           (*it)->validarSemantica();
        }
    }

    // NodoSentencia interface
public:
    void interpretar()
    {
        TablaSimbolos::obtenerInstancia()->infoF.tipoRetorno = tipoVariable;
        TablaSimbolos::obtenerInstancia()->infoF.nombreFuncion = nombre->valor;

    }
};
#endif
