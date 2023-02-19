/*
Student Name: Vaghasiya Dhrumil Arvindbhai
Student ID: 200492148
*/
#pragma once
#include "BoardSize.h"
#include <iostream>
using namespace std;

const int STAR_POINT_SPACING = 6;  

struct StonesRemoved {
  int us;
  int them;
};

class Board {
  private:
    char places[BOARD_SIZE][BOARD_SIZE];
    bool isAlignedForStarPoint (int index_in) const;
    void printRowNumber (int row_in) const;
    void printColumnLetters () const;
    int  capturePlayer (char player_value_in);
    bool isInvariantTrue () const; //New

  public:
    Board(); //Was named clear;
    char getAt(int row_in, int column_in) const;
    void print() const;
    int  countWithValue(char value_in) const;
    int calculateScore (char us_value_in) const;
    void setAt (int row_in, int column_in, char value_in);
    void load (const std::string& filename_in);
    StonesRemoved playStone (int row_in, int column_in, char us_value_in);
    void replaceAll (char old_value_in, char new_value_in);
    void fillConnected (char old_value_in, char new_value_in, char neighbour_value_in);
    bool isANeighbourWithValue (int row_in, int column_in, char value_in) const;
};



