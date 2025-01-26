#include <iostream>

struct Address{
    std::string city;
    std::string street;
    unsigned buildng;
    unsigned room;
    unsigned postcode;    
};

void printAddress(Address& address);

int main()
{
    std::cout << "Задача 3. Вывод структуры" << std::endl << std::endl;

    Address newBuilding = {"Москва", "Арбат", 12, 8, 123456};
    Address home = {"Ижевск", "Пушкина", 59, 143, 953769};

    printAddress(newBuilding);
    printAddress(home);
}

void printAddress(Address& address)
{
    std::cout << "Город: " << address.city << std::endl;
    std::cout << "Улица: " << address.street << std::endl;
    std::cout << "Номер дома: " << address.buildng << std::endl;
    std::cout << "Номер квартиры: " << address.room << std::endl;
    std::cout << "Индекс: " << address.postcode << std::endl;
    std::cout << std::endl;
}