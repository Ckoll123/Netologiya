#include <iostream>
#include <stdint.h>
#include <math.h>

uint64_t real_string_hash(const std::string& string, int length, int n);
uint64_t simple_string_hash(const std::string& string, int length);
int find_substring_light_rabin_karp(const std::string& string, const std::string& string_to_find);

int main(){

    std::string string{};
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> string;
    int result{-1};

    std::string string_to_find{};
    do{
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> string_to_find;

        result = find_substring_light_rabin_karp(string, string_to_find);

        if(result < 0){
            std::cout << "Подстрока " << string_to_find << " не найдена" << std::endl;
        }
        else{
            std::cout << "Подстрока " << string_to_find << " найдена по индексу " << result << std::endl;
        }

    } while (string_to_find != "exit");

}


uint64_t real_string_hash(const std::string& string, int length, int n){
    uint64_t hash{};
    int power{};
    int p{29};

    for(int ch = 0; ch < string.length(); ch++){
        hash += string[ch] * pow(p, power);
        power++;
    }

    return hash % n;
}

uint64_t simple_string_hash(const std::string& string, int length){
    uint64_t hash{};

    for(int ch = 0; ch < length; ch++){
        hash += string[ch];
    }

    return hash;
}


int find_substring_light_rabin_karp(const std::string& string, const std::string& string_to_find){
    uint64_t hash_string_to_find{};
    uint64_t hash_string{};
    int lenght_string_to_find = string_to_find.length();
    hash_string_to_find = simple_string_hash(string_to_find, lenght_string_to_find);

    for(int i; i < string.length(); i++){
        if(!i){
            hash_string = simple_string_hash(string, lenght_string_to_find);
        }
        else{
            hash_string += string[i + lenght_string_to_find - 1];
            hash_string -= string[i - 1];
        }

        if(hash_string_to_find == hash_string){
            for (int j{}; j < lenght_string_to_find; j++){
                if(string[i+j] != string_to_find[j]){
                    break;
                }
                else if (j == lenght_string_to_find - 1){
                    return (i);
                }
            }
        }
    }
    return -1;
}
