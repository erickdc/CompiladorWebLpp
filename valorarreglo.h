#ifndef VALORARREGLO
#define VALORARREGLO

#include "valorinterpretado.h"

class ValorArreglo:public ValorInterpretado{
public:

    ValorArreglo(){
        this->nombreTipo = "TipoArreglo";
    }

    // ValorInterpretado interface
public:
    string aCadena()
    {
        return "[]";
    }
};

#endif // VALORARREGLO

