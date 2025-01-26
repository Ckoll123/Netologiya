#include <iostream>


enum class Month : unsigned{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    std::cout << "Задача 1. Месяцы" << std::endl << std::endl;

    Month monthList;
    std::cout << "Введите номер месяца: ";
    int monthIn;
    std::cin >> monthIn;
    monthList = static_cast<Month>(monthIn);

    while (monthIn != 0)
    {
        switch (monthList)
        {
        case Month::January:
            std::cout << "Январь" << std:: endl;
            break;
        case Month::February:
            std::cout << "Февраль" << std:: endl;
            break;
        case Month::March:
            std::cout << "Март" << std:: endl;
            break;
        case Month::April:
            std::cout << "Апрель" << std:: endl;
            break;
        case Month::May:
            std::cout << "Май" << std:: endl;
            break;
        case Month::June:
            std::cout << "Июнь" << std:: endl;
            break;
        case Month::July:
            std::cout << "Июль" << std:: endl;
            break;
        case Month::August:
            std::cout << "Август" << std:: endl;
            break;
        case Month::September:
            std::cout << "Сентябрь" << std:: endl;
            break;
        case Month::October:
            std::cout << "Октябрь" << std:: endl;
            break;
        case Month::November:
            std::cout << "Ноябрь" << std:: endl;
            break;
        case Month::December:
            std::cout << "Декабрь" << std:: endl;
            break;

        default:
            std::cout << "Неправильный номер!" << std::endl;
            break;
        }

        std::cout << "Введите номер месяца: ";
        std::cin >> monthIn;
        monthList = static_cast<Month>(monthIn);
    }

    std::cout << "До свидания";
}