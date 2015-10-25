/* 
 * File:   Lexico.cpp
 * Author: erick304
 * 
 * Created on July 27, 2015, 7:03 AM
 */


#include <ctype.h>
#include <map>
#include <utility>
#include "Token.h"
#include "Lexico.h"
#include "ExcepcionLexica.h"


Lexico::Lexico(string entrada)
{
	this->entrada = entrada;
	InitListaPalabraReservada();
}

void Lexico::InitListaPalabraReservada()
{
	this->PalabrasOperadoresReservados["INICIO"] = INICIO;
	this->PalabrasOperadoresReservados["FIN"] = FIN;
	this->PalabrasOperadoresReservados["DECLARAR"] = DECLARAR;
	this->PalabrasOperadoresReservados["REGISTRO"] = REGISTRO;
	this->PalabrasOperadoresReservados["ARCHIVO"] = ARCHIVO;
	this->PalabrasOperadoresReservados["PARA"] = PARA;
	this->PalabrasOperadoresReservados["ESCRIBA"] = ESCRIBA;
	this->PalabrasOperadoresReservados["LLAMAR"] = LLAMAR;
	this->PalabrasOperadoresReservados["FUNCION"] = FUNCION;
	this->PalabrasOperadoresReservados["PROCEDIMIENTO"] = PROCEDIMIENTO;
	this->PalabrasOperadoresReservados["ENTERO"] = ENTERO;
	this->PalabrasOperadoresReservados["CADENA"] = CADENA;
	this->PalabrasOperadoresReservados["CARACTER"] = CARACTER;
	this->PalabrasOperadoresReservados["REAL"] = REAL;
	this->PalabrasOperadoresReservados["BOOLEANO"] = BOOLEANO;
	this->PalabrasOperadoresReservados["SI"] = SI;
	this->PalabrasOperadoresReservados["ENTONCES"] = ENTONCES;
	this->PalabrasOperadoresReservados["SINO"] = SINO;
	this->PalabrasOperadoresReservados["CASO"] = CASO;
	this->PalabrasOperadoresReservados["REPITA"] = REPITA;
	this->PalabrasOperadoresReservados["ESCRIBIR"] = ESCRIBIR;
	this->PalabrasOperadoresReservados["HASTA"] = HASTA;
	this->PalabrasOperadoresReservados["ARREGLO"] = ARREGLO;
	this->PalabrasOperadoresReservados["TIPO"] = TIPO;
	this->PalabrasOperadoresReservados["ABRIR"] = ABRIR;
	this->PalabrasOperadoresReservados["VERDADERO"] = VERDADERO;
	this->PalabrasOperadoresReservados["FALSO"] = FALSO;
	this->PalabrasOperadoresReservados["DE"] = DE;
	this->PalabrasOperadoresReservados["COMO"] = COMO;
	this->PalabrasOperadoresReservados["MOD"] = MOD;
	this->PalabrasOperadoresReservados["DIV"] = DIV;
	this->PalabrasOperadoresReservados["Y"] = Y;
	this->PalabrasOperadoresReservados["O"] = O;
	this->PalabrasOperadoresReservados["SECUENCIAL"] = SECUENCIAL;
	this->PalabrasOperadoresReservados["LECTURA"] = LECTURA;
	this->PalabrasOperadoresReservados["ESCRITURA"] = ESCRITURA;
	this->PalabrasOperadoresReservados["MIENTRAS"] = MIENTRAS;
	this->PalabrasOperadoresReservados["RETORNE"] = RETORNE;
	this->PalabrasOperadoresReservados["HAGA"] = HAGA;
	this->PalabrasOperadoresReservados["NO"] = NO;
	this->PalabrasOperadoresReservados["ES"] = ES;
	this->PalabrasOperadoresReservados["VAR"] = VAR;
	this->PalabrasOperadoresReservados["LEER"] = LEER;
	this->PalabrasOperadoresReservados["CERRAR"] = CERRAR;
	this->PalabrasOperadoresReservados["MENORIGUAL"] = MENORIGUAL;
	this->PalabrasOperadoresReservados["MAYORIGUAL"] = MAYORIGUAL;
	this->PalabrasOperadoresReservados["("] = PARENTHESISI;
	this->PalabrasOperadoresReservados[")"] = PARENTHESISD;
	this->PalabrasOperadoresReservados["["] = CORCHETEI;
	this->PalabrasOperadoresReservados["]"] = CORCHETED;
	this->PalabrasOperadoresReservados["-"] = RESTA;
	this->PalabrasOperadoresReservados["+"] = SUMA;
	this->PalabrasOperadoresReservados[":"] = DOSPUNTOS;
	this->PalabrasOperadoresReservados[","] = COMA;
	this->PalabrasOperadoresReservados["*"] = MULTIPLICACION;
	this->PalabrasOperadoresReservados["="] = IGUAL;
	this->PalabrasOperadoresReservados["."] = PUNTO;
	this->PalabrasOperadoresReservados["^"] = EXPONENTE;
}


