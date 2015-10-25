#ifndef VALORENTERO
#define VALORENTERO
#include <sstream>
#include "valorinterpretado.h"

class ValorEntero:public ValorInterpretado{
public:
    int valor;
    ValorEntero(int valor){
        this->valor = valor;
        this->nombreTipo = "TipoEntero";
    }

    // ValorInterpretado interface
public:
    string aCadena()
    {
        stringstream ss;
        ss << valor;
        string str = ss.str();
        return str;
    }
};

#endif // VALORENTERO

