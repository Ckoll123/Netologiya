#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void unique_vector(std::vector<T>& vec){
    auto it = vec.begin();
    std::sort(vec.begin(), vec.end());
    it = std::unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());
}

int main(){
    std::vector<int> vec{1, 1, 2, 5, 6, 1, 2, 4};
    std::cout << "[IN]: ";
    for (auto element : vec){
        std::cout << element << " ";
    }
    std::cout << std::endl;

    unique_vector(vec);

    std::cout << "[OUT]: ";
    for (auto element : vec){
        std::cout << element << " ";
    }
    std::cout << std::endl;
}