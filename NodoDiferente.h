#ifndef NODODIFERENTE
#define NODODIFERENTE
#include "NodoExpression.h"
#include "NodoOperacionBinaria.h"
#include "tipobooleano.h"

class NodoDiferente : public NodoOperacionBinaria
{
public:
    NodoDiferente(NodoExpression* izquierdo, NodoExpression* derecho,NodoBasico * basico) :NodoOperacionBinaria(izquierdo, derecho,basico)
	{
        this->nodoBasico->nombreNodo = "NodoDiferente";
        this->reglas["TipoBooleanoxTipoBooleano"] = new TipoBooleano(basico);
        this->reglas["TipoEnteroxTipoEntero"] = new TipoBooleano(basico);
        this->reglas["TipoCadenaxTipoCadena"] = new TipoBooleano(basico);
        this->reglas["TipoRealxTipoReal"] = new TipoBooleano(basico);
        this->reglas["TipoCaracterxTipoCaracter"] = new TipoBooleano(basico);
	}


};
#endif
