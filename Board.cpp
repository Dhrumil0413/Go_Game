/*
Student Name: Vaghasiya Dhrumil Arvindbhai
Student ID: 200492148
*/
#include "Board.h"
#include "BoardSize.h"
#include "BoardValue.h"
#include <cassert>
#include <fstream>
#include <iomanip>
using namespace std;

// Constructor
Board::Board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      places[i][j] = BOARD_VALUE_EMPTY;
    }
  }
}

// Implementation of Private Functions;
bool Board::isAlignedForStarPoint(int index_in) const {
  assert(index_in >= 0);
  if ((index_in % STAR_POINT_SPACING) ==
      ((BOARD_SIZE / 2) % STAR_POINT_SPACING)) {
    return true;
  }
  return false;
}

void Board::printRowNumber(int row_in) const { 
  cout << setw(2) << row_in;
}

void Board::printColumnLetters() const {
  char printChar = 'A';

  cout << "  ";
  for (int i = 'A'; i <= 'U'; i++) {
    if (printChar == 'I' || printChar == 'O') {
      printChar++;
      continue;
    }
    cout << setw(2) << printChar;
    printChar++;
  }
}

int Board::capturePlayer(char player_value_in) {
  assert(isBoardValuePlayer(player_value_in));

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (places[i][j] == player_value_in) {
        places[i][j] = BOARD_VALUE_MARKED;
      }
    }
  }

  fillConnected(BOARD_VALUE_MARKED, player_value_in, BOARD_VALUE_EMPTY);

  int Score_count = 0;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (places[i][j] == BOARD_VALUE_MARKED) {
        Score_count++;
        places[i][j] = BOARD_VALUE_EMPTY;
      }
    }
  }

  return Score_count;
}

bool Board::isInvariantTrue() const {
  char value;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      value = places[i][j];
      if (!isBoardValueValid(value)) {
        return false;
      }
    }
  }
  return true;
} // New Function to test if every value on the board is valid or not;

// Implementation of public functoins;

char Board::getAt(int row_in, int column_in) const {
  assert(isInvariantTrue());
  assert(isOnBoard(row_in, column_in));

  return places[row_in][column_in];
}

void Board::print() const {
  assert(isInvariantTrue());

  printColumnLetters();
  cout << endl;
  for (int i = 0; i < BOARD_SIZE; i++) {
    printRowNumber(i);
    cout << setw(2);
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (isAlignedForStarPoint(i) && isAlignedForStarPoint(j)) {
        if (places[i][j] == BOARD_VALUE_EMPTY) {
          cout << "*"
               << " ";
        } else {
          cout << places[i][j] << " ";
        }

      } else {
        cout << places[i][j] << " ";
      }
    }
    printRowNumber(i);
    cout << endl;
  }
  printColumnLetters();
  cout << endl;
}

int Board::countWithValue(char value_in) const {
  assert(isInvariantTrue());
  assert(isBoardValueValid(value_in));

  int value_count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (places[i][j] == value_in) {
        value_count++;
      }
    }
  }
  return value_count;
}

int Board::calculateScore(char us_value_in) const {
  assert(isInvariantTrue());
  assert(isBoardValuePlayer(us_value_in));

  char OTHER_PLAYER_VALUE = getOtherPlayer(us_value_in);
  Board copy = *this;

  copy.fillConnected(BOARD_VALUE_EMPTY, OTHER_PLAYER_VALUE, OTHER_PLAYER_VALUE);
  copy.fillConnected(BOARD_VALUE_EMPTY, us_value_in, us_value_in);

  int Us_Score = copy.countWithValue(us_value_in);

  return Us_Score;
}

void Board::setAt(int row_in, int column_in, char value_in) {
  assert(isInvariantTrue());
  assert(isOnBoard(row_in, column_in));
  assert(isBoardValueValid(value_in));

  places[row_in][column_in] = value_in;
}

