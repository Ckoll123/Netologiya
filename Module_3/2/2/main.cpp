#include <iostream>

class Counter{
public:
    Counter();
    Counter(int initValue);
    void increment();
    void decrement();
    int showCurrentValue();

private:
    int counterValue;
};

Counter initCounter();

int main()
{
    std::cout << "Задача 2. Счётчик" << std::endl << std::endl;

    Counter counter = initCounter();

    char command; 
    std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
    std::cin >> command;

    while ((command != 'x') && (command != 'х'))
    {
        if (command == '+') counter.increment();
        else if (command == '-') counter.decrement();
        else if (command == '=') std::cout << counter.showCurrentValue() << std::endl;
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;
    }
    
    std::cout << "До свидания!" << std::endl;
    
}

Counter::Counter():
    counterValue(1)
{}

Counter::Counter(int initValue):
    counterValue(initValue)
{}

void Counter::increment()
{counterValue++;}

void Counter::decrement()
{counterValue--;}

int Counter::showCurrentValue()
{return counterValue;}

Counter initCounter()
{
    std::string command; 
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: " << std::endl;
    std::getline(std::cin >> std::ws, command);

    if (command == "да")
    {
        int counterInitValue;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> counterInitValue;
        Counter counter(counterInitValue);
        return counter;
    }
    else if (command == "нет")
    {
        Counter counter;
        return counter;
    }
    else
    {
        std::cout << "Неверная команда!" << std::endl;
        Counter counter;
        return counter;
    }
}