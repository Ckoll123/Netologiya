#include <iostream>

struct BankAccount{
    int accountNumber;
    std::string nameOfOwner;
    float moneyAmount;
};

void accountUpdate(BankAccount& accountToChange, float newAmountOfMoney);

int main()
{
    std::cout << "Задача 2. Счета" << std::endl << std::endl;

    BankAccount bankAccount1;
    std::cout << "Введите номер счёта: ";
    std::cin >> bankAccount1.accountNumber;
    std::cout << "Введите имя владельца: ";
    std::cin >> bankAccount1.nameOfOwner;
    std::cout << "Введите баланс: ";
    std::cin >> bankAccount1.moneyAmount;

    float moneyAmountUpdate;
    std::cout << "Введите новый баланс: ";
    std::cin >> moneyAmountUpdate;
    accountUpdate(bankAccount1, moneyAmountUpdate);

    std::cout << "Ваш счёт: " << bankAccount1.nameOfOwner << ", " << bankAccount1.accountNumber << ", " << bankAccount1.moneyAmount 
              << std::endl;
}

void accountUpdate(BankAccount& accountToChange, float newAmountOfMoney)
{
    accountToChange.moneyAmount = newAmountOfMoney;
}