#include "Board.h"

//Constructor Functions -

Board::Board(int value)
{
	this->size = value;
	mat = new Node*[value];

	for(int i = 0; i < size ;i++)
	{
		mat[i] = new Node[size];
	}
}

Board::Board(const Board& other)
{
	this->size = other.getSize();
	mat = new Node*[size];

	for(int i = 0; i < size ;i++)
	{
		mat[i] = new Node[size];
	}
	for(int i = 0; i < size ;i++)
	{
		for(int j = 0; j < size; j++)
		{
			mat[i][j] = other.mat[i][j];
		}
	}	
}

int Board::getSize() const
{
	return this->size;
}

Board::~Board()
{
	for(int i = 0; i < this->size; i++){
		delete[] mat[i];
	}
	delete[] mat;
}

Node& Board::operator[](list<int> index)
{
	int a = index.front();
	int b = index.back();

	BoardIndex bIndex(a,b);

	if(bIndex.i < size && bIndex.i >= 0 && bIndex.j < size && bIndex.j >= 0)
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

	if(bIndex.i < size && bIndex.i >= 0 && bIndex.j < size && bIndex.j >= 0)
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
		for(int i = 0; i < this->size; i++){
			for(int j = 0; j < this->size; j++){
				this->mat[i][j].setSymbol(value);
			}
		}

	}
	return *this;
}

Board& Board::operator=(const Board& db)
{
	this->~Board();
	
	this->size = db.size;
	mat = new Node*[size];

	for(int i = 0; i < size ;i++)
	{
		mat[i] = new Node[size];
	}

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			mat[i][j].setSymbol(db.mat[i][j].getSymbol());
		}
	}
	return *this;
}