#include <iostream>
#include "staticLib/Greeter.h"

int main(){

    Greeter greeter;
    std::string temp;
    std::cout << "Введите имя: ";
    std::cin >> temp;
    std::cout << greeter.greet(temp);
}