#include "TicTacToe.h"

void TicTacToe::play(Player& xPlayer, Player& oPlayer)
{
    w = nullptr;
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    gboard = '.';
    int steps = 0;

    while(1)
    {
        tryPlay(xPlayer, oPlayer);
        if(w) break;
        if(steps == gboard.size())
        {
            w = &oPlayer;
            break;
        } 
        tryPlay(oPlayer, xPlayer);
        if(w) break;
    }
}