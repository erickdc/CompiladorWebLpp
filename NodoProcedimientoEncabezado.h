#ifndef NODOPROCEDIMIENTOENCABEZADO
#define NODOPROCEDIMIENTOENCABEZADO
#include "NodoSentencia.h"
#include <list>
#include "NodoExpression.h"
#include "NodoLiteralCadena.h"
#include "tablasimbolos.h"
#include "tipovoid.h"

class NodoProcedimientoEncabezado : public NodoSentencia
{
public:


	

	NodoLiteralCadena* nombre;

	std::list<NodoSentencia*>* listaArgumentos;

    NodoProcedimientoEncabezado(NodoLiteralCadena * nombre, std::list<NodoSentencia * >* listaArgumentos,NodoBasico * basico)
	{
		this->nombre = nombre;
		this->listaArgumentos = listaArgumentos;
        this->basico = basico;
        this->basico->nombreNodo = "NodoProcedimientoEncabezado";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        TablaSimbolos::obtenerInstancia()->infoF.tipoRetorno = new TipoVoid(this->basico);
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

    }
};
#endif
