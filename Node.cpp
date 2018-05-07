#include "Node.h"
#include "CharException.h"

Node::Node(){
    this->symbol = '.';
}

Node::Node(char value){
    if(value != 'X' && value != 'O')
	{
		throw IllegalCharException(value);
	}
    
    else
    {
        this->symbol = value;
    }
}


char Node::getSymbol(){
    return this->symbol;
}


void Node::setSymbol(char value){

    this->symbol = value;

}

