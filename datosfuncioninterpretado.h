#ifndef DATOSFUNCIONINTERPRETADO
#define DATOSFUNCIONINTERPRETADO
#include <map>
#include "valorinterpretado.h"

class DatosFuncionInterpretado{
public:
    map<string, ValorInterpretado*> variables;
    ValorInterpretado *tipoRetorno;
     map<string, ValorInterpretado*> listaParametros;
    DatosFuncionInterpretado(){
    }
};

#endif // DATOSFUNCIONINTERPRETADO

