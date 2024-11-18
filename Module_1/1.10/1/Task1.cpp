#include "Task1.h"

void printArray(int* array, int size)
{
  std::cout << "Введённый массив: ";
  for (int i = 0; i < size; i++)
    {std::cout << array[i] << " ";}
}