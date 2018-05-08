#pragma once
#include <iostream>
#include <list>

#include "Node.h"
#include "CoordinateException.h"
#include "CharException.h"
#include "BoardIndex.h"

using namespace std;

class Board{

int size;

public:
    
	Node **mat;

	Board(int value);
	Board(const Board& b);
	~Board();

	int getSize() const;

	Node& operator[](BoardIndex& index);
	Node& operator[](list<int> index);
	Board& operator=(char value);

	Board& operator=(const Board& db);

	friend ostream& operator<<(ostream& os, Board const &b);
	friend bool operator==(const Node& n, char value);
	friend bool operator==(const Board& b1, const Board& b2);

};

inline ostream& operator<<(ostream& os, Board const &b) {

	int n = b.getSize();
	string s="";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			s+=b.mat[i][j];
		}
		 s+="\n";
	}
		
	return os<<s;
}

inline bool operator==(const Node& n, char value){

	if(n.getSymbol() == value){
		return true;
	}
	return false;
}

inline bool operator==(const Board& b1, const Board& b2){

	if(b1.getSize() != b2.getSize()){
		return false;
	}
	else
	{
		for(int i = 0; i < b1.getSize(); i++){
			for(int j = 0; j < b1.getSize(); j++){
				if(b1.mat[i][j].getSymbol() != b2.mat[i][j].getSymbol()){
					return false;
				}
				
			}
		}
	}
	return true;
}
