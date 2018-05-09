#include "CharException.h"

IllegalCharException::IllegalCharException(char c)
{
	this->value = c;
}

char IllegalCharException::theChar() const
{
	return this->value;
}