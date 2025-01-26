#include <iostream>

class Calculator{
public:
    double add();
    double multiply();
    double subtract_1_2();
    double subtract_2_1();
    double divide_1_2();
    double divide_2_1();
    bool set_num1(double num1);
    bool set_num2(double num2);

private:
    double num1;
    double num2;
};


int main()
{
    std::cout << "Задача 1. Калькулятор двух чисел" << std::endl << std::endl;

    Calculator calculator;
    double number1;
    double number2;

    while(true)
    {
        std::cout << "Введите num1: ";
        std::cin >> number1;
        if(!calculator.set_num1(number1))
        {
            std::cout << "Неверный ввод!" << std::endl;

            std::cout << "Введите num1: ";
            std::cin >> number1;
            while (!calculator.set_num1(number1))
            {
                std::cout << "Неверный ввод!" << std::endl;
                std::cout << "Введите num1: ";
                std::cin >> number1;
            }
        }


        std::cout << "Введите num2: ";
        std::cin >> number2;
        if(!calculator.set_num2(number2))
        {
            std::cout << "Неверный ввод!" << std::endl;

            std::cout << "Введите num2: ";
            std::cin >> number2;
            while (!calculator.set_num2(number2))
            {
                std::cout << "Неверный ввод!" << std::endl;
                std::cout << "Введите num2: ";
                std::cin >> number2;
            }
        }

        std::cout << "num1 + num2 = " << calculator.add() << std::endl;
        std::cout << "num1 - num2 = " << calculator.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calculator.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calculator.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calculator.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calculator.divide_2_1() << std::endl;
    }

}


double Calculator::add()
{return num1 + num2;}

double Calculator::multiply()
{return num1 * num2;}

double Calculator::subtract_1_2()
{return num1 - num2;}

double Calculator::subtract_2_1()
{return num2 - num1;}

double Calculator::divide_1_2()
{return num1 / num2;}

double Calculator::divide_2_1()
{return num2 / num1;}

bool Calculator::set_num1(double num1)
{
    if (num1)
    {
        this->num1 = num1;
        return true;
    }
    else 
    {return false;}
}
bool Calculator::set_num2(double num2)
{
    if (num2)
    {
        this->num2 = num2;
        return true;
    }
    else 
    {return false;}
}