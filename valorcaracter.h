#ifndef VALORCARACTER
#define VALORCARACTER

#include "valorinterpretado.h"

class ValorCaracter : public ValorInterpretado{
public:
    char valor;
    ValorCaracter(char valor){
        this->valor = valor;
    }

    // ValorInterpretado interface
public:
    string aCadena()
    {
        return string(valor,1);
    }
};

#endif // VALORCARACTER

