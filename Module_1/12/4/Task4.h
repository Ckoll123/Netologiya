#pragma once

#include <iostream>
#include <fstream>

int** createDoubleArray(int rows, int columns);
void fillArray(int** p_arr, int rows, int columns, std::ifstream& iStream);
void printArrayReverse(int** pp_arr, int rows, int columns);
void deleteDoubleArray(int** pp_arr, int rows, int colums);