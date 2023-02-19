/*
Student Name: Vaghasiya Dhrumil Arvindbhai
Student ID: 200492148
*/
#pragma once
#include <iostream>
using namespace std;

const int BOARD_SIZE = 19;


bool isOnBoard(int row_in, int column_in);
bool isBoardValuePlayer (char value_in);
char getOtherPlayer (char player_value_in);