#ifndef NODOLLAMARFUNCION
#define NODOLLAMARFUNCION
#include "NodoSentencia.h"
#include "NodoExpression.h"
#include "tablasimbolos.h"
#include <list>
#include "NodoLiteralCadena.h"


class NodoLlamarFuncion : public NodoSentencia
{
public:


	NodoLiteralCadena* nombreFuncion;

	std::list<NodoExpression*>* listaParametros;

    NodoLlamarFuncion(NodoLiteralCadena* nombreFuncion, std::list<NodoExpression*>* listaParametros,NodoBasico * basico)
	{

		this->nombreFuncion = nombreFuncion;
		this->listaParametros = listaParametros;
        this->basico = basico;
        this->basico->nombreNodo = "NodoLlamarFuncion";

	}

    // NodoSentencia interface
public:
    void validarSemantica()
    {
        TablaSimbolos::obtenerInstancia()->existeFuncion(nombreFuncion->valor);
        int contador =0;
        for (list<NodoExpression*>::iterator it = listaParametros->begin();it!=listaParametros->end();++it){
          TipoV *tipo= (*it)->validarSemantica();
          TablaSimbolos::obtenerInstancia()->esTipoParametroIgual(nombreFuncion->valor,tipo,contador);
          contador++;
        }
        TablaSimbolos::obtenerInstancia()->tieneLaCantidadParametros(nombreFuncion->valor,contador);
    }

    // NodoSentencia interface
public:
    void interpretar()
    {

    }
};
#endif
