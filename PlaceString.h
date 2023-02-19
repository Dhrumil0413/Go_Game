/*
Student Name: Vaghasiya Dhrumil Arvindbhai
Student ID: 200492148
*/
#pragma once
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


const int INVALID_COORDINATE = -1;


int stringToInteger(const string &input);
int placeStringToRow(const string &input);
int placeStringToColumn(const string &input);
bool isPlaceStringWellFormed(const string &input);

