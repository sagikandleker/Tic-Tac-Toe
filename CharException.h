#pragma once
#include <iostream>
#include <exception>

using namespace std;

class IllegalCharException : public exception
{
	char value;

	public:
		IllegalCharException(char c);
		char theChar() const;

};