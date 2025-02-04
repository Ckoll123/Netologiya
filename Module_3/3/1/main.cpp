#include <iostream>
#include <fstream>
#include <string>

class Address
{
public:
    Address() :
        city("Default"),
        street("Default"),
        building(1),
        room(1)
    {}
    Address(std::string cityInit, std::string streetInit, unsigned buildingInit, unsigned roomInnit) :
        city(cityInit),
        street(streetInit),
        building(buildingInit),
        room(roomInnit)
    {}

    void setCity(std::string);
    void setStreet(std::string);
    void setBuilding(unsigned);
    void setRoom(unsigned);

    std::string getAddress();

private:
    std::string city;
    std::string street;
    unsigned building;
    unsigned room;
};

void Address::setCity(std::string cityIn)
{ if (!std::empty(cityIn)) { city = cityIn; } }

void Address::setStreet(std::string StreetIn)
{ if (!std::empty(StreetIn)) { street = StreetIn; } }

void Address::setBuilding(unsigned buildingIn)
{ building = buildingIn;}

void Address::setRoom(unsigned roomIn)
{ room = roomIn; }

std::string Address::getAddress()
{
    std::string outAddress;
    outAddress = city + ", " + street + ", " + std::to_string(building) + ", " + std::to_string(room) + "\n";
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
        Address* addresses = new Address[numberOfAddresses];

        for (int i = 0; i < numberOfAddresses; i++)
        {
            std::string tempString;
            unsigned tempNumber;

            inputFile >> tempString;
            addresses[i].setCity(tempString);

            inputFile >> tempString;
            addresses[i].setStreet(tempString);

            inputFile >> tempNumber;
            addresses[i].setBuilding(tempNumber);

            inputFile >> tempNumber;
            addresses[i].setRoom(tempNumber);
        }

        std::ofstream outFile("out.txt");
        if (outFile.is_open())
        {
            outFile << numberOfAddresses << std::endl;
            for (int i = numberOfAddresses - 1; i >= 0; i--)
            {
                outFile << addresses[i].getAddress();
            }
            outFile.close();
        }
        inputFile.close();

        delete []addresses;
    }
    else {std::cout << "Не удалось открыть файл!" << std::endl;}

}