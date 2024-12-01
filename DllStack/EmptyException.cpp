#include "EmptyException.h"

EmptyException::EmptyException(string msg)
{
    this->msg = "\n\nEmptyException : " + msg;
}


string EmptyException::what()
{
    return this->msg;
}
