
//#include "doctest.h"
#include "Direction.hpp"
/*#include <array>
#include <stdexcept>

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
*/
#include <regex>
#include <vector>
#include <string>
using namespace std;


namespace ariel {
	// Defines a class
class Board{
 public:
    int row;
    int col;
    Direction d;
    vector<vector<char>> board;
  //  int matrix[][];
  public:
  Board(){
    this->board=vector<vector<char>>(2,vector<char>(2,'_'));
    this->row=2;
    this->col=2;
  }

~Board(){}//destructor 
void show();
void post(int rowH,int colV,Direction d,string advertisement );
string read(int h,int v,Direction,int n);
void initBoard(int rows, int columns);
void cleanBoard();

};
}


