#include "Quadrangle.h"

Quadrangle::Quadrangle() : Figure("Четырёхугольник", 4),
    sideALenght(10),
    sideBLenght(20),
    sideCLenght(30),
    sideDLenght(40),
    angleA(50),
    angleB(60),
    angleC(70),
    angleD(80)
{}

void Quadrangle::printFigureInfo()
{
    Figure::printFigureInfo();
    std::cout << "Стороны: " << "a = " << sideALenght << " b = " << sideBLenght << " c = " << sideCLenght << " d = " << sideDLenght << std::endl;
    std::cout << "Углы: " << "A = " << angleA << " B = " << angleB << " C = " << angleC << " D = " << angleD << std::endl;
    std::cout << std::endl;
}

// Rectangle
Quadrangle::Quadrangle(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght) : Figure(figureName, 4),
    sideALenght(sidesACLenght),
    sideBLenght(sidesBDLenght),
    sideCLenght(sidesACLenght),
    sideDLenght(sidesBDLenght),
    angleA(90),
    angleB(90),
    angleC(90),
    angleD(90)
{}

// Square
Quadrangle::Quadrangle(std::string figureName, unsigned sidesLenght) : Figure(figureName, 4),
    sideALenght(sidesLenght),
    sideBLenght(sidesLenght),
    sideCLenght(sidesLenght),
    sideDLenght(sidesLenght),
    angleA(90),
    angleB(90),
    angleC(90),
    angleD(90)
{}

// Parallelogram
Quadrangle::Quadrangle(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght, unsigned anglesAC, unsigned anglesBD) : Figure(figureName, 4),
    sideALenght(sidesACLenght),
    sideBLenght(sidesBDLenght),
    sideCLenght(sidesACLenght),
    sideDLenght(sidesBDLenght),
    angleA(anglesAC),
    angleB(anglesBD),
    angleC(anglesAC),
    angleD(anglesBD)
{}

// Rhombus
Quadrangle::Quadrangle(std::string figureName, unsigned sidesLenght, unsigned anglesAC, unsigned anglesBD) : Figure(figureName, 4),
    sideALenght(sidesLenght),
    sideBLenght(sidesLenght),
    sideCLenght(sidesLenght),
    sideDLenght(sidesLenght),
    angleA(anglesAC),
    angleB(anglesBD),
    angleC(anglesAC),
    angleD(anglesBD)
{}

