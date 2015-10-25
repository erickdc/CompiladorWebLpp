#ifndef VALORCADENA
#define VALORCADENA

#include "valorinterpretado.h"

class ValorCadena: public ValorInterpretado{
public:

    int cantidad;
    string valor;
    ValorCadena(int cantidad, string valor){
        this->cantidad = cantidad;
        this->valor = valor;
         this->nombreTipo = "TipoCadena";


    }
    ValorCadena(string valor){
        this->valor = valor;
        this->nombreTipo = "TipoCadena";
    }

    // ValorInterpretado interface
public:
    string aCadena()
    {
        return valor;
    }

    // ValorInterpretado interface


};

#endif // VALORCADENA

