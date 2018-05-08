#include "CoordinateException.h"

IllegalCoordinateException::IllegalCoordinateException(int i, int j){
	this->a = i;
	this->b = j;
}

string IllegalCoordinateException::theCoordinate() const{
	return to_string(this->a) + "," + to_string(this->b);
}