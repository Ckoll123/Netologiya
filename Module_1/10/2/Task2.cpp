#include "Task2.h"

double* createArray(int size)
{
  double* p_arr = new double[size]{};
  return p_arr;
}

void printArray(double* array, int size)
{
  std::cout << "Введённый массив: ";
  for (int i = 0; i < size; i++)
    {std::cout << array[i] << " ";}
}