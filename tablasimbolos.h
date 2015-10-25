#ifndef TABLASIMBOLOS
#define TABLASIMBOLOS
#include "datosfuncion.h"
#include "datosregistro.h"
#include "excepcionsemantica.h"
#include "infofuncion.h"
#include "inforegistro.h"
#include "tablasimbolosinterpretado.h"
#include "tipoarreglo.h"
#include "tipobooleano.h"
#include "tipocadena.h"
#include "tipocaracter.h"
#include "tipodatos.h"
#include "tipoentero.h"
#include "tiporeal.h"
#include "tipov.h"

#include <map>
#include <string>
using namespace std;
class TablaSimbolos{
public :
    map<string, TipoV*> variables;
    map<string, DatosFuncion*> datosFuncion;
    map<string, DatosRegistro*> datosRegistro;
    list<string> tiposDeDatos;
    TablaSimbolosInterpretado tablaValores;
    int status =0;
    InfoFuncion infoF;
    InfoRegistro infoR;
    static TablaSimbolos *instancia;
    TablaSimbolos(){
         this->tiposDeDatos.push_back("TIPOENTERO");
         this->tiposDeDatos.push_back("TIPOCADENA");
         this->tiposDeDatos.push_back("TIPOCARACTER");
        this->tiposDeDatos.push_back("TIPOBOOLEANO");
        this->tiposDeDatos.push_back("TIPOREAL");
        this->tiposDeDatos.push_back("TIPOARREGLO");
        this->tiposDeDatos.push_back("TIPOARCHIVO");

        this->tiposDeDatos.push_back("TIPOARCHIVOSECUENCIAL");
        this->tiposDeDatos.push_back("TIPOARCHIVOVARIABLE");
    }

    static TablaSimbolos  * obtenerInstancia(){
        if(instancia ==NULL )
        {
            instancia = new TablaSimbolos();

        }
          return instancia;
    }
    void existeFuncion(string nombreFuncion){
        string nombreFuncionMayuscula = nombreFuncion;
         std::transform(nombreFuncionMayuscula.begin(), nombreFuncionMayuscula.end(), nombreFuncionMayuscula.begin(), ::toupper);
        map<string, DatosFuncion*>::iterator it = this->datosFuncion.find(nombreFuncionMayuscula);

        if (it == datosFuncion.end())
        {
           throw ExcepcionSemantica("Funcion " + nombreFuncion + " no existe");
        }
    }

    void declararFuncion(string nombreFuncion , TipoV * tipoRetorno){
        string nombreFuncionMayuscula = nombreFuncion;
         std::transform(nombreFuncionMayuscula.begin(), nombreFuncionMayuscula.end(), nombreFuncionMayuscula.begin(), ::toupper);
        map<string, DatosFuncion*>::iterator it = this->datosFuncion.find(nombreFuncionMayuscula);

        if (it != datosFuncion.end())
        {
           throw ExcepcionSemantica("Funcion " + nombreFuncion + " ya existe");
        }
        datosFuncion[nombreFuncionMayuscula] = new DatosFuncion(tipoRetorno);
    }

    void declararRegistro(string nombreRegistro){
        string nombreRegistroMayuscula = nombreRegistro;
            std::transform(nombreRegistroMayuscula.begin(), nombreRegistroMayuscula.end(), nombreRegistroMayuscula.begin(), ::toupper);
        map<string, DatosRegistro*>::iterator it = this->datosRegistro.find(nombreRegistroMayuscula);

        if (it != datosRegistro.end())
        {
           throw ExcepcionSemantica("Registro " + nombreRegistro + " ya existe");
        }
        datosRegistro[nombreRegistroMayuscula] = new DatosRegistro();
       TablaSimbolos::obtenerInstancia()->infoR.nombreRegistro= nombreRegistroMayuscula;
         tiposDeDatos.push_back(nombreRegistroMayuscula);

    }

    void definirTipos(string nombreTipo ,TipoV * tipo){
        string nombreTipoMayuscula = nombreTipo;
          std::transform(nombreTipoMayuscula.begin(), nombreTipoMayuscula.end(), nombreTipoMayuscula.begin(), ::toupper);
         std::list<string>::iterator it = std::find(tiposDeDatos.begin(), tiposDeDatos.end(), nombreTipoMayuscula);

        if (it != tiposDeDatos.end())
        {
           throw ExcepcionSemantica("Tipo de Dato " + nombreTipo + " ya existe");
        }
        tiposDeDatos.push_back(nombreTipoMayuscula);

    }

   int existeTipo(string nombreTipo){
       string mayusculaNombre = nombreTipo;
        std::transform(mayusculaNombre.begin(), mayusculaNombre.end(), mayusculaNombre.begin(), ::toupper);
        std::list<string>::iterator it = std::find(tiposDeDatos.begin(), tiposDeDatos.end(), mayusculaNombre);


       if (it != tiposDeDatos.end())
       {
          return 1;
       }
        throw  ExcepcionSemantica("Tipo: "+nombreTipo+" no existe");
   }

