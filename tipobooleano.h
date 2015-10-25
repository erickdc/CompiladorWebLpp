#ifndef TIPOBOOLEANO
#define TIPOBOOLEANO

#include "tipov.h"
#include "valorbooleano.h"

class TipoBooleano: public TipoV{
public:

    TipoBooleano(NodoBasico * nodoBasico):TipoV(nodoBasico){
        this->nombre = "TipoBooleano";
         this->nodoBasico->nombreNodo = "TipoBooleano";
    }
    TipoBooleano(){

    }

    // TipoV interface
public:
    ValorInterpretado *valorInterpretadoDefault()
    {
        return new ValorBooleano(false);
    }
};

#endif // TIPOBOOLEANO

