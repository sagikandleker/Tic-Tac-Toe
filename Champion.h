#pragma once
#include "Player.h"

class Champion : public Player {

public:
    const string name() const override
    {
        return "Itay, Sagi & Roni";
    }

    const Coordinate play(const Board& board) override;

};
