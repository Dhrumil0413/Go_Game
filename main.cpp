/*
Student Name: Vaghasiya Dhrumil Arvindbhai
Student ID: 200492148
*/

#include "BoardSize.h"
#include "PlaceString.h"
#include "Search.h"
#include "Board.h"
#include "BoardValue.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
  cout << "Welcom to my Go game!" << endl;
  string name;
  cout << "Enter your name: ";
  getline(cin, name);
  cout << "Hello " << name << " You will play black." << endl;

  //This block defines Board from Board Module;
  Board Board;

  //This block initiates variables needed to run loop, take input and compare strings;
  bool go_on = true;
  int row_num, column_num;
  string input;
  string quit = "quit", pass = "pass";

  //This block intitiates varibles to compare move, store move, and count them;
  string Pert_move = "K9";
  string Moves[1000];
  int Moves_Made = 0;
  float Black_Score = 0, White_Score = 0;
  const float KOMI_POINTS = 7.5;

  //Printing the Board
  cout << endl;
  Board.print();
  cout << endl;

  while (go_on) {

    cout << "Enter your move:  ";
    getline(cin, input);

    if (quit.compare(input) == 0) {
      go_on = false;
    } 
    else if (pass.compare(input) == 0) {
      cout << "Black Pass" << endl;
      cout << "White Pass" << endl;
    } 
    else if (isPlaceStringWellFormed(input)) {
  
      row_num = placeStringToRow(input);
      column_num = placeStringToColumn(input);
      
      if (isOnBoard(row_num, column_num)) {
        //Outputs number of rows and columns players has made moves on.
        if (Board.getAt(row_num, column_num) == BOARD_VALUE_EMPTY){
          Board.setAt(row_num, column_num, BOARD_VALUE_BLACK);
          cout << "Black played a stone at row " << row_num << " ,column "
             << column_num << endl;
          cout << "White Passed" << endl;
          //Stores input into an Array and increses Countable moves.
          Moves[Moves_Made] = input;
          Moves_Made++;
        }
        else {
          cout << "Forbidden: Place row " << row_num << " ,column " << column_num << " is not empty" << endl;
        }
      } 
      else {
        cout << "Forbidden: Place row  " << row_num << " ,column "
             << column_num << " is outside board" << endl;
      }
    } 
    else {
      cout << input << " is ill-formed" << endl;
    }

    cout << endl;
    Board.print();
    cout << endl;
  }

  Black_Score = Moves_Made;
  White_Score = KOMI_POINTS;

  if (White_Score > Black_Score){
    cout << "White wins " << White_Score << " to " << Black_Score << " (with komi)" << endl;
  }
  else {
    cout << "Black Wins " << Black_Score << " to " << White_Score << " (without komi)" << endl;
  }

  if (Moves_Made > 0) {
    
    mySort(Moves, Moves_Made);
    cout << endl;
    int smallest_int = sortedFindSmallest (Moves, Moves_Made);
    int largest_int = sortedFindLargest (Moves, Moves_Made);
    cout << "Black Played " << Moves_Made << " stones total" << endl;
    cout << "Smallest place was \"" << Moves[smallest_int] << "\" (index " << smallest_int << ")" << endl;
    cout << "Largeset place was \"" << Moves[largest_int] << "\" (index " << largest_int << ")" << endl;
    
    if (binarySearch(Moves, Moves_Made, Pert_move) != VALUE_NOT_FOUND) {
      cout << "Did play at \"" << Pert_move << "\""<< endl;
    } 
    else {
      cout << "Did not play at \"" << Pert_move << "\""<< endl;
    }
  }

  cout << "Goodbye, " << name << "!" << endl;
}