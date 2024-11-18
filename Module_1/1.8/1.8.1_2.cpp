#include <iostream>

// Task 1
void counting_function();

// Task 2
namespace addition {
  int calc(int x, int y);
}

namespace subtruction {
  int calc(int x, int y);
}

namespace multiplication {
  int calc(int x, int y);
}

namespace division {
  int calc(int x, int y);
}



int main() {

  std::cout << "Задание №1. Считающая функция\n\n";

  for (int i = 0; i < 15; i++) {
    counting_function();
  }

  std::cout << std::endl << std::endl;

  //--------------------------------------------------------------------------

  std::cout << "Задание №2. Одинаковые, но разные функции\n\n";

  int x{6};
  int y{9};

  std::cout << "x = " << x << ", y = " << y << std::endl;
  std::cout << "Сложение: " << addition::calc(x, y) << std::endl;
  std::cout << "Вычитание: " << subtruction::calc(x, y) << std::endl;
  std::cout << "Умножение: " << multiplication::calc(x, y) << std::endl;
  std::cout << "Деление: " << division::calc(x, y) << std::endl;

  return 0;
}

// Task 1
void counting_function() {
  static int counter{1};
  std::cout << "Количество вызовов функции counting_function(): " << counter++
            << std::endl;
}

// Task 2
int addition::calc(int x, int y) { return x + y; }
int subtruction::calc(int x, int y) { return x - y; }
int multiplication::calc(int x, int y) { return x * y; }
int division::calc(int x, int y) { return x / y; }
