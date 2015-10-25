#ifndef TABLASIMBOLOSINTERPRETADO
#define TABLASIMBOLOSINTERPRETADO
#include <map>
#include "valorinterpretado.h"
#include "datosfuncioninterpretado.h"
class TablaSimbolosInterpretado{
public:
    map<string, ValorInterpretado*> valores;
    map<string, DatosFuncionInterpretado*> datosFuncion;
    //map<string, DatosRegistro*> datosRegistro;
    //list<string> tiposDeDatos;
    TablaSimbolosInterpretado(){

    }

    ValorInterpretado* obternerValorVariableGlobal(string nombre ){
        string nombreVariableMayuscula = nombre;
        std::transform(nombreVariableMayuscula.begin(), nombreVariableMayuscula.end(), nombreVariableMayuscula.begin(), ::toupper);
        map<string, ValorInterpretado*>::iterator it = this->valores.find(nombreVariableMayuscula);

        if (it != valores.end())
        {
           return it->second;
        }
         throw  ExcepcionSemantica("Variable: "+nombre+" no existe");
    }

    void AsignarValorVariable(string nombre,ValorInterpretado* valor)
    {

        string nombreVariableMayuscula = nombre;
        std::transform(nombreVariableMayuscula.begin(), nombreVariableMayuscula.end(), nombreVariableMayuscula.begin(), ::toupper);

        valores[nombreVariableMayuscula] = valor;




   }

    void AsignarValorVariableFuncion(string nombreFuncion,string nombre,ValorInterpretado * valor){
        string nombreVariableMayuscula = nombre;
         string nombreFuncionMayuscula = nombreFuncion;
         std::transform(nombreFuncionMayuscula.begin(), nombreFuncionMayuscula.end(), nombreFuncionMayuscula.begin(), ::toupper);

        std::transform(nombreVariableMayuscula.begin(), nombreVariableMayuscula.end(), nombreVariableMayuscula.begin(), ::toupper);
        map<string, DatosFuncionInterpretado*>::iterator it = this->datosFuncion.find(nombreFuncionMayuscula);
        (it->second)->variables[nombreVariableMayuscula] = valor;
    }

    void AsignarValorParametroFuncion(string nombreFuncion,string nombre,ValorInterpretado * valor){
        string nombreVariableMayuscula = nombre;
         string nombreFuncionMayuscula = nombreFuncion;
         std::transform(nombreFuncionMayuscula.begin(), nombreFuncionMayuscula.end(), nombreFuncionMayuscula.begin(), ::toupper);

        std::transform(nombreVariableMayuscula.begin(), nombreVariableMayuscula.end(), nombreVariableMayuscula.begin(), ::toupper);
        map<string, DatosFuncionInterpretado*>::iterator it = this->datosFuncion.find(nombreFuncionMayuscula);
        (it->second)->listaParametros[nombreVariableMayuscula] = valor;
    }
};

#endif // TABLASIMBOLOSINTERPRETADO

