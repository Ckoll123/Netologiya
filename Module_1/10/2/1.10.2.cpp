#include <iostream>
#include "Task2.h"


int main() { 

  // Task 2
  std::cout << std::endl << std::endl;
  std::cout << "Задание №2. Создатель массивов:\n\n";

  std::cout << "Введите размер массива: ";
  int sizeArr2;
  std::cin >> sizeArr2;
  double* p_arr2 = createArray(sizeArr2);
  printArray(p_arr2, sizeArr2);
  delete[] p_arr2;
}
