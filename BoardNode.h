#pragma once
#include <iostream>

using namespace std;

class Node{
char symbol;
public:
    
    Node();
    Node(char c);

    char getSymbol() const;
    void setSymbol(char value);
    
    operator char();

    Node& operator=(char value);
    Node& operator=(const Node& n);

    friend ostream& operator<<(ostream& os, Node& n);
    friend bool operator==(const Node n, const char value);
};

inline ostream& operator<<(ostream& os, Node& n)
{
    os << n.getSymbol();
    return os;
}

inline bool operator==(const Node n, const char value)
{
    return n.getSymbol() == value;
}