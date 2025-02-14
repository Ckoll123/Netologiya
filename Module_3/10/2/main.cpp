#include <iostream>
#include "DynamicLib/Leaver.h"

int main(){
    Leaver leaver;
    std::string temp;
    std::cout << "Введите имя: ";
    std::cin >> temp;
    std::cout << leaver.leave(temp);
}