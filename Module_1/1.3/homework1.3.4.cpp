#include <iostream>
#include <string> 

std::string intToText(int inputNumber);  // for 4th task

int main() {
  // Task 4
  std::cout << "\nЗадание №4. Сравнить числа\n\n"; 

  std::cout << "Введите целое число: " << std::endl;
  int firstNumber;
  std::cin >> firstNumber;

  std::cout << "Введите целое число: " << std::endl;
  int secondNumber;
  std::cin >> secondNumber;

  std::string number1{};
  number1 = intToText(firstNumber);

  std::string number2{};
  number2 = intToText(secondNumber);

  if ((number1 == "Ошибка!") || (number2 == "Ошибка!"))
  {
    std::cout << "Ошибка! Одно из чисел вне диапазона." << std::endl;
  }
  else
  {
    std::string compareSign{};
    compareSign = firstNumber > secondNumber ? " больше чем " : (firstNumber < secondNumber ? " меньше чем " : " равно ");
    std::cout << number1 << compareSign << number2 << std::endl;
  }
}  // main

std::string intToText(int inputNumber)
{
    std::string firstAndSecondDecade[]{"один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять", "десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
  std::string decadesFrom2To9[]{"двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};

  if(inputNumber < 0)
  {return "минус " + intToText(-inputNumber);}

  if(!inputNumber)
    {return "ноль";}
  else if (inputNumber == 100)
    {return "сто";}
  else if(inputNumber < 20)
    {return firstAndSecondDecade[inputNumber-1];}
  else if(inputNumber < 100)
    {
      std::string num = decadesFrom2To9[(inputNumber/10) - 2]; 
      num = inputNumber % 10 == 0 ? num : (num + " " + intToText(inputNumber % 10));
      return num;
    }

  return "Ошибка!";
} 