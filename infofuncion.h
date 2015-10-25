#ifndef INFOFUNCION
#define INFOFUNCION
#include "tipov.h"

#include <string>
using namespace std;
class InfoFuncion{
public:
    string nombreFuncion;
    TipoV * tipoRetorno;
    InfoFuncion(){
        this->nombreFuncion = " ";
        this->tipoRetorno = NULL;
    }

    InfoFuncion(string nombreFuncion,TipoV *tipoRetorno){
        this->nombreFuncion = nombreFuncion;
        this->tipoRetorno = tipoRetorno;
    }
};

#endif // INFOFUNCION

