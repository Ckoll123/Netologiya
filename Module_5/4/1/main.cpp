#include <iostream>
#include <vector>

template <typename T>
T square(const T& value){
    return value * value;
}

template<typename T>
std::vector<T> square(const std::vector<T>& vec){
    std::vector<T> result;
    result.reserve(vec.size());
    for (const T& value : vec){
        result.push_back(value * value);
    }
    return result;
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