    TipoV* obtenerTipoVariable(string nombre)
    {
        string nombreVariableMayuscula = nombre;
        std::transform(nombreVariableMayuscula.begin(), nombreVariableMayuscula.end(), nombreVariableMayuscula.begin(), ::toupper);
        map<string, TipoV*>::iterator it = this->variables.find(nombreVariableMayuscula);

        if (it != variables.end())
        {
           return it->second;
        }
         throw  ExcepcionSemantica("Variable: "+nombre+" no existe");

    }
    TipoV* obtenerTipoVariableFuncion(string nombreFuncion,string nombreVariable )
    {
        string nombreFuncionMayuscula = nombreFuncion;
        string nombreVariableMayuscula = nombreVariable;

        std::transform(nombreFuncionMayuscula.begin(), nombreFuncionMayuscula.end(), nombreFuncionMayuscula.begin(), ::toupper);
        std::transform(nombreVariableMayuscula.begin(), nombreVariableMayuscula.end(), nombreVariableMayuscula.begin(), ::toupper);

        map<string, TipoV*>::iterator it3 = variables.find(nombreVariableMayuscula);

        if (it3 !=variables.end())
        {
           return it3->second;
        }
        map<string, DatosFuncion*>::iterator it = this->datosFuncion.find(nombreFuncionMayuscula);
        DatosFuncion* registroDatosFuncion;
        if (it != datosFuncion.end())
        {
           registroDatosFuncion= it->second;
        }else{
            throw  ExcepcionSemantica("Funcion "+nombreFuncion+" no existe");
        }


        map<string, TipoV*>::iterator it2 = registroDatosFuncion->variables.find(nombreVariableMayuscula);

        if (it2 != registroDatosFuncion->variables.end())
        {
           return it2->second;
        }
         throw  ExcepcionSemantica("Variable "+nombreVariable+" no existe");

    }


     void declararVariable(string nombre,TipoV* valor)
     {

         string nombreVariableMayuscula = nombre;
          std::transform(nombreVariableMayuscula.begin(), nombreVariableMayuscula.end(), nombreVariableMayuscula.begin(), ::toupper);
         map<string, TipoV*>::iterator it = this->variables.find(nombreVariableMayuscula);

         if (it != variables.end())
         {
            throw ExcepcionSemantica("Variable " + nombre + " ya existe");
         }
          existeTipo(valor->nodoBasico->nombreNodo);
         variables[nombreVariableMayuscula] = valor;

    }



     void declararVariableRegistro(string nombreRegistro,string nombreVariable,TipoV* valor)
     {
         string nombreVariableMayuscula = nombreVariable;
         string nombreRegistroMayuscula =nombreRegistro;

         std::transform(nombreVariableMayuscula.begin(), nombreVariableMayuscula.end(), nombreVariableMayuscula.begin(), ::toupper);
         std::transform(nombreRegistroMayuscula.begin(), nombreRegistroMayuscula.end(), nombreRegistroMayuscula.begin(), ::toupper);

         map<string, DatosRegistro*>::iterator it = this->datosRegistro.find(nombreRegistroMayuscula);
         DatosRegistro * datosRegistro;
         if (it != this->datosRegistro.end())
         {
            datosRegistro = it->second;
         }else{
             throw ExcepcionSemantica("No existe el registro con el nombre : "+ nombreRegistro);
         }

         map<string, TipoV*>::iterator it2 = datosRegistro->variables.find(nombreVariableMayuscula);

         if (it2 != datosRegistro->variables.end())
         {
            throw ExcepcionSemantica("Variable " + nombreVariable + " ya existe");
         }
         existeTipo(valor->nodoBasico->nombreNodo);
         datosRegistro->variables[nombreVariableMayuscula] = valor;

    }

     TipoV* obtenerTipoVariableRegistro(string nombreRegistro,string nombreVariable )
     {
         string nombreRegistroMayuscula = nombreRegistro;
         string nombreVariableMayuscula = nombreVariable;

         std::transform(nombreVariableMayuscula.begin(), nombreVariableMayuscula.end(), nombreVariableMayuscula.begin(), ::toupper);
         std::transform(nombreRegistroMayuscula.begin(), nombreRegistroMayuscula.end(), nombreRegistroMayuscula.begin(), ::toupper);


         map<string, DatosRegistro*>::iterator it = this->datosRegistro.find(nombreRegistroMayuscula);
         DatosRegistro* registroDatos;
         if (it != datosRegistro.end())
         {
            registroDatos= it->second;
         }else{
             throw  ExcepcionSemantica("Registro "+nombreRegistro+" no existe");
         }


         map<string, TipoV*>::iterator it2 = registroDatos->variables.find(nombreVariableMayuscula);

         if (it2 != registroDatos->variables.end())
         {
            return it2->second;
         }
          throw  ExcepcionSemantica("Variable "+nombreVariable+" no existe");

     }