Lexico::~Lexico()
{
}

char Lexico::ObtenerSimboloActual()
{
	if (posicion < entrada.size())
		return this->entrada[posicion];
	return '\0';
}

char Lexico::ObtenerSiguienteSimbolo()
{
	posicion++;
	char simbolo;
	simbolo = ObtenerSimboloActual();
	if (simbolo == '\n')
	{
		fila++;
		columna = 0;
	}
	else if (simbolo == '\r')
	{
		columna = 0;
	}
	else if (simbolo == '\t')
	{
		columna += 4;
	}
	else
		columna++;

	return simbolo;
}

bool Lexico::EsPalabraReservada(TipoToken tipo)
{
	string tipoS = Token::ObtenerTipoCorrespondiente(tipo);

	return false;
}

TipoToken Lexico::ObtenerTokenCorrespondiente(std::string token)
{
	string tokenMayuscula = token;
	std::transform(tokenMayuscula.begin(), tokenMayuscula.end(), tokenMayuscula.begin(), ::toupper);
	map<string, TipoToken>::iterator it = this->PalabrasOperadoresReservados.find(tokenMayuscula);
	TipoToken tokenR;
	if (it != this->PalabrasOperadoresReservados.end())
	{
		tokenR = it->second;
	}
	else
	{
		tokenR = IDLPP;
	}
	return tokenR;
}

