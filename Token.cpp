/* 
 * File:   Token.cpp
 * Author: erick304
 * 
 * Created on July 21, 2015, 8:13 PM
 */

#include <algorithm>

#include "Token.h"
#include <sstream>

Token::Token()
{
}

Token::Token(const Token& orig)
{
}

Token::~Token()
{
}

string Token::ObtenerTipoCorrespondiente(TipoToken tipo)
{
	switch (tipo)
	{
	case EOFLPP:
		return "E0F";
	case REGISTRO:
		return "REGISTRO";
	case ARCHIVO:
		return "ARCHIVO";
	case LEER:
		return "LEER";
	case CERRAR:
		return "CERRAR";
	case DECLARAR:
		return "DECLARAR";
	case CORCHETEI:
		return "CORCHETEI";
	case CORCHETED:
		return "CORCHETED";
	case ENTERO:
		return "ENTERO";
	case REAL:
		return "REAL";
	case IDLPP:
		return "ID";
	case INICIO:
		return "INICIO";
	case CARACTER:
		return "CARACTER";
	case BOOLEANO:
		return "BOOLEANO";
	case CADENA:
		return "CADENA";
	case MULTIPLICACION:
		return "MULTIPLICACION";
	case DIVISION:
		return "DIVISION";
	case SUMA:
		return "SUMA";
	case RESTA:
		return "RESTA";
	case SI:
		return "SI";
	case IGUAL:
		return "IGUAL";
	case MENORIGUAL:
		return "MENORIGUAL";
	case MAYORIGUAL:
		return "MAYORIGUAL";
	case MAYOR:
		return "MAYOR";
	case MENOR:
		return "MENOR";
	case VAR:
		return "VAR";
	case MOD:
		return "MOD";
	case DIV:
		return "DIV";
	case ENTONCES:
		return "ENTONCES";
	case SINO:
		return "SINO";
	case COMA:
		return "COMA";
	case DOSPUNTOS:
		return "DOSPUNTOS";
	case ASIGNACION:
		return "ASIGNACION";
	case REPITA:
		return "REPITA";
	case HASTA:
		return "HASTA";
	case PARENTHESISI:
		return "PARENTHESISI";
	case PARENTHESISD:
		return "PARENTHESISD";
	case EXPONENTE:
		return "EXPONENTE";
	case MODULAR:
		return "MODULAR";
	case DIVISIONENTERA:
		return "DIVISIONENTERA";
	case ARREGLO:
		return "ARREGLO";
	case TIPO:
		return "TIPO";
	case ABRIR:
		return "ABRIR";
	case ESCRIBIR:
		return "ESCRIBIR";
	case Y:
		return "Y";
	case O:
		return "O";
	case PROCEDIMIENTO:
		return "PROCEDIMIENTO";
	case FUNCION:
		return "FUNCION";
	case CASO:
		return "CASO";
	case FIN:
		return "FIN";
	case HTML:
		return "HTML";
	case ESCRIBA:
		return "ESCRIBA";
	case LITERALCADENA:
		return "LITERALCADENA";
	case LITERALCARACTER:
		return "LITERALCARACTER";
	case LITERALENTERO:
		return "LITERALENTERO";
	case LITERALREAL:
		return "LITERALREAL";
	case VERDADERO:
		return "VERDADERO";
	case FALSO:
		return "FALSO";
	case ES:
		return "ES";
	case DIFERENTE:
		return "DIFERENTE";
	case MIENTRAS:
		return "MIENTRAS";
	case RETORNE:
		return "RETORNE";
	case PARA:
		return "PARA";
	case LLAMAR:
		return "LLAMAR";
	case HAGA:
		return "HAGA";
	default:
		return "No Existe";
	}
}

TipoToken Token::ObtenerTipo(string lexema)
{
	if (lexema.compare("INICIO") == 0)
		return INICIO;
	if (lexema.compare("FIN") == 0)
		return FIN;
}

void Token::Imprimir()
{

	cout << "Lexema: " << this->Lexema;// << " "<< "Fila: " << this->Fila<< " " << "Columna: " << this->Columna;
}


string Token::ToString()
{
	return "Tipo: " + ObtenerTipoCorrespondiente(this->Tipo) + " Lexema: " + this->Lexema + " Fila : " + IntToString(this->Fila) + " Columna : " + IntToString(this->Columna) + "\n";
}

void Token::EstablecerLinea(int fila, int columna)
{
	this->Fila = fila;
	this->Columna = columna;
}

std::string Token::IntToString(int number)
{
	std::ostringstream oss;

	// Works just like cout
	oss << number;

	// Return the underlying string
	return oss.str();
}
