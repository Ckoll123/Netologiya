#include <iostream>
#include <fstream>
#include <string>

class Address
{
public:
    void setAddress(std::ifstream& inStream);
    void getAddress(std::ofstream& outStream);
private:
    std::string city;
    std::string street;
    unsigned building;
    unsigned room;

friend void sortAddresses(Address* addressNumber, unsigned addressQuantity);
};

void sortAddresses(Address* addressNumber, unsigned addressQuantity);

int main()
{
    std::cout << "Задача 2. Сортируем адреса" << std::endl << std::endl;

    std::ifstream inputFile("in.txt");
        
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    unsigned numberOfAddresses;
    inputFile >> numberOfAddresses;
    Address addressDataBase[numberOfAddresses];

    for (unsigned i = 0; i < numberOfAddresses; i++)
    { addressDataBase[i].setAddress(inputFile); }

    sortAddresses(addressDataBase, numberOfAddresses);

    std::ofstream outFile("out.txt");

    outFile << numberOfAddresses << std::endl;
    for (unsigned i = 0; i < numberOfAddresses; i++)
    { addressDataBase[i].getAddress(outFile); }

    outFile.close();
    inputFile.close();


}


void Address::setAddress(std::ifstream& inStream)
{ inStream >> city >> street >> building >> room; }

void Address::getAddress(std::ofstream& outStream)
{
    outStream << city       << ", "
              << street     << ", "
              << building   << ", "
              << room       << ", "
              << std::endl;
}

void sortAddresses(Address* addressNumber, unsigned addressQuantity)
{
    bool sorted{true};
    std::string temp;

    for (int i = addressQuantity - 1; i >=0 ; i--)
    {
        sorted = true;
        for (int j = 0; j < i; j++)
        {
            if (addressNumber[j].city > addressNumber[j + 1].city)
            {
                temp = addressNumber[j].city;
                addressNumber[j].city = addressNumber[j + 1].city;
                addressNumber[j + 1].city = temp;
                sorted = false;
            }
        }

        if (sorted) {break;}
    }
}