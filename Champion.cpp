#include "Champion.h"

const Coordinate Champion::play(const Board& board)
{

	Coordinate c{board.size()-1,0};
	if (board[c]=='.') {
		return c;
	}
	c={0,board.size()-1};
	if (board[c]=='.') {
		return c;
	}

	for(int i = 1; i < board.size(); i++){
			c={i,board.size()-1};
			if (board[c]=='.') {
				return c;
		}
	}
	return {0,0};
}
