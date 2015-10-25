/* 
 * File:   main.cpp
 * Author: erick304
 *
 * Created on July 21, 2015, 8:12 PM
 */

#include <cstdlib>
#include <iostream>
#include "Lexico.h"
#include "ExcepcionLexica.h"
#include <fstream>
#include <string>
#include "Sintactico.h"
#include "tablasimbolos.h"

/*

 * 
 */
std::string get_file_contents(const char* filename)
{
	std::FILE* fp = std::fopen(filename, "rb");
	if (fp)
	{
		std::string contents;
		std::fseek(fp, 0, SEEK_END);
		contents.resize(std::ftell(fp));
		std::rewind(fp);
		std::fread(&contents[0], 1, contents.size(), fp);
		std::fclose(fp);
		return(contents);
	}
}

TablaSimbolos * TablaSimbolos::instancia = NULL;
int main(int argc, char** argv)
{
	try
	{
		string entrada = " ";
        entrada = get_file_contents("C:/Users/erick304/Documents/CompiladorL/lexico.txt");
        TablaSimbolos tablaSimbolos;
		Lexico* lexico = new Lexico(entrada);
        Sintactico* sint = new Sintactico(lexico);
        list<NodoSentencia*>* listaSentencia =sint->Parse();
		cout << "Parse funciona";

        for (list<NodoSentencia*>::iterator it = listaSentencia->begin();it!=listaSentencia->end();++it){

            (*it)->validarSemantica();

        }
        for (list<NodoSentencia*>::iterator it2 = listaSentencia->begin();it2!=listaSentencia->end();++it2){

           (*it2)->interpretar();

        }
	}
	catch (ExcepcionLexica e)
	{
		cout << e.what();
	}

	system("pause");
	return 0;
}
