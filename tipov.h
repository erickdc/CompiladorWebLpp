#ifndef TIPOV
#define TIPOV
#include "nodobasico.h"
#include "valorinterpretado.h"

#include <string>
using namespace std;
class TipoV{
public:
    string nombre;
    NodoBasico *nodoBasico;
    TipoV(NodoBasico * nodoBasico){
        this->nodoBasico = nodoBasico;
    }
    TipoV(){

    }
    virtual void nada() {}
    virtual ValorInterpretado* valorInterpretadoDefault()=0;
};

#endif // TIPO

