#include <iostream>

int main() {
  // Task 1
  std::cout << "Задание №1. Таблица истинности:\n\n";
  std::cout << "Оператор ||\n";
  std::cout << "true\t" << "true\t" << "true\t" << std::endl;
  std::cout << "false\t" << "true\t" << "true\t" << std::endl;
  std::cout << "true\t" << "false\t" << "true\t" << std::endl;
  std::cout << "false\t" << "false\t" << "false\t" << '\n' << std::endl;

  std::cout << "Оператор &&\n";
  std::cout << "true\t" << "true\t" << "true\t" << std::endl;
  std::cout << "false\t" << "true\t" << "false\t" << std::endl;
  std::cout << "true\t" << "false\t" << "false\t" << std::endl;
  std::cout << "false\t" << "false\t" << "false\t" << std::endl;
          
  // Task 2
  std::cout << "\nЗадание №2. Упорядочить числа:\n\n";
  std::cout << "Введите первое число:\n";
  float firstNumber;
  std::cin >> firstNumber;
  std::cout << "Введите первое число:\n";
  float secondNumber;
  std::cin >> secondNumber;
  std::cout << "Введите третье число:\n";
  float thirdNumber;
  std::cin >> thirdNumber;

  // Change first two numbers
  float temp{firstNumber};
  firstNumber = firstNumber > secondNumber ? firstNumber : secondNumber;
  secondNumber = firstNumber == secondNumber ? temp : secondNumber;

  // Change last two numbers
  temp = secondNumber;
  secondNumber = secondNumber > thirdNumber ? secondNumber : thirdNumber;
  thirdNumber = secondNumber == thirdNumber ? temp : thirdNumber;

  // Change first two numbers
  temp = firstNumber;
  firstNumber = firstNumber > secondNumber ? firstNumber : secondNumber;
  secondNumber = firstNumber == secondNumber ? temp : secondNumber;

  std::cout << "Результат: " << firstNumber << ' ' << secondNumber << ' ' 
            << thirdNumber << '\n' << std::endl;  
}