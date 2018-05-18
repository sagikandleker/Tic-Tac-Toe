#pragma once
#include <iostream>
#include <list>
#include <string>

#include "BoardNode.h"
#include "CoordinateException.h"
#include "CharException.h"
#include "BoardIndex.h"
using Coordinate = BoardIndex;

using namespace std;

class Board{

public:
    
	Node **mat;
	int n;

	Board(int value);
	Board(const Board& other);
	~Board();

	int size() const;

	Node& operator[](list<int> index);
	Node& operator[](const BoardIndex& coor) const;
	Board& operator=(char value);
	Board& operator=(const Board& db);

	friend ostream& operator<<(ostream& os, Board const &b);
	friend bool operator==(const Board& b1, const Board& b2);

};

inline ostream& operator<<(ostream& os, Board const &b) {

	int n = b.size();
	string s = "";

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			s+=b.mat[i][j];
		}
		s+="\n";
	}

	return os << s;
}


inline bool operator==(const Board& b1, const Board& b2){

	if(b1.size() != b2.size()){
		return false;
	}
	else
	{
		for(int i = 0; i < b1.size(); i++){
			for(int j = 0; j < b1.size(); j++){
				if(b1.mat[i][j].getSymbol() != b2.mat[i][j].getSymbol()){
					return false;
				}
				
			}
		}
		return true;
	}
}