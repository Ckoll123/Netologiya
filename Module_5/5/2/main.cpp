#include <iostream>
#include <set>

class Comparator{
public:
    bool operator()(const int& a, const int& b) const {return a > b;}
};

int main(){
    std::cout << "[IN]:" << std::endl;
    unsigned int number{};
    std::cin >> number;
    std::set<int, Comparator> numbers;
    while(number){
        int tempNumber{};
        std::cin >> tempNumber;
        numbers.insert(tempNumber);
        number--;
    }

    std::cout << "[OUT]:" << std::endl;
    for(int number : numbers){
        std::cout << number << std::endl;
    }

}