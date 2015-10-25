#ifndef NODOOPERACIONBINARIA
#define NODOOPERACIONBINARIA
#include "NodoExpression.h"
#include "excepcionsemantica.h"
#include <map>
class NodoOperacionBinaria: public NodoExpression
{
public:
	NodoExpression* izquierdo;
	NodoExpression* derecho;
    map<std::string, TipoV*> reglas;

    NodoOperacionBinaria(NodoExpression* izquierdo, NodoExpression* derecho,NodoBasico * basico)
	{
		this->izquierdo = izquierdo;
		this->derecho = derecho;
        this->nodoBasico = basico;
	}


private:

    // NodoExpression interface
public:
    TipoV* validarSemantica()
    {
        TipoV* tipoDerecho = derecho->validarSemantica();
        TipoV* tipoIzquierdo = izquierdo->validarSemantica();
        string pair = tipoIzquierdo->nombre+"x" + tipoDerecho->nombre;
          map<std::string, TipoV*>::iterator it = this->reglas.find(pair);

          if (it != this->reglas.end())
          {
             return it->second;
          }
        else
        {
          throw ExcepcionSemantica("Tipo es incompatible con pair ");
        }
    }




    // NodoExpression interface
public:
    ValorInterpretado *evaluar()
    {

    }
};
#endif
