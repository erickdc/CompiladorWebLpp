/* 
 * File:   Sintactico.cpp
 * Author: erick304
 * 
 * Created on August 11, 2015, 9:32 AM
 */

#include "Sintactico.h"
#include <list>
#include "NodoId.h"
#include "NodoVariableRegistro.h"
#include "NodoVariableArreglo.h"
#include "NodoLiteralCaracter.h"
#include "NodoLiteralCadena.h"
#include "NodoLiteralReal.h"
#include "NodoLiteralEntero.h"
#include "NodoVerdadero.h"
#include "NodoFalso.h"
#include "NodoValorNegativo.h"
#include "NodoFuncion.h"
#include "NodoHtml.h"
#include "NodoDeclaracion.h"
#include "NodoRetorne.h"
#include "NodoTipo.h"
#include "NodoRegistro.h"
#include "NodoTipoVariableArreglo.h"
#include "NodoTipoArchivo.h"
#include "NodoTipoObjecto.h"
#include "NodoListaLiteralEnteros.h"
#include "NodoTipoPrimitivoEntero.h"
#include "NodoTipoPrimitivoReal.h"
#include "NodoTipoPrimitivoCaracter.h"
#include "NodoTipoPrimitivoBooleano.h"
#include "NodoPropAsignar.h"
#include "NodoPropEscribir.h"
#include "NodoPropMientras.h"
#include "NodoPropSi.h"
#include "NodoLlamarFuncion.h"
#include "NodoSino.h"
#include "NodoPropEscriba.h"
#include "NodoPropLeer.h"
#include "NodoPropRepita.h"
#include "NodoOperacionLectura.h"
#include "NodoOperactionEscritura.h"
#include "NodoParametroVar.h"
#include "NodoParametro.h"
#include "NodoFuncionEncabezado.h"
#include "NodoProcedimientoEncabezado.h"
#include "NodoPropCerrar.h"
#include "NodoDeclaracionSubPrograma.h"
#include "NodoCaso.h"
#include "NodoSinoCaso.h"
#include "NodoProposicionCaso.h"
#include "NodoPropAbrir.h"
#include "NodoTipoCadena.h"
#include "NodoArchivoSecuencial.h"
#include "nodoarchivovariable.h"
#include "NodoPropPara.h"
#include <iostream>
#include <string>


Sintactico::Sintactico(Lexico* lexico)
{
	this->lexico = lexico;
	consumirToken();
}


Sintactico::~Sintactico()
{
}

void Sintactico::consumirToken()
{
	this->tokenActual = this->lexico->ObtenerToken();
}

list<NodoSentencia*>* Sintactico::Parse()
{
	list <NodoSentencia * > * lista =Programa();
	if (this->tokenActual.Tipo != EOFLPP)
	{
		throw ExcepcionSintactica("Se esperaba eof " + string(" y se encontro : ") + tokenActual.ToString());
	}
	return lista;
}

list<NodoSentencia*>* Sintactico::Programa()
{
	if (this->tokenActual.Tipo == HTML)
	{
		string lex = tokenActual.Lexema;
        Token tokenA =tokenActual;
		consumirToken();
		list<NodoSentencia * > *lista= Programa();
        lista->insert(lista->begin(), new NodoHtml(lex, new NodoBasico(tokenA)));
		return lista;
	}
	else if (this->tokenActual.Tipo == TIPO || this->tokenActual.Tipo == REGISTRO || this->tokenActual.Tipo == DECLARAR || this->tokenActual.Tipo == FUNCION || this->tokenActual.Tipo == PROCEDIMIENTO || this->tokenActual.Tipo == MIENTRAS || this->tokenActual.Tipo == SI || this->tokenActual.Tipo == LLAMAR || this->tokenActual.Tipo == IDLPP || this->tokenActual.Tipo == PARA || this->tokenActual.Tipo == REPITA || this->tokenActual.Tipo == ESCRIBA || this->tokenActual.Tipo == CASO || this->tokenActual.Tipo == ESCRIBIR || this->tokenActual.Tipo == LEER || this->tokenActual.Tipo == ABRIR || this->tokenActual.Tipo == CERRAR || this->tokenActual.Tipo == RETORNE)
	{
		list<NodoSentencia * > *lista =ProgramaLpp();
		list<NodoSentencia * > *lista2 =Programa();
        lista->insert(lista->end(),lista2->begin(),lista2->end());
		return lista;
	}
	else
	{
		return new list<NodoSentencia*>();
	}
}

list<NodoSentencia*>* Sintactico::ProgramaLpp()
{
	if (this->tokenActual.Tipo == TIPO || this->tokenActual.Tipo == REGISTRO)
	{
		return DefinicionTipos();
	}
	else if (this->tokenActual.Tipo == DECLARAR)
	{
		return Declaraciones();
	}
	else if (this->tokenActual.Tipo == FUNCION || this->tokenActual.Tipo == PROCEDIMIENTO)
	{
		NodoSentencia* subPrograma = DeclaracionSubProgramas();
		list<NodoSentencia*> * lista = new list<NodoSentencia*>();
		lista->insert(lista->begin(), subPrograma);

		return  lista;
	}
	else if (this->tokenActual.Tipo == MIENTRAS || this->tokenActual.Tipo == SI || this->tokenActual.Tipo == LLAMAR || this->tokenActual.Tipo == IDLPP || this->tokenActual.Tipo == PARA || this->tokenActual.Tipo == REPITA || this->tokenActual.Tipo == ESCRIBA || this->tokenActual.Tipo == CASO || this->tokenActual.Tipo == ESCRIBIR || this->tokenActual.Tipo == LEER || this->tokenActual.Tipo == ABRIR || this->tokenActual.Tipo == CERRAR || this->tokenActual.Tipo == RETORNE)
	{
		return ListaProp();
	}
	else
	{
		return new list<NodoSentencia*>();
	}
}

list<NodoSentencia*>* Sintactico::DefinicionTipos()
{
	if (this->tokenActual.Tipo == TIPO || this->tokenActual.Tipo == REGISTRO)
	{
		NodoSentencia * sentencia =DefinicionTipo();
		list<NodoSentencia*>* lista =DefinicionTipos();
		lista->insert(lista->begin(), sentencia);
		return lista;
	}
	else
	{
        return new list<NodoSentencia*>();
	}
}

