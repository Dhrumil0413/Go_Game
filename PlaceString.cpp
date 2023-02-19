/*
Student Name: Vaghasiya Dhrumil Arvindbhai
Student ID: 200492148
*/
#include "PlaceString.h"

int stringToInteger(const string &input) {
  int j = 0;
  int len = input.length();
  if (len == 0) {
    j = INVALID_COORDINATE;
    return j;
  }

  for (int i = 0; i < len; i++) {
    if (input[i] < 48 || input[i] > 57) {
      j = INVALID_COORDINATE;
      break;
    }
    j = (j * 10) + (input[i] - '0');
  }
  return j;
}

int placeStringToRow(const string &input) {
  int row_num;
  if (input.length() == 0) {
    return INVALID_COORDINATE;
  } 
  else {
    row_num = stringToInteger(input.substr(1));
    return row_num;
  }
}

int placeStringToColumn(const string &input) {
  int col_num;
  if ((input.length() == 0) || (input[0] < 'A' || input[0] > 'Z') ||
      (input[0] == 'I') || (input[0] == 'O')) {
    return INVALID_COORDINATE;
  } else {
    if (input[0] > 'I' && input[0] < 'O') {
      col_num = (input[0] - 'A') - 1;
    } else if (input[0] > 'O') {
      col_num = (input[0] - 'A') - 2;
    } else {
      col_num = (input[0] - 'A');
    }
  }
  return col_num;
}

bool isPlaceStringWellFormed(const string &input) {
  if (placeStringToRow(input) == -1 || placeStringToColumn(input) == -1) {
    return false;
  }
  return true;
}