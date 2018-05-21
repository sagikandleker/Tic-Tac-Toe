#pragma once
#include "Board.h"
#include "BoardIndex.h"

using Coordinate = BoardIndex;

class Player{

public:
char myChar;
    void setChar(char c)
    {
        myChar = c;
    }
    
    char getChar() const
    {
        return myChar;
    }

    virtual const std::string name() const;
    virtual const Coordinate play(const Board& board);

    virtual ~Player(){}
};

