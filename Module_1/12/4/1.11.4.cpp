#include <iostream>
#include <fstream>
#include <string>

#include "Task4.h"

int main() { 

  std::cout << "Задание №4. Считывание двумерного массива из файла:\n\n";

  std::ifstream iFile("in.txt");
  if (iFile.is_open())
  {
    int rows;
    iFile >> rows;
    int columns;
    iFile >> columns;

    int** pp_arr = createDoubleArray(rows, columns); 
    fillArray(pp_arr, rows, columns, iFile);
    printArrayReverse(pp_arr, rows, columns);
    deleteDoubleArray(pp_arr, rows, columns);
  }
  else
    {std::cout << "Не удалось открыть файл" << std::endl;}
  
  iFile.close();
}