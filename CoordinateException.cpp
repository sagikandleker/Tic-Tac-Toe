#include "CoordinateException.h"


string IllegalCoordinateException::theCoordinate() const{
	return to_string(this->a) + "," + to_string(this->b);
}

IllegalCoordinateException::IllegalCoordinateException(int i, int j){
	this->a = i;
	this->b = j;
}