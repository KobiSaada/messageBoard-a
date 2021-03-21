#include <iostream>
#include <array>
#include "Board.hpp"
#include <stdexcept>
#include <regex>



using namespace std;
namespace ariel {

   void Board::cleanBoard(){
       for(int i=0;i<this->row;i++){
      for(int j=0 ;j<this->col;j++){
         this->board[i][j]='_';
   }
       }
   }
 
void Board::initBoard(int rows,  int columns){// init the board with resize function
    this->row = rows;
    this->col = columns;
    this->board.resize(rows);
    for ( int i = 0; i < rows; i++)
    {

        this->board[i].resize(columns,'_');
         
      //  for(unsigned int j =0;j<columns;j++){
      //    this->mat[i][j]='_';
       // d=Direction::Horizontal;
      ///  }
        
    
  }
}
   

void Board::post(int rowH,int colV,Direction d,string advertisement ){//post a message on the board
   int size=advertisement.size();
   switch (d){
      case Direction::Vertical:
      initBoard(max(this->row+size+1,rowH+1+size),max(this->col+size+1,colV+size+1));
      for(int i=0;i<size;i++){
         this->board[rowH][colV]=advertisement[i];
        
         rowH++;
         
        

      }
      break;
      case Direction::Horizontal:
        initBoard(max(this->row+size+1,rowH+size+1),max(this->col+size+1,colV+1+size));
      for(int i=0;i<size;i++){
         this->board[rowH][colV]=advertisement[i];
        
        colV++;
        


   }
   break;
   }


}
string Board::read( int h,int v,Direction d,int n){//read a message from the board
   string ans;
   try{
   switch(d){
      case Direction::Horizontal:
   for(int i =0;i<n;i++){
      ans+=this->board[h][v];
      v++;
     

   }
    break;
   case Direction::Vertical:
      for(int i =0;i<n;i++){
      ans+=this->board[h][v];
      h++;
      
      
      }
      break;
   }
   }
      catch(exception &e){
      cout<<"error"<<endl;
      }
   
   
return ans;
   
}
void Board:: show(){//show the board 
   cout<<"The Board:"<<endl;
   for(int i=0;i<this->row;i++){
      cout<<"row";
           cout<<i;
           cout<<":";
      for(int j=0 ;j<this->col;j++){
        if(this->board[i][j]!='_'){
           
          cout<<"| ";
          cout<<this->board[i][j];
          cout<< " |";

   }
         if(j+1==this->col){
         cout<<endl;
         }
      
      }
         

   }
   

}

}


   
    
    

    

