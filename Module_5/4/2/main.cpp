#include <iostream>
#include "Table.h"

int main(){
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    test[0][1] = 3;
    test[1][0] = 2;
    test[1][1] = 1;
    std::cout << test[0][0];
    std::cout << test[0][1];
    std::cout << test[1][0];
    std::cout << test[1][1];
}