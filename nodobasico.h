#ifndef NODOBASICO
#define NODOBASICO
#include "Token.h"

#include <string>
using namespace std;
class NodoBasico{
public:
    int fila;
    int columna;
    string nombreNodo;
    NodoBasico(Token token){
        this->fila = token.Fila;
        this->columna = token.Columna;


    }
};

#endif // NODOBASICO

