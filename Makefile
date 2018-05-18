CXX=g++
CXXFLAGS=-std=c++17

all: Board.o BoardIndex.o BoardNode.o CharException.o CoordinateException.o Player.o DummyPlayers.o TicTacToe.o Champion.o

run: Main.o Board.o BoardIndex.o BoardNode.o CharException.o CoordinateException.o  Player.o DummyPlayers.o TicTacToe.o Champion.o
	$(CXX) $(CXXFLAGS) Main.o Board.o BoardIndex.o BoardNode.o CharException.o CoordinateException.o  Player.o DummyPlayers.o TicTacToe.o Champion.o
	./a.exe

Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c Main.cpp -o Main.o

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

BoardIndex.o: BoardIndex.cpp BoardIndex.h
	$(CXX) $(CXXFLAGS) -c BoardIndex.cpp -o BoardIndex.o

BoardNode.o: BoardNode.cpp BoardNode.h
	$(CXX) $(CXXFLAGS) -c BoardNode.cpp -o BoardNode.o

CharException.o: CharException.cpp CharException.h
	$(CXX) $(CXXFLAGS) -c CharException.cpp -o CharException.o

CoordinateException.o: CoordinateException.cpp CoordinateException.h
	$(CXX) $(CXXFLAGS) -c CoordinateException.cpp -o CoordinateException.o

Player.o: Player.cpp Player.h
	$(CXX) $(CXXFLAGS) -c Player.cpp -o Player.o

DummyPlayers.o: DummyPlayers.cpp DummyPlayers.h
	$(CXX) $(CXXFLAGS) -c DummyPlayers.cpp -o DummyPlayers.o

TicTacToe.o: TicTacToe.cpp TicTacToe.h
	$(CXX) $(CXXFLAGS) -c TicTacToe.cpp -o TicTacToe.o

Champion.o: Champion.cpp Champion.h
	$(CXX) $(CXXFLAGS) -c Champion.cpp -o Champion.o

clean:
	rm *.o a.out

test: Board.o BoardIndex.o BoardNode.o CharException.o CoordinateException.o DummyPlayers.o Player.o TicTacToe.o Champion.o
	$(CXX) $(CXXFLAGS) Test.cpp -g Board.o BoardIndex.o BoardNode.o CharException.o CoordinateException.o DummyPlayers.o Player.o TicTacToe.o Champion.o -o Test.o
	./Test.o