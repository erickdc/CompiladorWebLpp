/* 
 * File:   Token.h
 * Author: erick304
 *
 * Created on July 21, 2015, 8:13 PM
 */

#ifndef TOKEN_H
#define	TOKEN_H
#include <string>
#include <iostream>
using namespace std;

enum TipoToken
{
	EOFLPP,
	REGISTRO,
	LEER,
	CERRAR,
	ARCHIVO,
	DECLARAR,
	RETORNE,
	VAR,
	CORCHETEI,
	DIFERENTE,
	CORCHETED,
	LITERALENTERO,
	MOD,
	DIV,
	LITERALREAL,
	LITERALCADENA,
	LITERALCARACTER,
	VERDADERO,
	FALSO,
	ENTERO,
	REAL,
	IDLPP,
	INICIO,
	FIN,
	HTML,
	SUMA,
	RESTA,
	MULTIPLICACION,
	PARENTHESISI,
	PARENTHESISD,
	EXPONENTE,
	DIVISION,
	MODULAR,
	DIVISIONENTERA,
	ARREGLO,
	DE,
	ES,
	SECUENCIAL,
	LECTURA,
	ESCRITURA,
	MIENTRAS,
	COMO,
	NO,
	TIPO,
	ABRIR,
	ESCRIBIR,
	Y,
	O,
	CADENA,
	HAGA,
	PARA,
	PROCEDIMIENTO,
	ESCRIBA,
	LLAMAR,
	CARACTER,
	FUNCION,
	BOOLEANO,
	SI,
	MAYORIGUAL,
	MENORIGUAL,
	MAYOR,
	MENOR,
	ENTONCES,
	SINO,
	IGUAL,
	CASO,
	DOSPUNTOS,
	PUNTO,
	COMA,
	ASIGNACION,
	REPITA,
	HASTA
};

class Token
{
public:
	Token();
	TipoToken Tipo;
	string Lexema;
    int Fila;
    int Columna;
	void Imprimir();
	static string ObtenerTipoCorrespondiente(TipoToken tipo);
	void EstablecerLinea(int fila, int columna);
	string ToString();
	std::string IntToString(int number);
	static TipoToken ObtenerTipo(string lexema);
	Token(const Token& orig);
	virtual ~Token();
private:

};

#endif /* TOKEN_H */
