  #include <iostream>

void swap(int& a, int& b);

int main(int argc, char** argv)
{   
  // Task 1
  std::cout << "Задание №1. Адреса переменных:\n\n";

  short s;
  int i;
  long c;
  long long d;
  float e;
  double f;
  long double g;
  bool h;

  std::cout << "short: " << &s << " " << sizeof(s) << "\n";
  std::cout << "int: " << &i << " " << sizeof(i) << "\n";
  std::cout << "long: " << &c << " " << sizeof(c) << "\n";
  std::cout << "long long: " << &d << " " << sizeof(d) << "\n";
  std::cout << "float: " << &e << " " << sizeof(e) << "\n";
  std::cout << "double: " << &f << " " << sizeof(f) << "\n";
  std::cout << "long double: " << &g << " " << sizeof(g) << "\n";
  std::cout << "bool: " << &h << " " << sizeof(h) << std::endl;
  
  //-----------------------------------------------------------------

  // Task 2
  std::cout << std::endl << std::endl;
  std::cout << "Задание №2. Обмен значениями:\n\n";

  int a = 5, b = 8;

  std::cout << "a = " << a << ", b = " << b << std::endl;

  swap(a, b);

  std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;
  
  return 0;
}

void swap(int& a, int& b)
{
  a += b;
  b = a - b;
  a -= b;
}