list<NodoSentencia*>* Sintactico::Declaraciones()
{
	if (this->tokenActual.Tipo == DECLARAR)
	{
		NodoSentencia * declaracion =LineaDeclaraciones();
		list<NodoSentencia*>* lista =Declaraciones();
		lista->insert(lista->begin(), declaracion);
		return lista;
	}
	else
	{
        return new list<NodoSentencia*>();
	}
}

NodoSentencia* Sintactico::LineaDeclaraciones()
{
	if (this->tokenActual.Tipo == DECLARAR)
	{
        Token nodoDeclaracion = tokenActual;
		consumirToken();
        TipoV * tipo =TipoVariable();
		if (tokenActual.Tipo != IDLPP)
		{
			throw ExcepcionSintactica("Se esperaba un ID");
		}
		string nombre = tokenActual.Lexema;
        Token tokenA = tokenActual;
		consumirToken();
		list<NodoLiteralCadena*>*lista = ListaIdentificadores();
        lista->insert(lista->begin(), new NodoLiteralCadena(nombre,new NodoBasico(tokenA)));
        return new NodoDeclaracion(tipo,lista,new NodoBasico(nodoDeclaracion));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  DECLARAR" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

list<NodoLiteralCadena*>* Sintactico::ListaIdentificadores()
{
	if (tokenActual.Tipo == COMA)
	{
		consumirToken();
		if (tokenActual.Tipo != IDLPP)
		{
			throw ExcepcionSintactica("Se esperaba un ID");
		}
		string nombre = tokenActual.Lexema;
        Token tokenA = tokenActual;
		consumirToken();
		list<NodoLiteralCadena*> * lista =ListaIdentificadores();
        lista->insert(lista->begin(), new NodoLiteralCadena(nombre,new NodoBasico(tokenA)));
		return lista;
	}
	else
	{
		return new list<NodoLiteralCadena*>();
	}
}
NodoSentencia* Sintactico::DeclaracionSubProgramas()
{
	if (tokenActual.Tipo == FUNCION || tokenActual.Tipo == PROCEDIMIENTO)
	{
		return DeclaracionSub();
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba FUNCION O PROCEDIMIENTO");
	}
}

NodoSentencia* Sintactico::DeclaracionSub()
{
	if (tokenActual.Tipo == FUNCION || tokenActual.Tipo == PROCEDIMIENTO)
	{
        Token token = tokenActual;
		NodoSentencia  * encabezado = EncabezadoSub();
		list<NodoSentencia* > *listaDeclaraciones =Declaraciones();
		list<NodoSentencia *> * listaProposiciones =ConjuntoProposiciones();
        return new NodoDeclaracionSubPrograma(encabezado, listaDeclaraciones, listaProposiciones, new NodoBasico(token));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  FUNCION O PROCEDIMIENTO" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoSentencia* Sintactico::EncabezadoSub()
{
	if (tokenActual.Tipo == FUNCION)
	{
        Token tokenA = tokenActual;
		consumirToken();
		if (tokenActual.Tipo != IDLPP)
		{
			throw ExcepcionSintactica("Se esperaba un ID" + string(" y se encontro : ") + tokenActual.ToString());
		}
        NodoLiteralCadena * nombre = new NodoLiteralCadena(tokenActual.Lexema,new NodoBasico(tokenActual));
		consumirToken();
		list<NodoSentencia * >* listaArgumentos =Argumentos();
		if (tokenActual.Tipo != DOSPUNTOS)
		{
			throw ExcepcionSintactica("Se esperaba :" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        TipoV * tipoVariable=TipoVariable();
        return new NodoFuncionEncabezado(nombre, listaArgumentos, tipoVariable,new NodoBasico(tokenA));
	}
	else if (tokenActual.Tipo == PROCEDIMIENTO)
	{
        Token tokenP =tokenActual;
		consumirToken();
		if (tokenActual.Tipo != IDLPP)
		{
			throw ExcepcionSintactica("Se esperaba un ID" + string(" y se encontro : ") + tokenActual.ToString());
		}
        NodoLiteralCadena * nombre = new NodoLiteralCadena(tokenActual.Lexema, new NodoBasico(tokenActual));
		consumirToken();
		list<NodoSentencia * >* listaArgumentos = Argumentos();
        return new NodoProcedimientoEncabezado(nombre, listaArgumentos,new NodoBasico(tokenP));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  FUNCION O PROCEDIMIENTO" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

list<NodoSentencia*>* Sintactico::Argumentos()
{
	if (tokenActual.Tipo == PARENTHESISI)
	{

		consumirToken();
		list<NodoSentencia*>* parametros =Parametros();
		if (tokenActual.Tipo != PARENTHESISD)
		{
			throw ExcepcionSintactica("Se esperaba  )" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		return parametros;
	}
	else
	{
		return new list<NodoSentencia*>();
	}
}

list<NodoSentencia*>* Sintactico::Parametros()
{
	if (tokenActual.Tipo == VAR || tokenActual.Tipo == ARREGLO || tokenActual.Tipo == IDLPP || tokenActual.Tipo == ENTERO || tokenActual.Tipo == REAL || tokenActual.Tipo == CADENA || tokenActual.Tipo == CARACTER || tokenActual.Tipo == BOOLEANO || tokenActual.Tipo == ARCHIVO)
	{

		NodoSentencia* parametro = DeclaracionParametro();
		list<NodoSentencia* > * lista =ParametrosPrima();
		lista->insert(lista->begin(), parametro);
		return lista;
	}
	else
	{
		return new list<NodoSentencia*>();
	}
}

NodoSentencia* Sintactico::DeclaracionParametro()
{
	if (tokenActual.Tipo == VAR)
	{
        Token tokenA =tokenActual;
		consumirToken();
        TipoV * tipoVariable =TipoVariable();
		if (tokenActual.Tipo != IDLPP)
		{
			throw ExcepcionSintactica("Se esperaba  ID" + string(" y se encontro : ") + tokenActual.ToString());
		}
        NodoLiteralCadena  *literalCadena = new NodoLiteralCadena(tokenActual.Lexema,new NodoBasico(tokenActual));

		consumirToken();
        return new NodoParametroVar(tipoVariable , literalCadena, new NodoBasico(tokenA));
	}
	else if (tokenActual.Tipo == ARREGLO || tokenActual.Tipo == IDLPP || tokenActual.Tipo == ENTERO || tokenActual.Tipo == REAL || tokenActual.Tipo == CADENA || tokenActual.Tipo == CARACTER || tokenActual.Tipo == BOOLEANO || tokenActual.Tipo == ARCHIVO)
	{
        Token tokenA = tokenActual;
        TipoV * tipoVariable = TipoVariable();
		if (tokenActual.Tipo != IDLPP)
		{
			throw ExcepcionSintactica("Se esperaba  ID" + string(" y se encontro : ") + tokenActual.ToString());
		}
        NodoLiteralCadena  *literalCadena = new NodoLiteralCadena(tokenActual.Lexema,new NodoBasico(tokenActual));
		consumirToken();
        return new NodoParametro(tipoVariable,literalCadena,new NodoBasico(tokenA));
	}else
	{
		throw ExcepcionSintactica("Se esperaba Parametro  ,Tipo o VAR");
	}
}

list<NodoSentencia*>* Sintactico::ParametrosPrima()
{
	if (tokenActual.Tipo == COMA)
	{
		consumirToken();
		if (tokenActual.Tipo == VAR || tokenActual.Tipo == ARREGLO || tokenActual.Tipo == IDLPP || tokenActual.Tipo == ENTERO || tokenActual.Tipo == REAL || tokenActual.Tipo == CADENA || tokenActual.Tipo == CARACTER || tokenActual.Tipo == BOOLEANO || tokenActual.Tipo == ARCHIVO)
		{
			NodoSentencia* parametro = DeclaracionParametro();
			list<NodoSentencia*>*lista = ParametrosPrima();
			lista->insert(lista->begin(), parametro);
			return lista;
		}else
		{
			throw ExcepcionSintactica("Se esperaba Parametro  ,Tipo o VAR");
			
		}
	}
	else
	{
		return new list<NodoSentencia*>();
	}
}

list<NodoSentencia*>* Sintactico::ListaProp()
{
	if (tokenActual.Tipo == MIENTRAS || tokenActual.Tipo == SI || tokenActual.Tipo == LLAMAR || tokenActual.Tipo == IDLPP || tokenActual.Tipo == PARA || tokenActual.Tipo == REPITA || tokenActual.Tipo == ESCRIBA || tokenActual.Tipo == CASO || tokenActual.Tipo == ESCRIBIR || tokenActual.Tipo == LEER || tokenActual.Tipo == ABRIR || tokenActual.Tipo == CERRAR || tokenActual.Tipo == RETORNE)
	{
		NodoSentencia* propos = Proposicion();
		list<NodoSentencia*>* lista =ListaProp();
		lista->insert(lista->begin(), propos);
		return lista;
	}
	else
	{
		return new list<NodoSentencia*>();
	}
}

NodoSentencia* Sintactico::Proposicion()
{
	if (tokenActual.Tipo == MIENTRAS)
	{
		return ProposicionMientras();
	}
	else if (tokenActual.Tipo == SI)
	{
		return ProposicionSi();
	}
	else if (tokenActual.Tipo == LLAMAR)
	{
		return PropisicionLlamar();
	}
	else if (tokenActual.Tipo == IDLPP)
	{
		return PropisicionAsignar();
	}
	else if (tokenActual.Tipo == PARA)
	{
		return ProposicionPara();
	}
	else if (tokenActual.Tipo == REPITA)
	{
		return PropisicionRepita();
	}
	else if (tokenActual.Tipo == ESCRIBA)
	{
		return PropisicionEscriba();
	}
	else if (tokenActual.Tipo == CASO)
	{
		return ProposicionCaso();
	}
	else if (tokenActual.Tipo == ESCRIBIR)
	{
		return ProposicionEscribir();
	}
	else if (tokenActual.Tipo == LEER)
	{
		return ProposicionLeer();
	}
	else if (tokenActual.Tipo == ABRIR)
	{
		return PropisicionAbrir();
	}
	else if (tokenActual.Tipo == CERRAR)
	{
		return PropisicionCerrar();
	}
	else //if (tokenActual.Tipo == RETORNE)
	{
		return ProposicionRetorne();
	}
}

NodoSentencia* Sintactico::ProposicionRetorne()
{
	if (tokenActual.Tipo == RETORNE)
	{
        Token tokenA = tokenActual;
		consumirToken();
        return new NodoRetorne(Expresion(),new NodoBasico(tokenA));
	}else
	{
		throw ExcepcionSintactica("Se esperaba Retorne");
	}

}

NodoSentencia* Sintactico::ProposicionMientras()
{
	if (tokenActual.Tipo == MIENTRAS)
	{
        Token  token =tokenActual;
		consumirToken();
		NodoExpression *exp =Expresion();
		if (tokenActual.Tipo != HAGA)
		{
			throw ExcepcionSintactica("Se esperaba  HAGA" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		list<NodoSentencia*>*lista =ListaProp();
		if (tokenActual.Tipo != FIN)
		{
			throw ExcepcionSintactica("Se esperaba  FIN" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		if (tokenActual.Tipo != MIENTRAS)
		{
			throw ExcepcionSintactica("Se esperaba  MIENTRAS" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return new NodoPropMientras(exp,lista, new NodoBasico(token));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  MIENTRAS" + string(" y se encontro : ") + tokenActual.ToString());
	}
}


NodoExpression* Sintactico::Expresion()
{
	NodoExpression* exp = ExpBool();
	return ExpPrima(exp);
}

NodoExpression* Sintactico::ExpBool()
{
	NodoExpression* exp = ExpBasico();
	return ExpBoolPrima(exp);
}

NodoExpression* Sintactico::ExpBasico()
{
	NodoExpression* fact = Factor();
	return ExpBasicoPrima(fact);
}

NodoExpression* Sintactico::Factor()
{
	NodoExpression* exp = ExpOper();
	return FactorPrima(exp);
}

NodoExpression* Sintactico::ExpOper()
{
	NodoExpression* exp = NoLogico();
	return ExpOperPrima(exp);
}

NodoExpression* Sintactico::NoLogico()
{
	if (tokenActual.Tipo == NO)
	{
        Token tokenA = tokenActual;
		consumirToken();
        return new NodoOperadorNo(Term(),new NodoBasico(tokenA));
	}
	else
	{
		return Term();
	}
}

NodoExpression* Sintactico::ValoresNegativo(NodoBasico * nodo)
{
	if (tokenActual.Tipo == LITERALENTERO || tokenActual.Tipo == LITERALREAL || tokenActual.Tipo == LITERALCADENA || tokenActual.Tipo == LITERALCARACTER)
	{
        return new NodoValorNegativo(Literal() , nodo);
	}
	else if (tokenActual.Tipo == PARENTHESISI)
	{
		consumirToken();
		list<NodoExpression * > *lista =ListaExpresiones();
		if (tokenActual.Tipo != PARENTHESISD)
		{
			throw ExcepcionSintactica("Se esperaba  )" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return new NodoValorNegativo(lista,nodo);
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  termino" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoExpression* Sintactico::Term()
{
	if (tokenActual.Tipo == IDLPP)
	{
		NodoExpression* exp =Variable();
		return VariablePrima2(exp);
	}
	else if (tokenActual.Tipo == PARENTHESISI)
	{
		consumirToken();
		NodoExpression * exp =Expresion();
		if (tokenActual.Tipo != PARENTHESISD)
		{
			throw ExcepcionSintactica("Se esperaba  )" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		return exp;
	}
	else if (tokenActual.Tipo == LITERALENTERO || tokenActual.Tipo == LITERALREAL || tokenActual.Tipo == LITERALCADENA || tokenActual.Tipo == LITERALCARACTER || tokenActual.Tipo == VERDADERO || tokenActual.Tipo == FALSO)
	{
		NodoExpression * exp;
		
		if (tokenActual.Tipo == LITERALENTERO)
            exp = new NodoLiteralEntero(std::stoi(tokenActual.Lexema),new NodoBasico(tokenActual));
		else if (tokenActual.Tipo == LITERALREAL)
            exp = new NodoLiteralReal(std::stof(tokenActual.Lexema),new NodoBasico(tokenActual));
		else if (tokenActual.Tipo == LITERALCADENA)
            exp = new NodoLiteralCadena(tokenActual.Lexema,new NodoBasico(tokenActual));
		else if (tokenActual.Tipo == LITERALCARACTER)
            exp = new NodoLiteralCaracter(tokenActual.Lexema.c_str()[0],new NodoBasico(tokenActual));
		else if (tokenActual.Tipo == VERDADERO)
            exp = new NodoVerdadero(new NodoBasico(tokenActual));
		else
            exp = new NodoFalso(new NodoBasico(tokenActual));
		consumirToken();
		return exp;
	}
	else if (tokenActual.Tipo == RESTA)
	{
        Token tokenTemp = tokenActual;
		consumirToken();
        return ValoresNegativo(new NodoBasico(tokenTemp));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  Term" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoExpression* Sintactico::VariablePrima2(NodoExpression * param)
{
	if (tokenActual.Tipo == PARENTHESISI)
	{
        Token tokenA = tokenActual;
		consumirToken();
		list<NodoExpression* > *lista =ListaExpresionesV();
		if (tokenActual.Tipo != PARENTHESISD)
		{
			throw ExcepcionSintactica("Se esperaba  )" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return new NodoFuncion(param, lista,new NodoBasico(tokenA));
		
		
	}
	else
	{
		return param;
	}
}

NodoExpression* Sintactico::ExpOperPrima(NodoExpression* param)
{
	if (tokenActual.Tipo == EXPONENTE)
	{
        Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = NoLogico();
        return ExpOperPrima(new NodoExponente(param, exp, new NodoBasico(token)));
	}
	else
	{
		return param;
	}
}

NodoExpression* Sintactico::FactorPrima(NodoExpression* param)
{
	if (tokenActual.Tipo == MULTIPLICACION)
	{
        Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = ExpOper();
        return FactorPrima(new NodoMultiplicacion(param, exp, new NodoBasico(token)));
	}
	else if (tokenActual.Tipo == DIVISION)
	{
         Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = ExpOper();
        return FactorPrima(new NodoDivision(param, exp,new NodoBasico(token)));
	}
	else if (tokenActual.Tipo == MODULAR)
	{
         Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = ExpOper();
        return FactorPrima(new NodoModular(param, exp,new NodoBasico(token)));
	}
	else if (tokenActual.Tipo == DIVISIONENTERA)
	{
         Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = ExpOper();
        return FactorPrima(new NodoDivisionEntera(param, exp,new NodoBasico(token)));
	}
	else
	{
		return param;
	}
}

NodoExpression* Sintactico::ExpBasicoPrima(NodoExpression* param)
{
	if (tokenActual.Tipo == SUMA)
	{
         Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = Factor();
        return ExpBasicoPrima(new NodoSuma(param, exp,new NodoBasico(token)));
	}
	else if (tokenActual.Tipo == RESTA)
	{
         Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = Factor();
        return ExpBasicoPrima(new NodoResta(param, exp, new NodoBasico(token)));
	}
	else
	{
		return param;
	}
}

NodoExpression* Sintactico::ExpBoolPrima(NodoExpression* param)
{
	if (tokenActual.Tipo == MENOR)
	{
         Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = ExpBasico();
        return ExpBoolPrima(new NodoMenor(param, exp,new NodoBasico(token)));
	}
	else if (tokenActual.Tipo == MAYOR)
	{
         Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = ExpBasico();
        return ExpBoolPrima(new NodoMayor(param, exp,new NodoBasico(token)));
	}
	else if (tokenActual.Tipo == MENORIGUAL)
	{
         Token token = tokenActual;
		consumirToken();

		NodoExpression* exp = ExpBasico();
        return ExpBoolPrima(new NodoMenorIgual(param, exp,new NodoBasico(token)));
	}
	else if (tokenActual.Tipo == MAYORIGUAL)
	{
         Token token = tokenActual;
		consumirToken();

		NodoExpression* exp = ExpBasico();
        return ExpBoolPrima(new NodoMayorIgual(param, exp,new NodoBasico(token)));
	}
	else if (tokenActual.Tipo == IGUAL)
	{
         Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = ExpBasico();
        return ExpBoolPrima(new NodoIgual(param, exp,new NodoBasico(token)));
	}
	else if (tokenActual.Tipo == DIFERENTE)
	{
         Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = ExpBasico();
        return ExpBoolPrima(new NodoDiferente(param, exp,new NodoBasico(token)));
	}
	else
	{
		return param;
	}
}

NodoExpression* Sintactico::ExpPrima(NodoExpression* param)
{
	if (tokenActual.Tipo == Y)
	{
        Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = ExpBool();
        return ExpPrima(new NodoY(param, exp,new NodoBasico(token)));
	}
	else if (tokenActual.Tipo == O)
	{
        Token token = tokenActual;
		consumirToken();
		NodoExpression* exp = ExpBool();
        return ExpPrima((new NodoO(param, exp,new NodoBasico(token))));
	}
	else
	{
		return param;
	}
}

NodoSentencia* Sintactico::ProposicionSi()
{
	if (tokenActual.Tipo == SI)
	{
        Token tokenA = tokenActual;
		consumirToken();
		NodoExpression * exp =Expresion();
		if (tokenActual.Tipo != ENTONCES)
		{
			throw ExcepcionSintactica("Se esperaba  ENTONCES" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		list<NodoSentencia*>*lista =ListaProp();
		NodoSentencia* nodoElse =ProposicionSiPrima();
        return new NodoPropSi(exp, lista, nodoElse,new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  SI" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoSentencia* Sintactico::PropisicionLlamar()
{
	if (tokenActual.Tipo == LLAMAR)
	{
        Token tokenA = tokenActual;
		consumirToken();
		if (tokenActual.Tipo != IDLPP)
		{
			throw ExcepcionSintactica("Se esperaba  ID" + string(" y se encontro : ") + tokenActual.ToString());
		}
        NodoLiteralCadena* nombreFuncion = new NodoLiteralCadena(tokenActual.Lexema,new NodoBasico(tokenActual));
		consumirToken();
		list<NodoExpression*>* listaParametros =Param();
        return new NodoLlamarFuncion(nombreFuncion, listaParametros,new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  LLAMAR" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

list<NodoExpression*>* Sintactico::Param()
{
	if (tokenActual.Tipo == PARENTHESISI)
	{
		consumirToken();
		list<NodoExpression*>* lista =ListaExpresionesV();
		if (tokenActual.Tipo != PARENTHESISD)
		{
			throw ExcepcionSintactica("Se esperaba  )" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		return lista;
	}
	else
	{
		return new list<NodoExpression*>();
	}
}

list<NodoExpression*>* Sintactico::ListaExpresiones()
{
	if (tokenActual.Tipo == IDLPP || tokenActual.Tipo == PARENTHESISI || tokenActual.Tipo == LITERALENTERO || tokenActual.Tipo == LITERALREAL || tokenActual.Tipo == LITERALCADENA || tokenActual.Tipo == LITERALCARACTER || tokenActual.Tipo == VERDADERO || tokenActual.Tipo == FALSO || tokenActual.Tipo == RESTA)
	{
		NodoExpression * exp = Expresion();
		list<NodoExpression*> * lista = ListaExpresionesPrima();
		lista->insert(lista->begin(), exp);
		return lista;
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  expresion" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

list<NodoExpression*>* Sintactico::ListaExpresionesPrima()
{
	if (tokenActual.Tipo == COMA)
	{
		consumirToken();
		NodoExpression* exp =Expresion();
		list<NodoExpression*>*lista =ListaExpresionesPrima();
		lista->insert(lista->begin(), exp);
		return lista;
	}
	else
	{
		return new list<NodoExpression * > ();
	}
}

NodoSentencia* Sintactico::PropisicionAsignar()
{
	if (tokenActual.Tipo == IDLPP)
	{
        Token tokenA = tokenActual;
		NodoExpression *exp =Variable();
		if (tokenActual.Tipo != ASIGNACION)
		{
			throw ExcepcionSintactica("Se esperaba  ASIGNACION" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();


		NodoExpression* valorAsignar=Expresion();
        return new NodoPropAsignar(exp, valorAsignar,new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  ID" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoSentencia* Sintactico::ProposicionSiPrima()
{
	if (tokenActual.Tipo == FIN)
	{
		consumirToken();
		if (tokenActual.Tipo != SI)
		{
			throw ExcepcionSintactica("Se esperaba  SI" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return NULL;
	}
	else if (tokenActual.Tipo == SINO)
	{
        Token tokenA = tokenActual;
		consumirToken();
		list<NodoSentencia*>* lista =ListaProp();
		if (tokenActual.Tipo != FIN)
		{
			throw ExcepcionSintactica("Se esperaba FIN" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		if (tokenActual.Tipo != SI)
		{
			throw ExcepcionSintactica("Se esperaba  SI" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return new NodoSino(lista,new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  FIN o SINO" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoSentencia* Sintactico::ProposicionPara()
{
	if (tokenActual.Tipo == PARA)
	{
         Token tokenA = tokenActual;
		consumirToken();
		NodoExpression * variable =Variable();
		if (tokenActual.Tipo != ASIGNACION)
		{
			throw ExcepcionSintactica("Se esperaba  ASIGNACION" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		NodoExpression *exp =Expresion();
		if (tokenActual.Tipo != HASTA)
		{
			throw ExcepcionSintactica("Se esperaba  HASTA" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		NodoExpression * expr2 =Expresion();
		if (tokenActual.Tipo != HAGA)
		{
			throw ExcepcionSintactica("Se esperaba  HAGA" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		list<NodoSentencia*> *lista = ListaProp();
		if (tokenActual.Tipo != FIN)
		{
			throw ExcepcionSintactica("Se esperaba  FIN" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		if (tokenActual.Tipo != PARA)
		{
			throw ExcepcionSintactica("Se esperaba  PARA" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return new NodoPropPara(variable, exp, expr2, lista,new NodoBasico(tokenA));
    }
	else
	{
		throw ExcepcionSintactica("Se esperaba  PARA" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoExpression* Sintactico::Variable()
{
	if (tokenActual.Tipo == IDLPP)
	{
		NodoExpression * exp = VariableSimple();
		return VariablePrima(exp);
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  ID" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoExpression* Sintactico::VariableSimple()
{
	if (tokenActual.Tipo == IDLPP)
	{
		string lex = tokenActual.Lexema;
        Token tokenA = tokenActual;
		consumirToken();
        return VariableSimplePrima(new NodoId(lex, new NodoBasico(tokenA)));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  ID" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

list<NodoExpression*>* Sintactico::ProposicionEscribaPrima()
{
	if (tokenActual.Tipo == COMA)
	{
		consumirToken();
		return ListaExpresiones();
	}
	else
	{
		return new list<NodoExpression*>();
	}
}

NodoExpression* Sintactico::VariableSimplePrima(NodoExpression* param)
{
	if (tokenActual.Tipo == CORCHETEI)
	{
        Token token = tokenActual ;
		consumirToken();
		list<NodoExpression* > *listaExp =ListaExpresiones();
		if (tokenActual.Tipo != CORCHETED)
		{
			throw ExcepcionSintactica("Se esperaba  ]" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return new NodoVariableArreglo(param, listaExp, new NodoBasico(token));
	}
	else
	{
		return param;
	}
}

NodoExpression* Sintactico::VariablePrima(NodoExpression * param)
{
	if (tokenActual.Tipo == PUNTO)
	{
        Token token = tokenActual;
		consumirToken();
		NodoExpression * expr =VariableSimple();
        return VariablePrima(new NodoVariableRegistro(param,expr, new NodoBasico(token)));
	}
	else
	{
		return param;
	}
}

NodoSentencia* Sintactico::PropisicionRepita()
{
	if (tokenActual.Tipo == REPITA)
	{
        Token tokenA = tokenActual;
		consumirToken();
		list<NodoSentencia*>* lista =ListaProp();
		if (tokenActual.Tipo != HASTA)
		{
			throw ExcepcionSintactica("Se esperaba  HASTA" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		NodoExpression* exp =Expresion();
        return new NodoPropRepita(lista, exp,new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  REPITA" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoSentencia* Sintactico::PropisicionEscriba()
{
	if (tokenActual.Tipo == ESCRIBA)
	{
        Token tokenA = tokenActual;
		consumirToken();
		NodoExpression* exp =Expresion();
        return new NodoPropEscriba(exp,ProposicionEscribaPrima(),new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  ESCRIBA" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoSentencia* Sintactico::ProposicionCaso()
{
	if (tokenActual.Tipo == CASO)
	{
       Token tokenA = tokenActual;
		consumirToken();
		NodoExpression* variable =Variable();
        list<NodoCaso*>* listaCasos =ListaCasos();
        NodoSinoCaso * sino =SinoCaso();
		if (tokenActual.Tipo != FIN)
		{
			throw ExcepcionSintactica("Se esperaba  FIN" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		if (tokenActual.Tipo != CASO)
		{
			throw ExcepcionSintactica("Se esperaba  CASO" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return new NodoProposicionCaso(variable, listaCasos, sino,new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  CASO" + string(" y se encontro : ") + tokenActual.ToString());
	}
}


list<NodoCaso*>* Sintactico::ListaCasos()
{
	if (tokenActual.Tipo == LITERALENTERO || tokenActual.Tipo == LITERALCADENA || tokenActual.Tipo == LITERALCARACTER || tokenActual.Tipo == LITERALREAL)
	{
        NodoCaso * caso =LineaCaso();
        list<NodoCaso*>* lista =ListaCasos();
		lista->insert(lista->begin(), caso);
		return lista;
	}
	else
	{
        return new list<NodoCaso*>();
	}
}

NodoCaso* Sintactico::LineaCaso()
{
	if (tokenActual.Tipo == LITERALENTERO || tokenActual.Tipo == LITERALCADENA || tokenActual.Tipo == LITERALCARACTER || tokenActual.Tipo == LITERALREAL)
	{
        Token tokenA = tokenActual;
		list<NodoExpression*>*listaLiterales =ListaLiterales();
		if (tokenActual.Tipo != DOSPUNTOS)
		{
			throw ExcepcionSintactica("Se esperaba  DOSPUNTOS" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		list<NodoSentencia*>* listaProposiciones =ListaProp();
        return new NodoCaso(listaLiterales,listaProposiciones,new NodoBasico(tokenA));
	}else
	{
		throw ExcepcionSintactica("Se esperaba una literal");
	}
}

list<NodoExpression*>* Sintactico::ListaLiterales()
{
	if (tokenActual.Tipo == LITERALENTERO || tokenActual.Tipo == LITERALCADENA || tokenActual.Tipo == LITERALCARACTER || tokenActual.Tipo == LITERALREAL)
	{
		NodoExpression* literal = Literal();
		list<NodoExpression*>* listaLiterales =ListaLiteralPrima();
		listaLiterales->insert(listaLiterales->begin(), literal);
		return listaLiterales;
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  una LITERAL" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoExpression* Sintactico::Literal()
{
	if (tokenActual.Tipo == LITERALENTERO || tokenActual.Tipo == LITERALCADENA || tokenActual.Tipo == LITERALCARACTER || tokenActual.Tipo == LITERALREAL)
	{
		NodoExpression* exp;
		if (tokenActual.Tipo == LITERALENTERO)
            exp = new NodoLiteralEntero(stoi(tokenActual.Lexema),new NodoBasico(tokenActual));
		else if (tokenActual.Tipo == LITERALREAL)
           exp = new NodoLiteralReal(stof(tokenActual.Lexema), new NodoBasico(tokenActual));
		else if (tokenActual.Tipo == LITERALCADENA)
            exp = new NodoLiteralCadena(tokenActual.Lexema,new NodoBasico(tokenActual));
		else 
            exp = new NodoLiteralCaracter(tokenActual.Lexema.c_str()[0],new NodoBasico(tokenActual));

		consumirToken();
	    return exp;
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba una Literal" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

list<NodoExpression*>* Sintactico::ListaLiteralPrima()
{
	if (tokenActual.Tipo == COMA)
	{
		consumirToken();
		NodoExpression * literal =Literal();
		list<NodoExpression*>*lista= ListaLiteralPrima();
		lista->insert(lista->begin(), literal);
		return lista;
	}
	else
	{
		return new list<NodoExpression*>();
	}
}

NodoSinoCaso* Sintactico::SinoCaso()
{
	if (tokenActual.Tipo == SINO)
	{
        Token tokenA = tokenActual;
		consumirToken();
		if (tokenActual.Tipo != DOSPUNTOS)
		{
			throw ExcepcionSintactica("Se esperaba  DOSPUNTOS" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		list<NodoSentencia*>* lista =ListaProp();
        return new NodoSinoCaso(lista,new NodoBasico(tokenA));
	}
	else
	{
        return NULL;
	}
}

NodoSentencia* Sintactico::ProposicionEscribir()
{
	if (tokenActual.Tipo == ESCRIBIR)
	{
        Token tokenA = tokenActual;
		consumirToken();
		NodoExpression* exp =Expresion();
		if (tokenActual.Tipo != COMA)
		{
			throw ExcepcionSintactica("Se esperaba  COMA" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return new NodoPropEscribir(exp,ListaExpresiones(), new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  ESCRIBIR" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoSentencia* Sintactico::ProposicionLeer()
{
	if (tokenActual.Tipo == LEER)
	{
       Token tokenA = tokenActual;
		consumirToken();
		NodoExpression * variable =Variable();
		if (tokenActual.Tipo != COMA)
		{
			throw ExcepcionSintactica("Se esperaba  COMA" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		list<NodoExpression*> * listaVariable =ListaVariable();
        return new NodoPropLeer(variable, listaVariable, new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  LEER" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

list<NodoExpression*>* Sintactico::ListaVariable()
{
	if (tokenActual.Tipo == IDLPP)
	{
		NodoExpression * variable = Variable();
		list<NodoExpression*> *listaVariables =ListaVariablePrima();
		listaVariables->insert(listaVariables->begin(), variable);
		return listaVariables;
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  ID" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

list<NodoExpression*>* Sintactico::ListaVariablePrima()
{
	if (tokenActual.Tipo == COMA)
	{
		consumirToken();
		NodoExpression * variable =Variable();
		list<NodoExpression*>* lista =ListaVariablePrima();
		lista->insert(lista->begin(), variable);
		return lista;
	}
	else
	{
		return new list<NodoExpression*>();
	}
}

NodoSentencia* Sintactico::PropisicionAbrir()
{
	if (tokenActual.Tipo == ABRIR)
	{
        Token tokenA=tokenActual;
		consumirToken();
		NodoExpression * exp =Expresion();
		if (tokenActual.Tipo != COMO)
		{
			throw ExcepcionSintactica("Se esperaba  COMO" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		NodoExpression* variable =Variable();
		list<NodoSentencia *>* listaOperaciones =ListaOperaciones();
        return new NodoPropAbrir(exp, variable, listaOperaciones, new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  ABRIR" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

list<NodoSentencia*>* Sintactico::ListaOperaciones()
{
	if (tokenActual.Tipo == PARA)
	{
		consumirToken();
		NodoSentencia* oper = Operacion();
		NodoSentencia* oper2 =OperacionPrima();
		list<NodoSentencia* >* listaOperaciones = new list<NodoSentencia*>();
		listaOperaciones->push_back(oper);
		listaOperaciones->push_back(oper2);
		return listaOperaciones;
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  PARA" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoSentencia* Sintactico::Operacion()
{
	if (tokenActual.Tipo == LECTURA || tokenActual.Tipo == ESCRITURA)
	{
		NodoSentencia* nodo;
		if (tokenActual.Tipo == LECTURA)
            nodo = new NodoOperacionLectura(new NodoBasico(tokenActual));
		else
            nodo = new NodoOperacionEscritura(new NodoBasico(tokenActual));
		consumirToken();
		return nodo;
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  ESCRITURA O LECTURA" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoSentencia* Sintactico::OperacionPrima()
{
	if (tokenActual.Tipo == COMA)
	{
		consumirToken();
		return Operacion();
	}
	else
	{
        return NULL;
	}
}

NodoSentencia* Sintactico::PropisicionCerrar()
{
	if (tokenActual.Tipo == CERRAR)
	{
        Token tokenA = tokenActual;
		consumirToken();
        return new NodoPropCerrar(Variable(),new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  CERRAR" + string(" y se encontro : ") + tokenActual.ToString());
	}
}


list<NodoSentencia*>* Sintactico::ConjuntoProposiciones()
{
	if (tokenActual.Tipo == INICIO)
	{
		consumirToken();
		list<NodoSentencia*>* listaProposiciones =ListaProp();
		if (tokenActual.Tipo != FIN)
		{
			throw ExcepcionSintactica("Se esperaba  FIN" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		return listaProposiciones;
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  INICIO" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoSentencia* Sintactico::DefinicionTipo()
{
	if (tokenActual.Tipo == TIPO)
	{
        Token tokenA = tokenActual;
		consumirToken();
		if (tokenActual.Tipo != IDLPP)
		{
			throw ExcepcionSintactica("Se esperaba un ID" + string(" y se encontro : ") + tokenActual.ToString());
		}
        NodoLiteralCadena * nombre = new NodoLiteralCadena(tokenActual.Lexema,new NodoBasico(tokenActual));
		consumirToken();
		if (tokenActual.Tipo != ES)
		{
			throw ExcepcionSintactica("Se esperaba la palabra Reservada ES" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        TipoV* tipo =TipoVariable();
        return new NodoTipo(nombre, tipo, new NodoBasico(tokenA));
	}
	else if (tokenActual.Tipo == REGISTRO)
	{
        Token tokenA = tokenActual;
		consumirToken();
		if (tokenActual.Tipo != IDLPP)
		{
			throw ExcepcionSintactica("Se esperaba un ID" + string(" y se encontro : ") + tokenActual.ToString());
		}
        NodoLiteralCadena * nombre = new NodoLiteralCadena(tokenActual.Lexema,new NodoBasico(tokenActual));
		consumirToken();
		list<NodoSentencia*>* declaraciones =Declaraciones();
		if (tokenActual.Tipo != FIN)
		{
			throw ExcepcionSintactica("Se esperaba FIN" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		if (tokenActual.Tipo != REGISTRO)
		{
			throw ExcepcionSintactica("Se esperaba REGISTRO" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return new NodoRegistro(nombre, declaraciones,new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  TIPO O REGISTRO" + string(" y se encontro : ") + tokenActual.ToString());
	}
}


TipoV* Sintactico::TipoVariable()
{
	if (tokenActual.Tipo == ENTERO || tokenActual.Tipo == REAL || tokenActual.Tipo == CADENA || tokenActual.Tipo == CARACTER || tokenActual.Tipo == BOOLEANO || tokenActual.Tipo == ARCHIVO)
	{
		return TipoPrimitivo();
	}
	else if (tokenActual.Tipo == ARREGLO)
	{
        Token token = tokenActual;
		consumirToken();
		if (tokenActual.Tipo != CORCHETEI)
		{
			throw ExcepcionSintactica("Se esperaba [" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		NodoSentencia * lista =ListaEnteros();
		if (tokenActual.Tipo != CORCHETED)
		{
			throw ExcepcionSintactica("Se esperaba ]" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		if (tokenActual.Tipo != DE)
		{
			throw ExcepcionSintactica("Se esperaba DE" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return new NodoTipoVariableArreglo(lista,TipoVariable(),new NodoBasico(token));
	}
	else if (tokenActual.Tipo == ARCHIVO)
	{
        Token tokenA = tokenActual;
		consumirToken();
		if (tokenActual.Tipo != DE)
		{
			throw ExcepcionSintactica("Se esperaba DE" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
        return new NodoTipoArchivo(TipoVariable(), new NodoBasico(tokenA));
	}
	else if (tokenActual.Tipo == IDLPP)
	{
		string nombre =tokenActual.Lexema;
        Token tokenA= tokenActual;
		consumirToken();
        return new NodoTipoObjecto(new NodoLiteralCadena(nombre,new NodoBasico(tokenA)),new NodoBasico(tokenA));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  Tipo Variable" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

NodoSentencia* Sintactico::ListaEnteros()
{
	if (tokenActual.Tipo == LITERALENTERO)
	{
		int valor = stoi(tokenActual.Lexema);
        Token token = tokenActual;
		consumirToken();
		list<NodoLiteralEntero*> *lista = ListaEnterosPrima();
        lista->insert(lista->begin(), new NodoLiteralEntero(valor,new NodoBasico(token)));
        return new NodoListaLiteralEnteros(lista,new NodoBasico(token));
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  LITERALENTERO" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

list<NodoLiteralEntero*> * Sintactico::ListaEnterosPrima()
{
	if (tokenActual.Tipo == COMA)
	{
		consumirToken();
		
		if (tokenActual.Tipo != LITERALENTERO)
		{
			throw ExcepcionSintactica("Se esperaba LITERALENTERO" + string(" y se encontro : ") + tokenActual.ToString());
		}
		int valor = stoi(tokenActual.Lexema);
        Token token = tokenActual;
		consumirToken();
		list<NodoLiteralEntero*> *lista = ListaEnterosPrima();
        lista->insert(lista->begin(), new NodoLiteralEntero(valor, new NodoBasico(token)));
		return lista;
	}
	else
	{
		return new list<NodoLiteralEntero*>();
	}
}

TipoV* Sintactico::TipoPrimitivo()
{
	if (tokenActual.Tipo == ENTERO || tokenActual.Tipo == REAL || tokenActual.Tipo == CARACTER || tokenActual.Tipo == BOOLEANO)
	{
        TipoV* nodo;
		if (tokenActual.Tipo == ENTERO)
            nodo = new TipoEntero(new NodoBasico(tokenActual));
		else if (tokenActual.Tipo == REAL)
            nodo = new TipoReal(new NodoBasico(tokenActual));
		else if (tokenActual.Tipo == CARACTER)
            nodo = new TipoCaracter(new NodoBasico(tokenActual));
		else
            nodo = new TipoBooleano(new NodoBasico(tokenActual));
		consumirToken();
		return nodo;
	}
	else if (tokenActual.Tipo == CADENA)
	{
        Token tokenC = tokenActual;
		consumirToken();
		if (tokenActual.Tipo != CORCHETEI)
		{
			throw ExcepcionSintactica("Se esperaba [" + string(" y se encontro : ") + tokenActual.ToString());
		}
		consumirToken();
		if (tokenActual.Tipo != LITERALENTERO)
		{
			throw ExcepcionSintactica("Se esperaba LITERALENTERO" + string(" y se encontro : ") + tokenActual.ToString());
		}
        NodoLiteralEntero * entero = new NodoLiteralEntero(stoi(tokenActual.Lexema),new NodoBasico(tokenActual));
		consumirToken();
		if (tokenActual.Tipo != CORCHETED)
		{
			throw ExcepcionSintactica("Se esperaba ]" + string(" y se encontro : ") + tokenActual.ToString());
		}

		consumirToken();
        return new NodoTipoCadena(entero,new NodoBasico(tokenC));
	}
	else if (tokenActual.Tipo == ARCHIVO)
	{
		consumirToken();
        return ArchivoPrima();

        //return new NodoArchivoSecuencial();
	}
	else
	{
		throw ExcepcionSintactica("Se esperaba  Tipo Variable" + string(" y se encontro : ") + tokenActual.ToString());
	}
}

TipoV * Sintactico::ArchivoPrima()
{
    if(tokenActual.Tipo == SECUENCIAL){
        Token tokenA = tokenActual;
        consumirToken();
        return new NodoArchivoSecuencial(new NodoBasico(tokenA));
    }else if (tokenActual.Tipo == DE){
       Token tokenA = tokenActual;
       consumirToken();
      TipoV* tipoV = TipoVariable();
      return new NodoArchivoVariable(tipoV  , new NodoBasico(tokenA));
    }else{
        throw ExcepcionSintactica("Se esperaba  Secuencial o DE" + string(" y se encontro : ") + tokenActual.ToString());
    }
}

list<NodoExpression*>* Sintactico::ListaExpresionesV()
{
	if (tokenActual.Tipo == IDLPP || tokenActual.Tipo == PARENTHESISI || tokenActual.Tipo == LITERALENTERO || tokenActual.Tipo == LITERALREAL || tokenActual.Tipo == LITERALCADENA || tokenActual.Tipo == LITERALCARACTER || tokenActual.Tipo == VERDADERO || tokenActual.Tipo == FALSO || tokenActual.Tipo == RESTA)
	{
		NodoExpression* exp =Expresion();
		list<NodoExpression*>*lista =  ListaExpresionesPrima();
		lista->insert(lista->begin(), exp);
		return lista;
	}
	else
	{
		return new list<NodoExpression*>();
	}
}
