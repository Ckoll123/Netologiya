#include "Triangle.h"

Triangle::Triangle() : Figure("Треугольник", 3),
    sideALenght(10),
    sideBLenght(20),
    sideCLenght(30),
    angleA(50),
    angleB(60),
    angleC(70)
{}

// RightTriangle
Triangle::Triangle(std::string figureName, unsigned angleC) : Figure(figureName, 3),
    sideALenght(10),
    sideBLenght(20),
    sideCLenght(30),
    angleA(50),
    angleB(60),
    angleC(angleC)
{}

// IsoscelesTriangle
Triangle::Triangle(std::string figureName, unsigned equalSidesLenght, unsigned equalAnglesLenght) : Figure(figureName, 3),
    sideALenght(equalSidesLenght),
    sideBLenght(20),
    sideCLenght(equalSidesLenght),
    angleA(equalAnglesLenght),
    angleB(60),
    angleC(equalAnglesLenght)
{}

// EquilateralTriangle
Triangle::Triangle(std::string figureName, unsigned equalSidesLenght, int) : Figure(figureName, 3),
    sideALenght(equalSidesLenght),
    sideBLenght(equalSidesLenght),
    sideCLenght(equalSidesLenght),
    angleA(60),
    angleB(60),
    angleC(60)
{}

void Triangle::printFigureInfo()
{
    Figure::printFigureInfo();
    std::cout << "Стороны: " << "a = " << sideALenght << " b = " << sideBLenght << " c = " << sideCLenght << std::endl;
    std::cout << "Углы: " << "A = " << angleA << " B = " << angleB << " C = " << angleC << std::endl;
    std::cout << std::endl;
}