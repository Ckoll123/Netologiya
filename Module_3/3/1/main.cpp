#include <iostream>
#include <fstream>
#include <string>

struct Address
{
    std::string city;
    std::string street;
    unsigned building;
    unsigned room;
};


int main()
{
    std::cout << "Задача 1. Адреса" << std::endl << std::endl;

    std::ifstream inputFile("in.txt");

    if (inputFile.is_open())
    {
        int numberOfAddresses;
        inputFile >> numberOfAddresses;
        Address addressDataBase[numberOfAddresses];

        for (int i = 0; i < numberOfAddresses; i++)
        {
            inputFile >> addressDataBase[i].city;
            inputFile >> addressDataBase[i].street;
            inputFile >> addressDataBase[i].building;
            inputFile >> addressDataBase[i].room;
        }

        std::ofstream outFile("out.txt");
        if (outFile.is_open())
        {
            outFile << numberOfAddresses << std::endl;
            for (int i = numberOfAddresses - 1; i >= 0; i--)
            {
                outFile << addressDataBase[i].city      << ", " 
                        << addressDataBase[i].street    << ", " 
                        << addressDataBase[i].building  << ", " 
                        << addressDataBase[i].room      << ", " 
                        << std::endl;
            }
            outFile.close();
        }
        inputFile.close();
    }
    else {std::cout << "Не удалось открыть файл!" << std::endl;}

}