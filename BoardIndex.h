#pragma once
#include <iostream>

using namespace std;

class BoardIndex
{
    public:
        unsigned int i;
        unsigned int j;
        BoardIndex();
        BoardIndex(unsigned int x, unsigned int y);
        unsigned int getI();
        unsigned int getJ();

        BoardIndex(const BoardIndex& other);
        BoardIndex& operator=(const BoardIndex& index);

        friend ostream& operator<<(ostream& os, BoardIndex n);
};

inline ostream& operator<<(ostream& os, BoardIndex n){
    os << "{";
    os << n.i << "," << n.j;
    os << "}";
    return os;
}