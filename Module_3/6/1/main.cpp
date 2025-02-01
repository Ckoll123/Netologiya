#include <iostream>

#define MODE 1

#ifdef MODE
    int add(int a, int b)
    { return a + b; }
#endif

int main()
{
    std::cout << "Задача 1. Препроцессорные директивы" << std::endl << std::endl;

#ifndef MODE
    std::cout << "Нееобходимо определить MODE" << std::endl;
#else
    if(MODE)
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
    else 
        std::cout << "Работаю в режиме тренировки" << std::endl;
#endif
} 