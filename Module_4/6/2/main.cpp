#include <iostream>
#include <stdint.h>
#include <math.h>

uint64_t real_string_hash(const std::string& string, int p, int n);

int main(){

    int p{};
    int n{};
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;

    std::string string;
    do{
        std::cout << "Введите строку: ";
        std::cin >> string;
        std::cout << "Наивный хэш строки ", string, " = ";
        std::cout << real_string_hash(string, p, n) << std::endl;
    } while (string != "exit");

}


uint64_t real_string_hash(const std::string& string, int p, int n){
    uint64_t hash{};
    int power{};

    for (auto &ch : string){
         hash += ch * pow(p, power);
         power++;
    } 
    return hash % n;
}
