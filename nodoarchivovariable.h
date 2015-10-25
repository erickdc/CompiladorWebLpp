#ifndef NODOARCHIVOVARIABLE
#define NODOARCHIVOVARIABLE

#include "NodoSentencia.h"
#include "tipov.h"


class NodoArchivoVariable:public TipoV{
public:
    TipoV * tipoVariable;
    NodoArchivoVariable(TipoV* tipoVariable , NodoBasico * basico):TipoV(basico){
        this->tipoVariable = tipoVariable;
        this->nombre = "TipoArchivoVariable";
        this->nodoBasico->nombreNodo = "TipoArchivoVariable";

    }



    // TipoV interface
public:
    ValorInterpretado *valorInterpretadoDefault()
    {

    }
};

#endif // NODOARCHIVOVARIABLE