Token Lexico::ObtenerToken()
{
	int estadoActual = 0;
	if (modoLpp)
		estadoActual = 4;

	char simbolo = ObtenerSimboloActual();

	int columna = this->columna;
	Token token;

	while (1)
	{
		token.EstablecerLinea(this->fila, columna);

		switch (estadoActual)
		{
		case 0:
			if (simbolo == '\0')
			{
				estadoActual = 1;
			}
			else if (simbolo == '<')
			{
				this->lexemaAnterior = token.Lexema;
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 2;
			}
			else
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 3;
			}
			break;

		case 1:
			token.Tipo = EOFLPP;
			token.Lexema = " ";
			return token;
		case 2:
			if (simbolo == '%')
			{
				token.Lexema = lexemaAnterior;
				token.Tipo = HTML;
				this->modoLpp = true;
				simbolo = ObtenerSiguienteSimbolo();
				return token;
			}
			else if (simbolo == '\0')
			{
				estadoActual = 1;
				token.Tipo = HTML;
				return token;
			}
			else
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 3;
			}
			break;
		case 3:
			if (simbolo == '<')
			{
				this->lexemaAnterior = token.Lexema;
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 2;
			}
			else if (simbolo == '\0')
			{
				estadoActual = 1;
				token.Tipo = HTML;
				return token;
			}
			else
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
			}
			break;
		case 4:
			if (simbolo == '.' || simbolo == '+' || simbolo == '-' || simbolo == '*' || simbolo == '(' || simbolo == ')' || simbolo == '^' || simbolo == ':' || simbolo == ',' || simbolo == '=' || simbolo == '[' || simbolo == ']')
			{
				estadoActual = 5;
			}
			else if (simbolo == '\'')
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 6;
			}
			else if (isalpha(simbolo) || simbolo == '_')
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 9;
			}
			else if (isdigit(simbolo))
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 10;
			}
			else if (simbolo == '"')
			{
                //token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 13;
			}
			else if (simbolo == '<')
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 15;
			}
			else if (simbolo == '>')
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 19;
			}
			else if (simbolo == '/')
			{
				lexemaAnterior = token.Lexema;
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 21;
			}
			else if (simbolo == '%')
			{
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 25;
			}
			else if (simbolo == ' ' || simbolo == '\n' || simbolo == '\t' || simbolo == '\r')
			{
				simbolo = ObtenerSiguienteSimbolo();
			}
			else
			{
				throw ExcepcionLexica("Token no reconocido");
			}

			break;
		case 5:
			token.Lexema += simbolo;
			token.Tipo = ObtenerTokenCorrespondiente(string(1, simbolo));
			simbolo = ObtenerSiguienteSimbolo();
			return token;
		case 6:
			if (simbolo == '\'' || simbolo == '\n')
			{
				throw ExcepcionLexica("Se esperaba caracter entre las comillas simples");
			}
			else
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 7;
			}

			break;

		case 7:
			if (simbolo == '\'')
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 8;
			}
			else
			{
				throw ExcepcionLexica("Se esperaba que se cerrara las comillas simples");
			}
			break;
		case 8:
			token.Tipo = LITERALCARACTER;
			return token;
		case 9:
			if (simbolo == '_' || isalpha(simbolo) || isdigit(simbolo))
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
			}
			else
			{
				token.Tipo = ObtenerTokenCorrespondiente(token.Lexema);
				return token;
			}
			break;
		case 10:
			if (isdigit(simbolo))
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
			}
			else if (simbolo == '.')
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 11;
			}
			else
			{
				token.Tipo = LITERALENTERO;
				return token;
			}
			break;
		case 11:
			if (isdigit(simbolo))
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 12;
			}
			else
			{
				throw ExcepcionLexica("Se esperaba digito despues del punto");
			}
			break;
		case 12:
			if (isdigit(simbolo))
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
			}
			else
			{
				token.Tipo = LITERALREAL;
				return token;
			}
			break;
		case 13:
			if (simbolo == '"')
			{
                //token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 14;
			}
			else if (simbolo == '\n')
			{
				throw ExcepcionLexica("Se esperaba comillas");
			}
			else
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
			}
			break;
		case 14:
			token.Tipo = LITERALCADENA;
			return token;
		case 15:
			if (simbolo == '>')
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 16;
			}
			else if (simbolo == '-')
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 17;
			}
			else if (simbolo == '=')
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 18;
			}
			else
			{
				token.Tipo = MENOR;
				return token;
			}
			break;
		case 16:
			token.Tipo = DIFERENTE;
			return token;
		case 17:
			token.Tipo = ASIGNACION;
			return token;
		case 18:
			token.Tipo = MENORIGUAL;
			return token;
		case 19:
			if (simbolo == '=')
			{
				token.Lexema += simbolo;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 20;
			}
			else
			{
				token.Tipo = MAYOR;
				return token;
			}
			break;
		case 20:
			token.Tipo = MAYORIGUAL;
			return token;

		case 21:
			if (simbolo == '/')
			{
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 22;
			}
			else if (simbolo == '*')
			{
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 23;
			}
			else
			{
				token.Tipo = DIVISION;
				return token;
			}
			break;
		case 22:
			if (simbolo == '\n')
			{
				token.Lexema = lexemaAnterior;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 4;
			}
			else
			{
				simbolo = ObtenerSiguienteSimbolo();
			}
			break;

		case 23:
			if (simbolo == '*')
			{
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 24;
			}
			else if (simbolo == '\0')
			{
				throw ExcepcionLexica("No se cerro los comentarios");
			}
			else
			{
				simbolo = ObtenerSiguienteSimbolo();
			}
			break;
		case 24:
			if (simbolo == '/')
			{
				token.Lexema = lexemaAnterior;
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 4;
			}
			else if (simbolo == '\0')
			{
				throw ExcepcionLexica("No se cerro los comentarios");
			}
			else
			{
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 23;
			}
			break;
		case 25:
			if (simbolo == '>')
			{
				simbolo = ObtenerSiguienteSimbolo();
				estadoActual = 0;
				modoLpp = false;
			}
			else
			{
				throw ExcepcionLexica("No se cerro el codigo lpp");
			}
		}
	}
}
