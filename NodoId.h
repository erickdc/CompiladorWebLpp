#ifndef NODOID
#define NODOID
#include <string>
#include "NodoExpression.h"
#include "tablasimbolos.h"

class NodoId : public NodoExpression
{
public:
	std::string id;

    NodoId(std::string id,NodoBasico * basico)
	{
		this->id = id;
        this->nodoBasico = basico;
        this->nodoBasico->nombreNodo = "NodoId";

	}

    // NodoExpression interface
public:
    TipoV* validarSemantica()
    {
        if(TablaSimbolos::obtenerInstancia()->status==0){
             return TablaSimbolos::obtenerInstancia()->obtenerTipoVariable(id);
        }else if (TablaSimbolos::obtenerInstancia()->status==1){
            return TablaSimbolos::obtenerInstancia()->obtenerTipoVariableFuncion(TablaSimbolos::instancia->infoF.nombreFuncion,id);
        }else if(TablaSimbolos::obtenerInstancia()->status==2){
            return TablaSimbolos::obtenerInstancia()->obtenerTipoVariableRegistro(TablaSimbolos::instancia->infoR.nombreRegistro,id);
        }


    }

    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {
        return TablaSimbolos::obtenerInstancia()->tablaValores.obternerValorVariableGlobal(this->id);
    }
};
#endif
