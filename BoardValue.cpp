/*
Student Name: Vaghasiya Dhrumil Arvindbhai
Student ID: 200492148
*/
#include "BoardValue.h"
#include <cassert>

bool isBoardValueValid(char value) {
  if ((value == BOARD_VALUE_EMPTY) || (value == BOARD_VALUE_BLACK) ||
      (value == BOARD_VALUE_WHITE) || (value == BOARD_VALUE_MARKED)) {
    return true;
  }
  return false;
}

bool isBoardValuePlayer(char value_in) {
  if (value_in == BOARD_VALUE_BLACK || value_in == BOARD_VALUE_WHITE) {
    return true;
  }
  return false;
}

char getOtherPlayer(char player_value_in) {
  assert(isBoardValuePlayer(player_value_in));

  if (player_value_in == BOARD_VALUE_BLACK) {
    return BOARD_VALUE_WHITE;
  }
  if (player_value_in == BOARD_VALUE_WHITE) {
    return BOARD_VALUE_BLACK;
  }

  return player_value_in;
}