/* 
 * File:   ExcepcionLexica.h
 * Author: erick304
 *
 * Created on July 27, 2015, 7:28 AM
 */

#ifndef EXCEPCIONSINTACTICA_H
#define	EXCEPCIONSINTACTICA_H
#include <string>

using namespace std;

class ExcepcionSintactica : public std::exception
{
public:
	string Message;

	ExcepcionSintactica(string mensaje):Message(mensaje)
	{
	}

	const char* what() const throw()
	{
		return Message.c_str();
	}

	~ExcepcionSintactica() throw()
	{
	}
};

#endif /* EXCEPCIONLEXICA_H */
