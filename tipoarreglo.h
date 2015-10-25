#ifndef TIPOARREGLO
#define TIPOARREGLO
#include <list>
#include "tipov.h"
#include "valorarreglo.h"

class TipoArreglo : public TipoV{
public :
    TipoV *tipo;
    std::list<int> *dimensiones;
    TipoArreglo(TipoV *tipoDE , std::list<int> *dimensiones)
    {
        this->tipo = tipoDE;
        this->dimensiones = dimensiones;
        this->nombre = "TipoArreglo";


    }

    TipoArreglo (){

    }

    // TipoV interface
public:
    ValorInterpretado *valorInterpretadoDefault()
    {
        return new ValorArreglo();
    }
};

#endif // TIPOARREGLO

