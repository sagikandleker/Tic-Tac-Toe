#include <iostream>

using namespace std;

class Node{

char symbol;

public:
    Node();
    Node(char c);

    char getSymbol();
    void setSymbol(char value);

    operator char();
    
    char operator=(Node& n);
    Node& operator=(char value);
    Node& operator=(int value);
    Node& operator=(const Node& n);


};

inline ostream& operator<<(ostream& os, Node n){
    return os << n.getSymbol();
}