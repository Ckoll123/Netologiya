#include "Quadrangle.h"

Quadrangle::Quadrangle() : Figure(4),
    sideALenght(10),
    sideBLenght(20),
    sideCLenght(30),
    sideDLenght(40),
    angleA(50),
    angleB(60),
    angleC(70),
    angleD(80)
{name = "Четырёхугольник";}


Quadrangle::Quadrangle(unsigned sideA, unsigned sideB, unsigned sideC, unsigned sideD, unsigned angleA, unsigned angleB, unsigned angleC, unsigned angleD) : Figure(4),
    sideALenght(sideA),
    sideBLenght(sideB),
    sideCLenght(sideC),
    sideDLenght(sideD),
    angleA(angleA),
    angleB(angleB),
    angleC(angleC),
    angleD(angleD)
{
    name = "Четырёхугольник";

    if (sides != 4) throw FigureException("количество граней не равно 4");
    if (angleA + angleB + angleC + angleD != 360) throw FigureException("сумма углов не равна 360");
}


void Quadrangle::printInfo()
{
    std::cout << name << " (стороны " << sideALenght << ", " 
                                      << sideBLenght << ", "
                                      << sideCLenght << ", "
                                      << sideDLenght << "; "
                           << "углы " << angleA << ", "
                                      << angleB << ", "
                                      << angleC << ", "
                                      << angleD << ") создан" << std::endl;
}

void Quadrangle::printFigureInfo()
{
    Figure::printFigureInfo();
    std::cout << "Стороны: " << "a = " << sideALenght << " b = " << sideBLenght << " c = " << sideCLenght << " d = " << sideDLenght << std::endl;
    std::cout << "Углы: " << "A = " << angleA << " B = " << angleB << " C = " << angleC << " D = " << angleD << std::endl;
    std::cout << std::endl;
}
