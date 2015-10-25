/* 
 * File:   ExcepcionLexica.h
 * Author: erick304
 *
 * Created on July 27, 2015, 7:28 AM
 */

#ifndef EXCEPCIONLEXICA_H
#define	EXCEPCIONLEXICA_H
#include <string>

using namespace std;

class ExcepcionLexica : public std::exception
{
public:
	string Message;

	ExcepcionLexica(string mensaje):Message(mensaje)
	{
	}

	const char* what() const throw()
	{
		return Message.c_str();
	}

	~ExcepcionLexica() throw()
	{
	}
};

#endif /* EXCEPCIONLEXICA_H */
