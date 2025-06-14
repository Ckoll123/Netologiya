#include <iostream>
#include <stdexcept>
#include <fstream>

#include "IniParser.h"

int main(){

    try{
        IniParser parser("filename.ini");
        auto value1 = parser.get_value<double>("Section1.var1");
        std::cout << "Значение в Section1.var1 = " << value1 << std::endl;

        auto value2 = parser.get_value<std::string>("Section2.var2");
        std::cout << "Значение в Section2.var2 = " << value2 << std::endl;

        auto value3 = parser.get_value<std::string>("Section10.var1");
        std::cout << "Значение в Section10.var1 = " << value3 << std::endl;
    }
    catch(const std::out_of_range& ex){
        std::cout << ex.what() << std::endl;
        // std::cout << "Не существует указанной секции или переменной" << std::endl;
    }
    catch(const std::exception& ex){
        std::cout << ex.what() << std::endl;
    }


    return 0;
}