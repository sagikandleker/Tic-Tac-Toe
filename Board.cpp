#include "Board.h"

//Constructor Functions -

Board::Board(int value){

	this->size = value;
	mat = new Node*[value];

	for(int i = 0; i < value ;i++)
	{
		mat[i] = new Node[value];
	}

	for(int i = 0; i < value; i++)
	{
		for(int j = 0; j < value; j++)
		{
			mat[i][j] = '.';
		}
	}
}

Board::Board(const Board& other){

	this->size = other.size;
		mat = new Node*[size];

		for(int i = 0; i < size ;i++)
		{
			mat[i] = new Node[size];
		}

		for(int i = 0; i < size; i++)
		{
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

	if(a < size && a >= 0 && b < size && b >= 0)
	{
		return this->mat[a][b];
	}

	else
	{
		throw IllegalCoordinateException(a,b);
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