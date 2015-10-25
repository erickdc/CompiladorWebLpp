#ifndef TIPOREAL
#define TIPOREAL

#include "tipov.h"
#include "valorflotante.h"

class TipoReal : public TipoV{
public:
    TipoReal(NodoBasico * basico ):TipoV(basico){
        this->nombre = "TipoReal";
        this->nodoBasico->nombreNodo = "TipoReal";
    }
    TipoReal(){

    }

    // TipoV interface
public:
    ValorInterpretado *valorInterpretadoDefault()
    {
        return new ValorFlotante(0);
    }
};

#endif // TIPOREAL

