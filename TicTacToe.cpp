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
        if(fullboard() && w==nullptr){w=&oPlayer; break;}
        tryPlay(xPlayer, oPlayer);
        steps++;
        if(w) break;
        if(steps == (gboard.size())*(gboard.size()))
        {
            w = &oPlayer;
            break;
        } 
        tryPlay(oPlayer, xPlayer);
        steps++;
        if(w) break;
    }
    if(!w) w = &oPlayer;
}