     void declararVariableFuncion(string nombreFuncion ,string nombreVariable,TipoV* valor)
     {
         string nombreFuncionMayuscula = nombreFuncion;
         string nombreVariableMayuscula = nombreVariable;

         std::transform(nombreVariableMayuscula.begin(), nombreVariableMayuscula.end(), nombreVariableMayuscula.begin(), ::toupper);
         std::transform(nombreFuncionMayuscula.begin(), nombreFuncionMayuscula.end(), nombreFuncionMayuscula.begin(), ::toupper);



         map<string, TipoV*>::iterator it = this->variables.find(nombreVariableMayuscula);

         if (it != variables.end())
         {
            throw ExcepcionSemantica("Variable " + nombreVariable + " ya existe");
         }

         map<string, DatosFuncion*>::iterator it2 = this->datosFuncion.find(nombreFuncionMayuscula);
         DatosFuncion* registroDatosFuncion;
         if (it2 != datosFuncion.end())
         {
            registroDatosFuncion= it2->second;
         }else{
             throw  ExcepcionSemantica("Funcion "+nombreFuncion+" no existe");
         }

         map<string, TipoV*>::iterator it3= registroDatosFuncion->variables.find(nombreVariableMayuscula);

         if (it3 != registroDatosFuncion->variables.end())
         {
            throw ExcepcionSemantica("Variable " + nombreVariable + " ya existe en esta funcion");
         }
         existeTipo(valor->nodoBasico->nombreNodo);
         registroDatosFuncion->variables[nombreVariableMayuscula] = valor;

    }

     void declararParametroFuncion(string nombreFuncion ,string nombreVariable,TipoV* valor)
     {
         string nombreFuncionMayuscula = nombreFuncion;
         string nombreVariableMayuscula = nombreVariable;

         std::transform(nombreVariableMayuscula.begin(), nombreVariableMayuscula.end(), nombreVariableMayuscula.begin(), ::toupper);
         std::transform(nombreFuncionMayuscula.begin(), nombreFuncionMayuscula.end(), nombreFuncionMayuscula.begin(), ::toupper);





         map<string, DatosFuncion*>::iterator it2 = this->datosFuncion.find(nombreFuncionMayuscula);
         DatosFuncion* registroDatosFuncion;
         if (it2 != datosFuncion.end())
         {
            registroDatosFuncion= it2->second;
         }else{
             throw  ExcepcionSemantica("Funcion "+nombreFuncion+" no existe");
         }


         registroDatosFuncion->listaParametros.push_back(valor);

    }

    void esTipoParametroIgual(string nombreFuncion,TipoV * tipoVariable, int posicion){
        string nombreFuncionMayuscula = nombreFuncion;
        string nombreTipoVariableMayuscula = tipoVariable->nodoBasico->nombreNodo;
        std::transform(nombreFuncionMayuscula.begin(), nombreFuncionMayuscula.end(), nombreFuncionMayuscula.begin(), ::toupper);
        std::transform(nombreTipoVariableMayuscula.begin(), nombreTipoVariableMayuscula.end(), nombreTipoVariableMayuscula.begin(), ::toupper);

        map<string, DatosFuncion*>::iterator it = this->datosFuncion.find(nombreFuncionMayuscula);
        DatosFuncion* registroDatosFuncion;
        if (it != datosFuncion.end())
        {
           registroDatosFuncion= it->second;
        }else{
            throw  ExcepcionSemantica("Funcion "+nombreFuncion+" no existe");
        }


        if(registroDatosFuncion->listaParametros.size()<=posicion){
            throw ExcepcionSemantica("Se mando mas parametros de los establecidos");
        }
        std::list<TipoV*>::iterator it4 = registroDatosFuncion->listaParametros.begin();
         std::advance(it4, posicion);
         string nombreTipo = (*it4)->nodoBasico->nombreNodo;
         std::transform(nombreTipo.begin(), nombreTipo.end(), nombreTipo.begin(), ::toupper);

        if(nombreTipo != nombreTipoVariableMayuscula)
        {
            throw ExcepcionSemantica("Tipo no coincide con el parametro enviado");
        }
    }

    void tieneLaCantidadParametros(string nombreFuncion,int cantidad){
        string nombreFuncionMayuscula = nombreFuncion;

        std::transform(nombreFuncionMayuscula.begin(), nombreFuncionMayuscula.end(), nombreFuncionMayuscula.begin(), ::toupper);


        map<string, DatosFuncion*>::iterator it = this->datosFuncion.find(nombreFuncionMayuscula);
        DatosFuncion* registroDatosFuncion;
        if (it != datosFuncion.end())
        {
           registroDatosFuncion= it->second;
        }else{
            throw  ExcepcionSemantica("Funcion "+nombreFuncion+" no existe");
        }


        if(registroDatosFuncion->listaParametros.size()!=cantidad){
            throw ExcepcionSemantica("Se esperaba parametros en la funcion");
        }

    }


};

#endif // TABLASIMBOLOS

