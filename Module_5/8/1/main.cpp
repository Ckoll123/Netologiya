#include <iostream>
#include <vector>
#include <utility>

template <typename T>
void move_vectors(std::vector<T>& vec_from, std::vector<T>& vec_to){
    vec_to = std::move(vec_from);
}

int main(){
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    move_vectors(one, two);

    std::cout << "one size: " << one.size() << std::endl;
    std::cout << "two size: " << two.size() << std::endl;
    for (const auto& str : two) {
        std::cout << str << std::endl;
    }
}