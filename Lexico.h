/* 
 * File:   Lexico.h
 * Author: erick304
 *
 * Created on July 27, 2015, 7:03 AM
 */

#ifndef LEXICO_H
#define	LEXICO_H

#include "Token.h"
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Lexico
{
public:
	Lexico(string entrada);
	string entrada;
	string lexemaAnterior = " ";
	int posicion = 0;
	int columna = 0;
	int fila = 0;
	bool modoLpp = false;

	map<string, TipoToken> PalabrasOperadoresReservados;

	void InitListaPalabraReservada();

	bool EsPalabraReservada(TipoToken tipo);
	char ObtenerSimboloActual();
	char ObtenerSiguienteSimbolo();
	TipoToken ObtenerTokenCorrespondiente(std::string token);
	Token ObtenerToken();

	virtual ~Lexico();
private:
};

#endif /* LEXICO_H */
