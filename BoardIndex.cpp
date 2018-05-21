#include "BoardIndex.h"

BoardIndex::BoardIndex(){
    this->i = 0;
    this->j = 0;
}

BoardIndex::BoardIndex(unsigned int x, unsigned int y){
    this->i = x;
    this->j = y;
}

unsigned int BoardIndex::getI(){
    return this->i;
}

unsigned int BoardIndex::getJ(){
    return this->j;
}

BoardIndex::BoardIndex(const BoardIndex& other)
{
    i = other.i;
    j = other.j;
}

BoardIndex& BoardIndex::operator=(const BoardIndex& index)
{
    i = index.i;
    j = index.j;
    return *this;
}