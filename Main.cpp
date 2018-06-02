#include "Board.h"

int main(){
	
	Board board;
	cin >> board;
	string filename = board.draw(1200);
	cout << filename << endl;

return 0;

}