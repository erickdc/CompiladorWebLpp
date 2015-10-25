#ifndef INFOREGISTRO
#define INFOREGISTRO
#include <string>
using namespace std;
class InfoRegistro{
public:
    string nombreRegistro;
    InfoRegistro(){

    }

    InfoRegistro(string nombreRegistro){
        this->nombreRegistro = nombreRegistro;
    }
};

#endif // INFOREGISTRO

