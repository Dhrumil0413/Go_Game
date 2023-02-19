/*
Student Name: Vaghasiya Dhrumil Arvindbhai
Student ID: 200492148
*/
#pragma once
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int VALUE_NOT_FOUND = INT_MAX;

//Assignment 1 Prototypes
int linearSearch(const string data_in[], int count_in, const string &value_in);
int unsortedFindSmallest(const string data_in[], int count_in);
int unsortedFindLargest(const string data_in[], int count_in);

// Assignment 2 Prototypes
void mySort(string data_in[], int count_in);
bool isSorted(const string data_in[], int count_in);
int sortedFindSmallest(const string data_in[], int count_in);
int sortedFindLargest(const string data_in[], int count_in);
int binarySearch(const string data_in[], int count_in, const string &value_in);
int binarySearchFirst(const string data_in[], int count_in,
                      const string &value_in);
