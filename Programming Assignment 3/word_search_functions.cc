//Copyright Sakthi Thanigai 03/06/26
#include "word_search_functions.h"
#include <fstream>
#include <iostream>
using std::cout;
using std::endl;
using std::ifstream;

bool ReadWordSearch(string file_name, char word_search[][kSize]) {
  ifstream input(file_name);
  if (!input.is_open()) return false;

  char ch;
  int count = 0;
  while (input >> ch && count < kSize * kSize) {
    word_search[count / kSize][count % kSize] = ch;
    count++;
  }
  input.close();
  return (count == kSize * kSize);
}

void PrintWordSearch(const char word_search[][kSize]) {
  for (int row = 0; row < kSize; row++) {
    for (int col = 0; col < kSize; col++) {
      cout << word_search[row][col] << " ";
    }
    cout << endl;
  }
}

bool FindWordRight(const char word_search[][kSize], string to_find, int& row, int& col) {
  int length = to_find.length();
  for (int r = 0; r < kSize; r++) {
    for (int c = 0; c <= kSize - length; c++) {
      int i = 0;
      for (; i < length; i++) {
        if (word_search[r][c + i] != to_find[i]) break;
      }
      if (i == length) {
        row = r;
        col = c;
        return true;
      }
    }
  }
  return false;
}

bool FindWordLeft(const char word_search[][kSize], string to_find, int& row, int& col) {
  int length = to_find.length();
  for (int r = 0; r < kSize; r++) {
    for (int c = length - 1; c < kSize; c++) {
      int i = 0;
      for (; i < length; i++) {
        if (word_search[r][c - i] != to_find[i]) break;
      }
      if (i == length) {
        row = r;
        col = c;
        return true;
      }
    }
  }
  return false;
}

bool FindWordDown(const char word_search[][kSize], string to_find, int& row, int& col) {
  int length = to_find.length();
  for (int c = 0; c < kSize; c++) {
    for (int r = 0; r <= kSize - length; r++) {
      int i = 0;
      for (; i < length; i++) {
        if (word_search[r + i][c] != to_find[i]) break;
      }
      if (i == length) {
        row = r;
        col = c;
        return true;
      }
    }
  }
  return false;
}

bool FindWordUp(const char word_search[][kSize], string to_find, int& row, int& col) {
  int length = to_find.length();
  for (int c = 0; c < kSize; c++) {
    for (int r = length - 1; r < kSize; r++) {
      int i = 0;
      for (; i < length; i++) {
        if (word_search[r - i][c] != to_find[i]) break;
      }
      if (i == length) {
        row = r;
        col = c;
        return true;
      }
    }
  }
  return false;
}

bool FindWordDiagonal(const char word_search[][kSize], string to_find, int& row, int& col) {
  int length = to_find.length();
  for (int r = 0; r <= kSize - length; r++) {
    for (int c = 0; c <= kSize - length; c++) {
      int i = 0;
      for (; i < length; i++) {
        if (word_search[r + i][c + i] != to_find[i]) break;
      }
      if (i == length) {
        row = r;
        col = c;
        return true;
      }
    }
  }
  return false;
}
