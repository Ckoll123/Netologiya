#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <vector>


template <typename T>
void print_container(T container){
    for (auto it : container){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);
}