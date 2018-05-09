#include "CoordinateException.h"

IllegalCoordinateException::IllegalCoordinateException(BoardIndex index)
{
	this->xy = index;
}

BoardIndex IllegalCoordinateException::theCoordinate() const
{
	return this->xy;
}