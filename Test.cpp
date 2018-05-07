#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "Board.h"

#include <iostream>
using namespace std;

TEST_CASE("Testing Homework 4") {

    Board board1{3};
    Board board2{3};

    board1[{0,0}] = 'X';
    cout << board1 << endl;
}