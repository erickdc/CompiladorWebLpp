#ifndef NODOPROPASIGNAR
#define NODOPROPASIGNAR
#include "NodoSentencia.h"
#include "NodoExpression.h"
#include "excepcionsemantica.h"
#include "NodoId.h"


class NodoPropAsignar : public NodoSentencia
{
public:


	NodoExpression* valorAsignar;

    NodoExpression* variable;

    NodoPropAsignar(NodoExpression *exp, NodoExpression* valorAsignar,NodoBasico *nodo)
	{

        this->variable = exp;
		this->valorAsignar = valorAsignar;
        this->basico = nodo;
        this->basico->nombreNodo = "NodoPropAsignar";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        TipoV* variableS=variable->validarSemantica();
        TipoV *tipoValor = valorAsignar->validarSemantica();
        if (variableS->nombre!=tipoValor->nombre)
        {
              throw ExcepcionSemantica("Tipo asignado es incompatibles entre si.");
        }
    }

    // NodoSentencia interface
public:
    void interpretar()
    {
         NodoId* nodoId = (dynamic_cast<NodoId*>(variable));
         if(TablaSimbolos::obtenerInstancia()->status==0)
         {
             TablaSimbolos::obtenerInstancia()->tablaValores.AsignarValorVariable(nodoId->id,valorAsignar->evaluar());
        } else if(TablaSimbolos::obtenerInstancia()->status ==1){
             TablaSimbolos::obtenerInstancia()->tablaValores.AsignarValorVariableFuncion(TablaSimbolos::obtenerInstancia()->infoF.nombreFuncion,nodoId->id,valorAsignar->evaluar());
         }
    }
};
#endif
