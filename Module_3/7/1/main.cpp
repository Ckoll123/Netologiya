#include <iostream>
#include <string>
#include <exception>

int function(std::string str, int forbidden_length);

class ForbiddenLength : public std::exception
{
    const char* what() const noexcept override
    {return "Вы ввели слово запретной длины! До свидания";}
};

int main()
{
    int length;
    std::cout << "Введите запретную длину: ";
    std::cin >> length;

    while(1)
    {
        std::string inString;
        std::cout << "Введите слово: ";
        std::cin >> inString;
        try
        { 
            int wordLength = function(inString, length);
            std::cout << "Длина слова \"" << inString << "\" " << "равна " << wordLength << std::endl;
        }
        catch(std::exception& ex)
        {
            std::cerr << ex.what() << '\n';
            break;
        }
    }

}

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length)
    { throw ForbiddenLength(); }
    else return str.length();
}