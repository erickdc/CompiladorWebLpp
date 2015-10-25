#ifndef TIPOENTERO
#define TIPOENTERO

#include "tipov.h"
#include "valorentero.h"

class TipoEntero: public TipoV{
public:
    TipoEntero(NodoBasico *nodoBasico):TipoV(nodoBasico){
        this->nombre = "TipoEntero";
        this->nodoBasico->nombreNodo = "TipoEntero";
    }
    TipoEntero(){

    }

    // TipoV interface
public:
    ValorInterpretado *valorInterpretadoDefault()
    {
        return new ValorEntero(0);
    }
};

#endif // TIPOENTERO

