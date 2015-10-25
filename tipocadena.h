#ifndef TIPOCADENA
#define TIPOCADENA

#include "tipov.h"
#include "valorcadena.h"

class TipoCadena : public TipoV{
public :
    int cantidadLetras;
    TipoCadena(int cantidad,NodoBasico *nodoBasico):TipoV(nodoBasico){
        this->cantidadLetras = cantidad;
        this->nombre ="TipoCadena";
        this->nodoBasico->nombreNodo ="TipoCadena";
    }
    TipoCadena(NodoBasico*nodoBasico):TipoV(nodoBasico){
        this->nombre ="TipoCadena";
        this->nodoBasico->nombreNodo ="TipoCadena";
    }
    TipoCadena(){
        this->nombre ="TipoCadena";
        this->nodoBasico->nombreNodo ="TipoCadena";
    }

    // TipoV interface
public:
    ValorInterpretado *valorInterpretadoDefault()
    {
        return new ValorCadena(" ");
    }
};

#endif // TIPOCADENA

