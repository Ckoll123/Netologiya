#include "Figure.h"

Figure::Figure() :
    name("Фигура"),
    sides(0)
{}

Figure::Figure(unsigned figureSides) :
    sides(figureSides)
{}

Figure::Figure(std::string figureName, unsigned figureSides) :
    name(figureName),
    sides(figureSides)
{}

void Figure::printInfo()
{ std::cout << name << ": " << std::endl; }

void Figure::printFigureInfo()
{
    std::cout << name << ": " << std::endl;
    std::cout << "Стороны: " << sides << std::endl;
}