#include <iostream>

// Task 1
int sum(int a, int b);
int diff(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);

// Task 2
int powerFunc(int value, int power);


// Task 3
int fibonacci(int number);


int main() {
  
  // Task 1
  std::cout << "Задание №1. Арифметические функции:\n\n";
  
  int a = 5, b = 10;
  
  int s = sum(a, b);
  int dif = diff(a, b);
  int mult = multiplication(a, b);
  double div = division(a, b);
  
  std::cout << a << " + " << b << " = " << s << std::endl;
  std::cout << a << " - " << b << " = " << dif << std::endl;
  std::cout << a << " * " << b << " = " << mult << std::endl;
  std::cout << a << " / " << b << " = " << div << std::endl;

  //--------------------------------------------------------------------------------------

  // Task 2
  std::cout << std::endl << std::endl;
  std::cout << "Задание №2. Устранение дублирования:\n\n";
  
  int value = 5, power = 2;
  std::cout << value << " в степени " << power << " = " << powerFunc(value, power) << std::endl;

  value = 3;
  power = 3;
  std::cout << value << " в степени " << power << " = " << powerFunc(value, power) << std::endl;

  value = 4;
  power = 4;
  std::cout << value << " в степени " << power << " = " << powerFunc(value, power) << std::endl;

//--------------------------------------------------------------------------------------
  
  // Task 3
  std::cout << std::endl << std::endl;
  std::cout << "Задание №3. Числа Фибоначчи:\n\n";

  std::cout << "Введите число: ";
  int number;
  std::cin >> number;
  std::cout << "Числа Фибоначчи: ";
  for(int i = 0; i < number; i++)
  {
    std::cout << fibonacci(i) << " ";
  }
 
  return 0;
}


// Task 1
int sum(int a, int b) {
  return a + b;
}

int diff(int a, int b) {
  return a - b;
}

int multiplication(int a, int b) {
  return a * b;
}

int division(int a, int b) {
  return a / b;
}

// Task 2
int powerFunc(int value, int power)
{
  if(power > 1)
    {return value * powerFunc(value, power - 1);}
  else
    {return value;}
}

// Task 3
int fibonacci(int number)
{
  if(number == 0 || number == 1)
    {return number;}
  else
    {return fibonacci(number - 1) + fibonacci(number - 2);}
}