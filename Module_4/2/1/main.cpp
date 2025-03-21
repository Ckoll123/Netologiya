#include <iostream>

int fibonachi(int number);

int main(){

    int result = fibonachi(6);
    std::cout << result;
    return 0;
}

int fibonachi(int number){
    if (number <= 1) {
        return number;
    }
    else
    { return fibonachi(number - 1) + fibonachi(number - 2); }
    
}
