#pragma once
#include <iostream>
#include <list>

#include "Node.h"
#include "CoordinateException.h"
#include "CharException.h"

using namespace std;


class Board{

int size;

public:
    
	Node **mat;


	Board(int value);
	Board(const Board& b);
	~Board();

	int getSize() const;

	Node& operator[](list<int> index);
	Board& operator=(char value);

	Board& operator=(const Board& db);

	friend ostream& operator<<(ostream& os, Board const &b);
	friend int operator==(Node& n, char value);
};

inline ostream& operator<<(ostream& os, Board const &b) {

	int n = b.getSize();

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << b.mat[i][j];
		}
		cout << "\n";
	}
	return os;
}

inline int operator==(Node& n, char value){

	if(n.getSymbol() == value)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

