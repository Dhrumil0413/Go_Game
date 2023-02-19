/*
Student Name: Vaghasiya Dhrumil Arvindbhai
Student ID: 200492148
*/
#pragma once
#include <iostream>
using namespace std;

const char BOARD_VALUE_EMPTY = '.';
const char BOARD_VALUE_BLACK = 'O';
const char BOARD_VALUE_WHITE = '@';
const char BOARD_VALUE_MARKED = '#';

bool isBoardValueValid (char value);
bool isBoardValuePlayer(char value_in);
char getOtherPlayer(char player_value_in);