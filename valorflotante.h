#ifndef VALORFLOTANTE
#define VALORFLOTANTE
#include <iostream>
#include <sstream>
#include "valorinterpretado.h"

class ValorFlotante: public ValorInterpretado{
public:
    float valor;
    ValorFlotante(float valor){
        this->valor = valor;
         this->nombreTipo = "TipoReal";
    }

    // ValorInterpretado interface
public:
    string aCadena()
    {
        std::ostringstream ss;
        ss << valor;

        return std::string (ss.str());
    }
};

#endif // VALORFLOTANTE

