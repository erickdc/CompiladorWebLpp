#ifndef TIPOCARACTER
#define TIPOCARACTER

#include "tipov.h"
#include "valorcaracter.h"

class TipoCaracter : public TipoV{
   public:
    TipoCaracter(NodoBasico * basico):TipoV(basico){
        this->nombre = "TipoCaracter";
         this->nodoBasico->nombreNodo = "TipoCaracter";
    }

    TipoCaracter(){

    }

    // TipoV interface
public:
    ValorInterpretado *valorInterpretadoDefault()
    {
        return new ValorCaracter(' ');
    }
};

#endif // TIPOCARACTER

