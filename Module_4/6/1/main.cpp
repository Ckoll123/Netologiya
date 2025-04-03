#include <iostream>

unsigned int simple_string_hash(const std::string& string);

int main(){

    std::string string;
    do{
        std::cout << "Введите строку: ";
        std::cin >> string;
        std::cout << "Наивный хэш строки ", string, " = ";
        std::cout << simple_string_hash(string) << std::endl;
    } while (string != "exit");

}


unsigned int simple_string_hash(const std::string& string){
    unsigned int hash{};
    for (auto &ch : string){
         hash += ch;
    } 
    return hash;
}
