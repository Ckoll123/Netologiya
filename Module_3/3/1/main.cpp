#include <iostream>
#include <fstream>
#include <string>


struct initAddress
{
    std::string city;
    std::string street;
    unsigned building;
    unsigned room;

    initAddress() :
        city(""),
        street(""),
        building(0),
        room(0)
    {}
};

class Address
{
public:
    Address(initAddress& inData) :
        _city(inData.city),
        _street(inData.street),
        _building(inData.building),
        _room(inData.room)
    {}

    std::string getAddress() const;

private:
    std::string _city;
    std::string _street;
    unsigned _building;
    unsigned _room;
};


std::string Address::getAddress() const
{
    std::string outAddress;
    outAddress = _city + ", " + _street + ", " + std::to_string(_building) + ", " + std::to_string(_room) + "\n";
    return outAddress;
}


int main()
{
    std::cout << "Задача 1. Адреса" << std::endl << std::endl;

    std::ifstream inputFile("in.txt");

    if (inputFile.is_open())
    {
        int numberOfAddresses;
        inputFile >> numberOfAddresses;
        Address** addresses = new Address* [numberOfAddresses];

        for (int i = 0; i < numberOfAddresses; i++)
        {
            initAddress inData;

            inputFile >> inData.city;
            inputFile >> inData.street;
            inputFile >> inData.building;
            inputFile >> inData.room;
            addresses[i] = new Address(inData);
        }

        std::ofstream outFile("out.txt");
        if (outFile.is_open())
        {
            outFile << numberOfAddresses << std::endl;
            for (int i = numberOfAddresses - 1; i >= 0; i--)
            { outFile << addresses[i]->getAddress(); }

            outFile.close();
        }
        inputFile.close();

        for (int i = 0; i < numberOfAddresses; i++)
        { delete addresses[i]; }
        delete []addresses;
    }
    else {std::cout << "Не удалось открыть файл!" << std::endl;}

}