void Board::load(const string &filename_in) {
  assert(filename_in != "");

  // open file with name filename_in
  // fin will read from that file
  // use fin like you use cin
  ifstream fin(filename_in);

  if (!fin) {
    cout << "Error: Could not open file \"" << filename_in << "\"" << endl;
    return; // end function immediately
  }

  // read in the board size
  string line;
  int board_size_read;
  fin >> board_size_read;
  if (!fin) {
    cout << "Error: File \"" << filename_in
         << "\" does not start with board size" << endl;
    return; // end function immediately
  }
  if (board_size_read != BOARD_SIZE) {
    cout << "Error: File \"" << filename_in << "\" has board size "
         << board_size_read << ", but must be " << BOARD_SIZE << endl;
    return; // end function immediately
  }
  assert(fin);
  string dummy;
  getline(fin, dummy); // throw away whatever else is on the line

  // read in board state
  bool is_print_error = true;
  for (int r = 0; r < BOARD_SIZE; r++) {
    string line;
    getline(fin, line);
    if (!fin) {
      if (is_print_error) {
        cout << "Error: Could not read line " << r << " of file \""
             << filename_in << "\"" << endl;
        cout << "       Replacing with '.'s" << endl;
        is_print_error = false;
      }
      line = string(BOARD_VALUE_EMPTY, BOARD_SIZE); // set to '.'s
    } else if ((int)(line.length()) < BOARD_SIZE) {
      if (is_print_error) {
        cout << "Error: Line " << r << " of file \"" << filename_in
             << "\" only contains " << line.length() << " / " << BOARD_SIZE
             << " characters" << endl;
        cout << "       Adding '.'s to end" << endl;
        is_print_error = false;
      }
      line += string(BOARD_VALUE_EMPTY, BOARD_SIZE); // add '.'s
    }

    for (int c = 0; c < BOARD_SIZE; c++) {
      if (isBoardValueValid(line[c]))
        setAt(r, c, line[c]);
      else {
        setAt(r, c, BOARD_VALUE_EMPTY);
        if (is_print_error) {
          cout << "Error: Line " << r << ", character " << c << " of file \""
               << filename_in << "\" is an invalid '" << line[c]
               << "' character" << endl;
          cout << "       Substituting '" << BOARD_VALUE_EMPTY << "'" << endl;
          is_print_error = false;
        }
      }
    }
  }

  // file will be closed automatically when fin goes out of scope
}

StonesRemoved Board::playStone(int row_in, int column_in, char us_value_in) {
  assert(isInvariantTrue());
  assert(isBoardValueValid(places[row_in][column_in]));
  assert(places[row_in][column_in] == BOARD_VALUE_EMPTY);

  setAt(row_in, column_in, us_value_in);
  
  int them_score = capturePlayer(getOtherPlayer(us_value_in));
  int us_score = capturePlayer(us_value_in);

  StonesRemoved Temp1;

  Temp1.us = us_score;
  Temp1.them = them_score;


  assert(isInvariantTrue());

  return Temp1;
}

void Board::replaceAll(char old_value_in, char new_value_in) {
  assert(isBoardValueValid(old_value_in));
  assert(isBoardValueValid(new_value_in));
  assert(isInvariantTrue());

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (places[i][j] == old_value_in) {
        places[i][j] = new_value_in;
      }
    }
  }

  assert(isInvariantTrue());
}

bool Board::isANeighbourWithValue(int row_in, int column_in,
                                  char value_in) const {
  assert(isOnBoard(row_in, column_in));
  assert(isBoardValueValid(value_in));
  assert(isInvariantTrue());

  bool Flag1 = isOnBoard(row_in + 1, column_in);
  bool Flag2 = isOnBoard(row_in - 1, column_in);
  bool Flag3 = isOnBoard(row_in, column_in - 1);
  bool Flag4 = isOnBoard(row_in, column_in + 1);

  if (Flag1) {
    if (places[row_in+1][column_in] == value_in){
      return true;
    }
  }
  if (Flag2) {
    if (places[row_in-1][column_in] == value_in){
      return true;
    }
  }
  if (Flag4) {
    if (places[row_in][column_in+1] == value_in){
      return true;
    }
  }
  if (Flag3) {
    if (places[row_in][column_in-1] == value_in){
      return true;
    }
  }
  return false;
}

void Board::fillConnected(char old_value_in, char new_value_in,
                          char neighbour_value_in) {
  assert(isInvariantTrue());
  assert(isBoardValueValid(old_value_in));
  assert(isBoardValueValid(new_value_in));
  assert(isBoardValueValid(neighbour_value_in));

  bool Changes = true;
  while (Changes) {
    Changes = false;
    for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
        if (places[i][j] == old_value_in &&
            (isANeighbourWithValue(i, j, neighbour_value_in) ||
             isANeighbourWithValue(i, j, new_value_in))) {
          places[i][j] = new_value_in;
          Changes = true;
        }
      }
    }
  }
  assert(isInvariantTrue());
}
