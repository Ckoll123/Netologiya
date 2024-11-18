#include <iostream>
#include "Task1.h"


int main() { 

  std::cout << "Задание №1. Ввод массива с консоли:\n\n";

  std::cout << "Введите размер массива: ";
  int sizeArr1;
  std::cin >> sizeArr1;  
  int* p_arr1 = new int[sizeArr1];

  for (int i = 0; i < sizeArr1; i++)
  {
      std::cout << "arr[" << i << "] = ";
      std::cin >> p_arr1[i];
  }
  printArray(p_arr1, sizeArr1);
  delete[] p_arr1;
  
  std::cout << std::endl;
}