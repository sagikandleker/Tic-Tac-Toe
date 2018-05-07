CXX=g++
CXXFLAGS=-std=c++17

all: Main.o Board.o BoardIndex.o Node.o CharException.o CoordinateException.o
	$(CXX) $(CXXFLAGS) Main.o Board.o BoardIndex.o Node.o CharException.o CoordinateException.o
	./a.exe

Main.o: Main.o
	$(CXX) $(CXXFLAGS) -c Main.cpp -o Main.o

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

BoardIndex.o: BoardIndex.cpp BoardIndex.h
	$(CXX) $(CXXFLAGS) -c BoardIndex.cpp -o BoardIndex.o

Node.o: Node.cpp Node.h
	$(CXX) $(CXXFLAGS) -c Node.cpp -o Node.o

CharException.o: CharException.cpp CharException.h
	$(CXX) $(CXXFLAGS) -c CharException.cpp -o CharException.o

CoordinateException.o: CoordinateException.cpp CoordinateException.h
	$(CXX) $(CXXFLAGS) -c CoordinateException.cpp -o CoordinateException.o

clean:
	rm *.o a.out

test:
	$(CXX) $(CXXFLAGS) Test.cpp -g Board.o BoardIndex.o Node.o CharException.o CoordinateException.o -o Test.o
	./Test.o