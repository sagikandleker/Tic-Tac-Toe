#pragma once
#include "BoardIndex.h"
#include <exception>

class IllegalCoordinateException : public exception
{
	BoardIndex xy;

	public:
		IllegalCoordinateException(BoardIndex index);
		BoardIndex theCoordinate() const;
};