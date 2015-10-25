#ifndef NODODECLARACION
#define NODODECLARACION
#include <string>
#include "NodoSentencia.h"
#include "NodoLiteralCadena.h"
#include "tablasimbolos.h"
#include "tipoarreglo.h"

#include <list>

class NodoDeclaracion : public NodoSentencia
{
public:
    TipoV * tipo;

    std::list<NodoLiteralCadena*>*listaNombres;
    NodoDeclaracion(TipoV * tipo , std::list<NodoLiteralCadena*>*lista,NodoBasico * basico)
	{
		this->tipo = tipo;
        this->listaNombres = lista;

        this->basico = basico;
        this->basico->nombreNodo = "NodoDeclaracion";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {



        for (list<NodoLiteralCadena*>::iterator it = listaNombres->begin();it!=listaNombres->end();++it){
              if(TablaSimbolos::obtenerInstancia()->status==0){
                  TablaSimbolos::obtenerInstancia()->declararVariable(((*it)->valor),tipo);
              }else if (TablaSimbolos::obtenerInstancia()->status==1){
                TablaSimbolos::obtenerInstancia()->declararVariableFuncion(TablaSimbolos::obtenerInstancia()->infoF.nombreFuncion,((*it)->valor),tipo);

              }else if(TablaSimbolos::obtenerInstancia()->status ==2)
              {
                  TablaSimbolos::obtenerInstancia()->declararVariableRegistro(TablaSimbolos::obtenerInstancia()->infoR.nombreRegistro,((*it)->valor),tipo);
              }
        }


    }

    // NodoSentencia interface
public:
    void interpretar()
    {
        for (list<NodoLiteralCadena*>::iterator it = listaNombres->begin();it!=listaNombres->end();++it){
        {
                if(TablaSimbolos::obtenerInstancia()->status==0){
                      TablaSimbolos::obtenerInstancia()->tablaValores.AsignarValorVariable(((*it)->valor),tipo->valorInterpretadoDefault());
                }else if (TablaSimbolos::obtenerInstancia()->status==1){
                     TablaSimbolos::obtenerInstancia()->tablaValores.AsignarValorVariableFuncion(TablaSimbolos::obtenerInstancia()->infoF.nombreFuncion,((*it)->valor),tipo->valorInterpretadoDefault());
                }else if (TablaSimbolos::obtenerInstancia()->status==2){

                }
        }
      }
    }
};
#endif
