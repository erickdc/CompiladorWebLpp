#ifndef EXCEPCIONSEMANTICA
#define EXCEPCIONSEMANTICA
#include <string>

using namespace std;

class ExcepcionSemantica : public std::exception
{
public:
    string Message;

    ExcepcionSemantica(string mensaje):Message(mensaje)
    {
    }

    const char* what() const throw()
    {
        return Message.c_str();
    }

    ~ExcepcionSemantica() throw()
    {
    }
};

#endif // EXCEPCIONSEMANTICA

