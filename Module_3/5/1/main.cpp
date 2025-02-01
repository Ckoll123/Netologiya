#include <iostream>

float sum(float a, float b);
float substr(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float pow(float a, float b);

int main()
{
    std::cout << "Задача 1. Математические функции" << std::endl;

    float number1;
    std::cout << "Введите первое число: "; 
    std::cin >> number1; 

    float number2;
    std::cout << "Введите второе число: "; 
    std::cin >> number2;

    int option;
    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): "; 
    std::cin >> option;

    enum class MATH_FUNCTIONS{
        SUM = 1,
        SUBSTR,
        MULTIPLY,
        DIVIDE,
        POWER
    };

    MATH_FUNCTIONS math_functions = static_cast<MATH_FUNCTIONS>(option);

    switch (math_functions)
    {
    case MATH_FUNCTIONS::SUM:
        std::cout << number1 << " плюс " << number2 << " = " << sum(number1, number2) << std::endl;
        break;
    case MATH_FUNCTIONS::SUBSTR:
        std::cout << number1 << " минус " << number2 << " = " << substr(number1, number2) << std::endl;
        break;
    case MATH_FUNCTIONS::MULTIPLY:
        std::cout << number1 << " умножить на " << number2 << " = " << multiply(number1, number2) << std::endl;
        break;
    case MATH_FUNCTIONS::DIVIDE:
        std::cout << number1 << " разделить на " << number2 << " = " << divide(number1, number2) << std::endl; 
        break;
    case MATH_FUNCTIONS::POWER:
        std::cout << number1 << " в степени " << number2 << " = " << pow(number1, number2) << std::endl; 
        break;

    default:
        std::cout << "Неизвестная функция" << std::endl; 
        break;
    }

}