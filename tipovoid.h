#ifndef TIPOVOID
#define TIPOVOID

#include "tipov.h"
#include "valorcadena.h"

class TipoVoid:public TipoV{
public:
    TipoVoid(NodoBasico * basico):TipoV(basico){

        this->nodoBasico->nombreNodo="TipoVoid";
    }

    // TipoV interface
public:
    ValorInterpretado *valorInterpretadoDefault()
    {
        return new ValorCadena(" ");
    }
};

#endif // TIPOVOID

