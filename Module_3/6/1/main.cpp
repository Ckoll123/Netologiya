#include <iostream>

#define MODE 1

#if MODE == 1
    int add(int a, int b)
    { return a + b; }
#endif

#ifndef MODE
#error "Нееобходимо определить MODE"
#endif

int main()
{
    std::cout << "Задача 1. Препроцессорные директивы" << std::endl << std::endl;

#if MODE == 1
{
    std::cout << "Работаю в боевом режиме" << std::endl;
    int number1; 
    std::cout << "Введите число 1: ";
    std::cin >> number1; 
    int number2; 
    std::cout << "Введите число 2: ";
    std::cin >> number2;
    std::cout << "Результат сложения " << add(number1, number2) << std::endl;
}
#elif (MODE == 0)
    std::cout << "Работаю в режиме тренировки" << std::endl;
#else
    std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif
} 