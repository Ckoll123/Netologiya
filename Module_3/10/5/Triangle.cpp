#include "Triangle.h"

Triangle::Triangle() : Figure(3),
    sideALenght(10),
    sideBLenght(20),
    sideCLenght(30),
    angleA(50),
    angleB(60),
    angleC(70)
{
    name = "Треугольник";

    try
    {
        if (sides != 3) throw FigureException("количество граней не равно 3");
        if (angleA + angleB + angleC != 180) throw FigureException("сумма углов не равна 180");
    }
    catch(const std::exception& e)
    { 
        std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << '\n'; 
        Triangle::~Triangle();
    }
}

Triangle::Triangle(unsigned sideA, unsigned sideB, unsigned sideC, unsigned angleA, unsigned angleB, unsigned angleC) : Figure(3),
    sideALenght(sideA),
    sideBLenght(sideB),
    sideCLenght(sideC),
    angleA(angleA),
    angleB(angleB),
    angleC(angleC)
{
    name = "Треугольник";
    
    if (sides != 3) throw FigureException("количество граней не равно 3");
    if (angleA + angleB + angleC != 180) throw FigureException("сумма углов не равна 180");
}


void Triangle::printInfo()
{
    std::cout << name << " (стороны " << sideALenght << ", " 
                                      << sideBLenght << ", "
                                      << sideCLenght << "; "
                           << "углы " << angleA << ", "
                                      << angleB << ", "
                                      << angleC << ") создан" << std::endl;
}

void Triangle::printFigureInfo()
{
    Figure::printFigureInfo();
    std::cout << "Стороны: " << "a = " << sideALenght << " b = " << sideBLenght << " c = " << sideCLenght << std::endl;
    std::cout << "Углы: " << "A = " << angleA << " B = " << angleB << " C = " << angleC << std::endl;
    std::cout << std::endl;
}