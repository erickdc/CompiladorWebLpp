#ifndef VALORBOOLEANO
#define VALORBOOLEANO

#include "valorinterpretado.h"

class ValorBooleano: public ValorInterpretado{
  public:
    bool tipo;
    ValorBooleano(bool tipo)
    {
        this->tipo = tipo;
         this->nombreTipo = "TipoBooleano";
    }

    // ValorInterpretado interface
public:
    string aCadena()
    {
        return tipo?"VERDADERO":"FALSE";
    }
};

#endif // VALORBOOLEANO

