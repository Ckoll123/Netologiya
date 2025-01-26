#include <iostream>

struct BankAccount{
    int accountNumber;
    std::string nameOfOwner;
    float moneyAmount;
};

void accountUpdate(BankAccount accountToChange, float newAmountOfMoney);

int main()
{
    std::cout << "Задача 2. Счета" << std::endl << std::endl;

    BankAccount bankAccount1;
    accountUpdate(bankAccount1, 2000);
}

void accountUpdate(BankAccount accountToChange, float newAmountOfMoney)
{
    std::cout << "Введите номер счёта: ";
    std::cin >> accountToChange.accountNumber;
    std::cout << "Введите имя владельца: ";
    std::cin >> accountToChange.nameOfOwner;
    std::cout << "Введите баланс: ";
    std::cin >> accountToChange.moneyAmount;
    std::cout << "Введите новый баланс: ";
    std::cin >> accountToChange.moneyAmount;
    std::cout << "Ваш счёт: " << accountToChange.nameOfOwner << ", " << accountToChange.accountNumber << ", " << accountToChange.moneyAmount 
              << std::endl;
}