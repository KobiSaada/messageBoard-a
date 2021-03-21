#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

string no__(string input) {
     std::erase(input, '_');
	 return input;
     
  }

TEST_CASE("good board"){
	ariel::Board board;
	board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
	CHECK(no__(board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3)) ==string("b"));  
		// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	board.post(/*row=*/99, /*column=*/202, Direction::Vertical, "xyz");
	CHECK(no__(board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6)) =="abyd");  
	
	// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).


	board.post(/*row=*/0, /*column=*/0, Direction::Horizontal, "dd");
	CHECK(no__(board.read(/*row=*/0, /*column=*/1, Direction::Vertical, /*length=*/3)) ==string("d"));  

		board.post(/*row=*/3, /*column=*/4, Direction::Horizontal, "kob");
	CHECK(no__(board.read(/*row=*/3, /*column=*/4, Direction::Vertical, /*length=*/2)) ==string("k"));  
	
	board.post(/*row=*/2, /*column=*/2, Direction::Vertical, "kobi");
	CHECK(no__(board.read(/*row=*/2, /*column=*/2, Direction::Vertical, /*length=*/4)) ==string("kobi"));  
	
	board.post(/*row=*/7, /*column=*/8, Direction::Horizontal, "kobi");
	CHECK(no__(board.read(/*row=*/7, /*column=*/7, Direction::Horizontal, /*length=*/3)) ==string("ko"));  
	
	board.post(/*row=*/10, /*column=*/0, Direction::Horizontal, "murphysP");
	CHECK(no__(board.read(/*row=*/7, /*column=*/7, Direction::Vertical, /*length=*/6)) ==string("P"));  
	
	board.post(/*row=*/11, /*column=*/0, Direction::Vertical, "murphysP");
	CHECK(no__(board.read(/*row=*/11, /*column=*/0, Direction::Horizontal, /*length=*/2)) ==string("m"));  
	
	
	board.post(/*row=*/23, /*column=*/1, Direction::Vertical, "netanya");
	CHECK(no__(board.read(/*row=*/23, /*column=*/1, Direction::Horizontal, /*length=*/2)) ==string("n"));  
	//board.cleanBoard();
	//board.post(0,0,Direction::Horizontal,"bp");
	
	
	
	

	board.show(); // shows the board in a reasonable way. For example:
		//    98:  _________
		//    99:  ____x____
		//    100: __abyd___
		//    101: ____z____
		//    102: _________


}
