#ifndef DATOSFUNCION
#define DATOSFUNCION
#include "tipov.h"
#include <map>
#include <string>
#include <list>
using namespace std;

class DatosFuncion{
public:
    map<string, TipoV*> variables;
    TipoV *tipoRetorno;
    list<TipoV*> listaParametros;
    DatosFuncion(TipoV *tipoRetorno){
        this->tipoRetorno = tipoRetorno;
    }
};

#endif // DATOSFUNCION

