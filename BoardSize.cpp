/*
Student Name: Vaghasiya Dhrumil Arvindbhai
Student ID: 200492148
*/
#include "BoardSize.h"

bool isOnBoard(int row_in, int column_in)
{
  if ((row_in >= 0 && row_in < BOARD_SIZE) && (column_in >= 0 && column_in < BOARD_SIZE)){
    return true;
  }
  return false;
}