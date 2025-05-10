#include <iostream>
#include "Table.h"

int main(){
    auto test = Table<int>(2, 3);
    try{
        test[1][0] = 4;
        test[1][2] = 3;
        test[0][2] = 2;
        test[1][1] = 1;
        std::cout << test[1][0] << " ";
        std::cout << test[1][1] << " ";
        std::cout << test[1][2] << " ";
        std::cout << test[2][3] << " ";
    }
    catch(const std::exception& ex){
        std::cout << ex.what() << std::endl;
    }
}