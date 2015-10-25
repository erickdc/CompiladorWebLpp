/* 
 * File:   Sintactico.h
 * Author: erick304
 *
 * Created on August 11, 2015, 9:32 AM
 */

#ifndef SINTACTICO_H
#define	SINTACTICO_H
#include "ExcepcionSintactica.h"
#include "Lexico.h"
#include "Token.h"
#include "NodoY.h"
#include "NodoO.h"
#include "NodoMenor.h"
#include "NodoMayor.h"
#include "NodoMenorIgual.h"
#include "NodoMayorIgual.h"
#include "NodoIgual.h"
#include "NodoDiferente.h"
#include "NodoSuma.h"
#include "NodoResta.h"
#include "NodoMultiplicacion.h"
#include "NodoDivision.h"
#include "NodoModular.h"
#include "NodoDivisionEntera.h"
#include "NodoExponente.h"
#include "NodoOperadorNo.h"
#include <list>
#include "NodoSentencia.h"
#include "NodoLiteralEntero.h"
#include "NodoLiteralCadena.h"
#include "NodoCaso.h"
#include "NodoSinoCaso.h"
class NodoExpression;

class Sintactico
{
public:
	Sintactico(Lexico* lexico);

	Lexico* lexico;
	Token tokenActual;
	list<NodoSentencia*>* Parse();
	list<NodoSentencia*>* Programa();
	list<NodoSentencia*>* ProgramaLpp();
	list<NodoSentencia*>* DefinicionTipos();
	list<NodoSentencia*>* Declaraciones();
	NodoSentencia* DeclaracionSubProgramas();
	list<NodoSentencia*>*  ConjuntoProposiciones();

	NodoSentencia* DefinicionTipo();
    TipoV *TipoVariable();
	NodoSentencia* LineaDeclaraciones();
	list<NodoLiteralCadena*>* ListaIdentificadores();
    TipoV *TipoPrimitivo();
	NodoSentencia* ListaEnteros();
	list<NodoLiteralEntero*> * ListaEnterosPrima();
	NodoSentencia* DeclaracionSub();
	NodoSentencia* EncabezadoSub();
	list<NodoSentencia*>* ListaProp();
	list<NodoSentencia*>*  Argumentos();
	list<NodoSentencia*>* Parametros();
	NodoSentencia* DeclaracionParametro();
	list<NodoSentencia*>* ParametrosPrima();
	NodoSentencia* Proposicion();
	NodoSentencia* ProposicionMientras();
	NodoSentencia* ProposicionSi();
	NodoSentencia* PropisicionLlamar();
	NodoSentencia* PropisicionAsignar();
	NodoSentencia* ProposicionPara();
	NodoSentencia* PropisicionRepita();
	NodoSentencia* PropisicionEscriba();
	NodoSentencia* ProposicionCaso();
	NodoSentencia* ProposicionEscribir();
	NodoSentencia* ProposicionLeer();
	NodoSentencia* PropisicionAbrir();
	NodoSentencia* PropisicionCerrar();
	NodoExpression* Expresion();
	NodoSentencia* ProposicionSiPrima();
	list<NodoExpression*>* Param();
	list<NodoExpression*>* ListaExpresiones();
	list<NodoExpression*>* ListaExpresionesPrima();
	NodoExpression* Variable();
    list<NodoCaso *> *ListaCasos();
    NodoSinoCaso *SinoCaso();
    NodoCaso *LineaCaso();
	list<NodoExpression*>* ListaLiterales();
	NodoExpression* Literal();
	list<NodoExpression*>* ListaLiteralPrima();
	list<NodoSentencia*>* ListaOperaciones();
	NodoSentencia*  Operacion();
	NodoSentencia* OperacionPrima();
	list<NodoExpression*>* ListaVariable();
	list<NodoExpression*>* ListaVariablePrima();
	NodoExpression* VariableSimple();
	NodoExpression* VariableSimplePrima(NodoExpression* param);
	void consumirToken();
	NodoExpression* ExpBool();
	NodoExpression* ExpPrima(NodoExpression* param);
	NodoExpression* ExpBasico();
	NodoExpression* ExpBoolPrima(NodoExpression* param);
	NodoExpression* Factor();
	NodoExpression* ExpOper();
	NodoExpression* FactorPrima(NodoExpression* param);
	NodoExpression* ExpBasicoPrima(NodoExpression* param);
	NodoExpression* NoLogico();
	NodoExpression* ExpOperPrima(NodoExpression* param);
	NodoExpression* Term();
	NodoSentencia* ProposicionRetorne();
	NodoExpression* VariablePrima(NodoExpression* param);
	NodoExpression* VariablePrima2(NodoExpression *param);
    NodoExpression* ValoresNegativo(NodoBasico *nodo);
	list<NodoExpression*>*  ProposicionEscribaPrima();
	list<NodoExpression*>* ListaExpresionesV();
    TipoV *ArchivoPrima();
	virtual ~Sintactico();

private:
};

#endif /* SINTACTICO_H */
