#include "FullException.h"


FullException::FullException(string msg)
{
    this->msg = "\n\nFullException : " + msg;
}

string FullException::what()
{
    return this->msg;
}
