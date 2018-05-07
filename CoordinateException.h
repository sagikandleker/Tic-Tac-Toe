
#include <iostream>
#include <exception>
#include <string>

using namespace std;

class IllegalCoordinateException : public exception{
	int a,b;

	public:

		IllegalCoordinateException(int i, int j);
		string theCoordinate() const;

};