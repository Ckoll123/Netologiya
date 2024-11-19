#include <iostream>
#include <cmath>  // for 2nd task

int main() {

  std::cout << "Задание №1. Сумматор\n\n";
  
  int sum{0};
  while(true)
  {
    std::cout << "Введите целое число или число '0', чтобы закончить: ";
    int inputNumber;
    std::cin >> inputNumber;
    if(!inputNumber)
      {break;}
    else
      {sum += inputNumber;}
  }

  std::cout << "Сумма: " << sum << std::endl;


  
  std::cout << "Задание №2. Сумма цифр числа\n\n";

  std::cout << "Введите целое число: ";
  int inputNumber1;
  std::cin >> inputNumber1;

  int sum1{0};
  for (; inputNumber1 != 0; inputNumber1 /= 10)
    {sum += abs(inputNumber1 % 10);}
  
  std::cout << "Сумма цифр: " << sum1 << std::endl;


  
  std::cout << "Задание №3. Таблица умножения для числа\n\n";

  std::cout << "Введите целое число: ";
  int inputNumber2;
  std::cin >> inputNumber2;

  for (int i = 1; i <= 10; i++)
  {
    std::cout << inputNumber2 << " * " << i << " = " << inputNumber2 * i << std::endl;
  }
  
  return 0;
}