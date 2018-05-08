#include "Board.h"

//Constructor Functions -

Board::Board(int value){

	this->size = value;
	mat = new Node*[value];

	for(int i = 0; i < size ;i++)
	{
		mat[i] = new Node[size];
	}
}

Board::Board(const Board& other){

	this->size = other.size;
		mat = new Node*[size];

		for(int i = 0; i < size ;i++)
		{
			mat[i] = new Node[size];

			for(int j = 0; j < size; j++)
			{
				mat[i][j] = other.mat[i][j];
			}
		}
}


int Board::getSize() const{
	return this->size;
}


//Destruction Function -
Board::~Board(){

	for(int i = 0; i < this->size; i++){
		delete[] mat[i];
	}
	delete[] mat;
}


//Operators - 
Node& Board::operator[](list<int> index){

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


Board& Board::operator=(char value){
	{

	if(value != 'X' && value != 'O' && value != '.')
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
}


Board& Board::operator=(const Board& db){
	Board b{db};
	return *this;
}