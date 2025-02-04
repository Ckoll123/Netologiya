#include <iostream>
#include <fstream>
#include <string>

class Address
{
public:
    Address(std::ifstream& inStream);
    void getAddress(std::ofstream& outStream);
    std::string getCity() const;

private:
    std::string city;
    std::string street;
    unsigned building;
    unsigned room;
};

void sortAddresses(Address** addressNumber, unsigned addressQuantity);

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

    Address** addressDataBase = new Address* [numberOfAddresses];

    for (unsigned i = 0; i < numberOfAddresses; i++)
    { addressDataBase[i] = new Address(inputFile); }

    sortAddresses(addressDataBase, numberOfAddresses);

    std::ofstream outFile("out.txt");

    outFile << numberOfAddresses << std::endl;
    for (unsigned i = 0; i < numberOfAddresses; i++)
    { addressDataBase[i]->getAddress(outFile); }

    outFile.close();
    inputFile.close();

    for (unsigned i = 0; i < numberOfAddresses; i++)
    { delete addressDataBase[i]; }

    delete []addressDataBase;
}


Address::Address(std::ifstream& inStream)
{ inStream >> city >> street >> building >> room; }

void Address::getAddress(std::ofstream& outStream)
{
    outStream << city       << ", "
              << street     << ", "
              << building   << ", "
              << room       << ", "
              << std::endl;
}

std::string Address::getCity() const
{ return city; }


void sortAddresses(Address** addressNumber, unsigned addressQuantity)
{
    bool sorted{true};
    Address* temp;

    for (int i = addressQuantity - 1; i >=0 ; i--)
    {
        sorted = true;
        for (int j = 0; j < i; j++)
        {
            if (addressNumber[j]->getCity() > addressNumber[j + 1]->getCity())
            {
                temp = addressNumber[j];
                addressNumber[j] = addressNumber[j + 1];
                addressNumber[j + 1] = temp;
                sorted = false;
            }
        }

        if (sorted) {break;}
    }
}