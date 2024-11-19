#include <iostream>
#include "Task3.h"


int main() { 
  std::cout << std::endl << std::endl;
  std::cout << "Задание №3. Динамическая таблица умножения:\n\n";

  std::cout << "Введите количество строк: ";
  int rows;
  std::cin >> rows;
  std::cout << "Введите количество столбцов: ";
  int colums;
  std::cin >> colums;
  int** pp_arr = create_two_dim_array(rows, colums);
  fill_two_dim_array(pp_arr, rows, colums);
  print_two_dim_array(pp_arr, rows, colums);
  delete_two_dim_array(pp_arr, rows, colums);
}
