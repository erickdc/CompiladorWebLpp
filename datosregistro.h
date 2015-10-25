#ifndef DATOSREGISTRO
#define DATOSREGISTRO
#include "tipodatos.h"
#include "tipov.h"

#include <map>
class DatosRegistro :public TipoDatos{
public:
    map<string, TipoV*> variables;
    DatosRegistros(){

    }
};

#endif // DATOSREGISTRO

