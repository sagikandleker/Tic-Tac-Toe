#include "Board.h"

//Constructor Functions -
/*Board::Board()
{
	this->n = 1;
	mat = new Node*[n];
	for(int i = 0; i < n ;i++)
	{
		mat[i] = new Node[n];
		for(int j = 0; j < n ;j++)
		{
			mat[i][j] = Node('.');
		}
	}
}*/


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
	/*if(size()>0){
		this->~Board();
	}*/
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

Board& Board::operator=(int value){

	n = value;
	mat = new Node*[n];

	for(int i = 0; i < n ;i++)
	{
		mat[i] = new Node[n];
	}
	return *this;
}

struct RGB {
	uint8_t red, green, blue;
public:
	RGB() {}
	RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

string Board::draw(int val){
	const int dimx = val;
	const int dimy = val;

	int k=1;
	string filename="cpp"+to_string(k)+".ppm";
	//ofstream imageFile(filename, ios::out | ios::binary);
	while(ifstream(filename)){
		filename="cpp"+to_string(++k)+".ppm";
	}
	ofstream imageFile(filename, ios::out | ios::binary);
	imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
	RGB image[dimx*dimy];
	int charsize=val/n;
	for(int i = 0; i < n; i++)
	{


		for(int j = 0; j < val; j++)
		{
			image[charsize*val*i+j].green = (255);
			image[charsize*i+j*val].green = (255);
		}
	}
	for(int f=0;f<n;f++)
	{
		for(int g=0;g<n;g++)
		{
			if(mat[f][g].getSymbol()=='X')
			{
				for(int loc=1;loc<charsize;loc++)
				{
					image[val*charsize*f+val*loc+g*charsize+loc].red = (255);
					image[val*charsize*f+val*loc+g*charsize+loc].green = (0);
					image[val*charsize*f+val*loc+g*charsize+loc].blue = (0);
					image[val*charsize*f+val*loc+charsize+g*charsize-loc].red = (255);
					image[val*charsize*f+val*loc+charsize+g*charsize-loc].green = (0);
					image[val*charsize*f+val*loc+charsize+g*charsize-loc].blue = (0);
				}

			}
			else if(mat[f][g].getSymbol()=='O')
			{
				for(int row=1;row<charsize;row++)
				{
					for(int loc=1;loc<charsize;loc++)
					{
						int rx=charsize/2;
						int ry=charsize/2;
						int dx = (rx- loc) ; // horizontal offset
						int dy = (ry-row); // vertical offset
						if ( (dx*dx + dy*dy) <= (rx*rx))
						{
							image[val*charsize*f+row*val+g*charsize+loc].red = (0);
							image[val*charsize*f+row*val+g*charsize+loc].green = (0);
							image[val*charsize*f+row*val+g*charsize+loc].blue = (128);
						}
					}
				}
			}
		}
	}
	imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
	imageFile.close();
	return filename;
}