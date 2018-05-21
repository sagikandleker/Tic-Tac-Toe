#include "DummyPlayers.h"


const Coordinate XYPlayer::play(const Board& board) {
	for (unsigned int x=0; x<board.size(); ++x) {
		for (unsigned int y=0; y<board.size(); ++y) {
			Coordinate c{(int)x,(int)y};
			if (board[c]=='.') {
				return c;
			}
		}
	}
	return {0,0};  // did not find an empty square - play on the top-left
}


const Coordinate YXPlayer::play(const Board& board) {
	for (unsigned int y=0; y<board.size(); ++y) {
		for (unsigned int x=0; x<board.size(); ++x) {
			Coordinate c{(int)x,(int)y};
			if (board[c]=='.') {
				return c;
			}
		}
	}
	return {0,0};  // did not find an empty square - play on the top-left
}



/**
 * The illegal player tries to put a char on a cell owned by the other player.
 */
const Coordinate IllegalPlayer::play(const Board& board) {
	char charOfOtherPlayer = (
		myChar=='X'? 'O': 'X'
		);
	for (unsigned int y=0; y<board.size(); ++y) {
		for (unsigned int x=0; x<board.size(); ++x) {
			Coordinate c{(int)x,(int)y};
			if (board[c]==charOfOtherPlayer) {
				return c;
			}
		}
	}
	return {0,0};  // did not find an illegal square - play on the top-left
}


const Coordinate ExceptionPlayer::play(const Board& board) {
	throw string("hahaha");
}