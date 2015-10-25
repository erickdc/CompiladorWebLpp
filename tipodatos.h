#ifndef TIPODATOS
#define TIPODATOS
#include "tipov.h"

#include <map>

class TipoDatos{
public:
    TipoV *tipo;
    TipoDatos(TipoV * tipo){
        this->tipo = tipo;
    }

    TipoDatos(){

    }
};

#endif // TIPODATOS

