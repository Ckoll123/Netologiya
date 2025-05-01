#include <iostream>
#include <vector>

template <typename T>
T square(T value){
    return value * value;
}

template<typename T>
std::vector<T> square(std::vector<T> vec){
    for (T& value : vec){
        value *= value;
    }
    return vec;
}



int main(){
    int value{5};
    std::vector<float> vec = {-1, 4, 8};

    std::cout << "[IN]: " << value << std::endl;
    value = square(value);
    std::cout << "[OUT]: " << value << std::endl;

    std::cout << "[IN]: ";
    for(auto value : vec){
        std::cout << value << " ";
    }
    std::cout << std::endl;
    vec = square(vec);
    std::cout << "[OUT]: ";
    for(auto value : vec){
        std::cout << value << " ";
    }
    std::cout << std::endl;
}