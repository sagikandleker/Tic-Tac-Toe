#include "Board.h"

//Constructor Functions -

Board::Board(int value)
{
	this->n = value;
	mat = new Node*[value];

	for(int i = 0; i < n ;i++)
	{
		mat[i] = new Node[n];
	}
}

Board::Board(const Board& other)
{
	this->n = other.size();
	mat = new Node*[n];

	for(int i = 0; i < n ;i++)
	{
		mat[i] = new Node[n];
	}
	for(int i = 0; i < n ;i++)
	{
		for(int j = 0; j < n; j++)
		{
			mat[i][j] = other.mat[i][j];
		}
	}	
}

int Board::size() const
{
	return this->n;
}

Board::~Board()
{
	for(int i = 0; i < this->n; i++){
		delete[] mat[i];
	}
	delete[] mat;
}

Node& Board::operator[](list<int> index)
{
	int a = index.front();
	int b = index.back();

	BoardIndex bIndex(a,b);

	if(bIndex.i < n && bIndex.i >= 0 && bIndex.j < n && bIndex.j >= 0)
	{
		return mat[bIndex.i][bIndex.j];
	}

	else
	{
		throw IllegalCoordinateException(bIndex);
	}
}

Node& Board::operator[](const BoardIndex& coor) const
{
	int a = coor.i;
	int b = coor.j;

	BoardIndex bIndex(a,b);

	if(bIndex.i < n && bIndex.i >= 0 && bIndex.j < n && bIndex.j >= 0)
	{
		return mat[bIndex.i][bIndex.j];
	}

	else
	{
		throw IllegalCoordinateException(bIndex);
	}
}
Board& Board::operator=(char value)
{
	if(value != '.' && value != 'X' && value != 'O')
	{
		throw IllegalCharException(value);
	}
	else
	{
		for(int i = 0; i < this->n; i++){
			for(int j = 0; j < this->n; j++){
				this->mat[i][j].setSymbol(value);
			}
		}

	}
	return *this;
}

Board& Board::operator=(const Board& db)
{
	this->~Board();
	
	this->n = db.n;
	mat = new Node*[n];

	for(int i = 0; i < n ;i++)
	{
		mat[i] = new Node[n];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			mat[i][j].setSymbol(db.mat[i][j].getSymbol());
		}
	}
	return *this;
}