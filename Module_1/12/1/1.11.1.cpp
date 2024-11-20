#include <iostream>
#include <fstream>


int main() { 

  std::cout << "Задание №1. Вывод файла:\n\n";

  std::ifstream iFile("in.txt");
  if (iFile.is_open())
  {
    std::string inText;
    while (iFile >> inText)
    {
      std::cout << inText << std::endl;
    }
  }
  else
    {std::cout << "Не удалось открыть файл" << std::endl;}
  
  iFile.close();
}