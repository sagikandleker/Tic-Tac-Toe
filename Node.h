#pragma once
#include <iostream>

using namespace std;

class Node{



public:
    char symbol;
    Node();
    Node(char c);

    //char getSymbol() const;
    //void setSymbol(char value);

    operator char();
    
    char operator=(Node& n);
    Node& operator=(char value);
    Node& operator=(int value);
    Node& operator=(const Node& n);

    friend ostream& operator<<(ostream& os, Node n);
    friend bool operator==(const Node n, const char value);
};

inline ostream& operator<<(ostream& os, Node n)
{
    return os << n.symbol;
}

inline bool operator==(const Node n, const char value)
{
    return n.symbol == value;
}