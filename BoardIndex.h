#pragma once
#include <iostream>

using namespace std;

class BoardIndex
{
    public:
        int i;
        int j;
        BoardIndex();
        BoardIndex(int x, int y);
        int getI();
        int getJ();

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