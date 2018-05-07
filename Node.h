#include <iostream>

using namespace std;

class Node{

char symbol;

public:
    Node();
    Node(char c);

    char getSymbol();
    void setSymbol(char value);



};

inline ostream& operator<<(ostream& os, Node n){
    return os << n.getSymbol();
}