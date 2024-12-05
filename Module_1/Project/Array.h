#pragma once

#include <iostream>
#include <fstream>

char** createDoubleArray(int rows, int columns);

void fillArray(char** ppArr, int rows, int columns, std::ifstream& iStream);
void fillArray(char** ppArr, int rows, int columns, char initSymbol);
void fillArray(char** ppArrCopyTo, int rows, int columns, char** ppArrCopyFrom);

void printArray(const char* const* ppArr, const int rows, const int columns);

void deleteDoubleArray(char** ppArr, const int rows, const int columns);