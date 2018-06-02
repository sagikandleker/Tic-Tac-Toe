#include "Board.h"

int main(){
	
	Board board;
	cin >> board;
	string filename = board.draw(600);
	cout << filename << endl;

return 0;

}