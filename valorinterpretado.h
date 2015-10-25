#ifndef VALORINTERPRETADO
#define VALORINTERPRETADO
#include <string>

using namespace std;
class ValorInterpretado{
public:
    string nombreTipo;
    ValorInterpretado(){

    }
   virtual string aCadena()=0;
};

#endif // VALORINTERPRETADO

