#include <iostream>

using namespace std;

class BoardIndex{
    int i;
    int j;

    public:
        BoardIndex();
        BoardIndex(int x, int y);
        int getI();
        int getJ();
};

inline ostream& operator<<(ostream& os, BoardIndex n){
    os << "{";
    os << n.getI() << "," << n.getJ();
    os << "}";
}