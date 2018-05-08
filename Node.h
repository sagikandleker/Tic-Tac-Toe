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
    
    char operator=(Node& n);
    Node& operator=(char value);
    Node& operator=(int value);
    Node& operator=(const Node& n);

    friend ostream& operator<<(ostream& os, Node n);
    friend bool operator==(const Node n, const char c);
};

inline ostream& operator<<(ostream& os, Node n){
    return os << n.getSymbol();
}
inline bool operator==(const Node n, const char c){
	if(n.getSymbol() == c)return true;
	return false;
}
