#include "Node.h"
#include "CharException.h"

Node::Node(){
    this->symbol = '.';
}

Node::Node(char value){
    this->symbol = value;
}


/*char Node::getSymbol() const{
    return this->symbol;
}


void Node::setSymbol(char value){

    this->symbol = value;

}*/

Node::operator char(){
    return this->symbol;
}

/*
char Node::operator=(Node& n){
    return n.symbol;
}*/

Node& Node::operator=(char value){
    if(value != 'X' && value != 'O' && value != '.')
	{
		throw IllegalCharException(value);
	}
    else
    {
        this->symbol = value;
    }
    return *this;
}


/*Node& Node::operator=(int value){
    if(value != 88 && value != 79)
	{
		throw IllegalCharException(value);
	}
    else
    {
        this->symbol = value;
    }
    return *this;
}*/

Node& Node::operator=(const Node& n){
    this->symbol = n.symbol;
    return *this;
}