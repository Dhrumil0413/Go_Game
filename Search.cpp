/*
Student Name: Vaghasiya Dhrumil Arvindbhai
Student ID: 200492148
*/
#include "Search.h"
#include <cassert>
#include <iostream>
using namespace std;

int linearSearch(const string data_in[], int count_in, const string &value_in) {
  for (int i = 0; i < count_in; i++) {
    if (data_in[i] == value_in) {
      return i;
    }
  }

  return VALUE_NOT_FOUND;
}

int unsortedFindSmallest(const string data_in[], int count_in) {
  int smallest_int = 0;
  string smallest_str = data_in[0];
  for (int i = 1; i < count_in; i++) {
    if (data_in[i] < smallest_str) {
      smallest_str = data_in[i];
      smallest_int = i;
    }
  }
  return smallest_int;
}

int unsortedFindLargest(const string data_in[], int count_in) {
  int largest_int = 0;
  string largest_str = data_in[0];
  for (int i = 1; i < count_in; i++) {
    if (data_in[i] > largest_str) {
      largest_str = data_in[i];
      largest_int = i;
    }
  }
  return largest_int;
}

// Selection Sort Code;
void mySort(string data_in[], int count_in) {
  if (count_in <= 0) {
    return;
  }
  int current_int_min, i;
  string tempValue, current_min = data_in[0];

  for (int i = 0; i < count_in - 1; i++) {
    current_int_min = i;
    current_min = data_in[i];
    for (int j = i + 1; j < count_in; j++) {
      if (data_in[j] < current_min) {
        current_int_min = j;
        current_min = data_in[j];
      }
    }
    if (current_int_min > i) {
      tempValue = data_in[i];
      data_in[i] = data_in[current_int_min];
      data_in[current_int_min] = tempValue;
    }
  }
} 

bool isSorted(const string data_in[], int count_in) {
  // I take granted that Array is sorted in Ascending Order.
  int i = 1;
  while (i < count_in) {
    if (data_in[i] < data_in[i - 1]) {
      return false;
    }
    i++;
  }
  return true;
}

int sortedFindSmallest(const string data_in[], int count_in) {
  // It will return index of First Position. Which is 0;
  assert(isSorted(data_in, count_in));
  assert(count_in > 0);
  return 0;
}

int sortedFindLargest(const string data_in[], int count_in) {
  assert(isSorted(data_in, count_in));
  assert(count_in > 0);
  return count_in - 1;
}

int binarySearch(const string data_in[], int count_in, const string &value_in) {
  assert(isSorted(data_in, count_in));
  int low = 0, high = count_in - 1, mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (data_in[mid] == value_in) {
      return mid;
    } else if (data_in[mid] < value_in) {
      low = mid + 1;
    } else if (data_in[mid] > value_in) {
      high = mid - 1;
    }
  }
  return VALUE_NOT_FOUND;
}

int binarySearchFirst(const string data_in[], int count_in,
                      const string &value_in) {
  assert(isSorted(data_in, count_in));
  if (count_in <= 0){
    return VALUE_NOT_FOUND;
  }

  int low = 0, high = count_in - 1, mid;
  int result = VALUE_NOT_FOUND;

  while (low <= high) {
    mid = (low + high) / 2;
    if (data_in[mid] == value_in) {
      high = mid - 1;
      result = mid;
    } else if (data_in[mid] < value_in) {
      low = mid + 1;
    } else if (data_in[mid] > value_in) {
      high = mid - 1;
    }
  }
  return result;
} // This binarySearchFirst Function will search for the first occurance of
  // value_in;