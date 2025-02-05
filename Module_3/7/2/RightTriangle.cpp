#include "RightTriangle.h"

RightTriangle::RightTriangle() :
    RightTriangle(10, 20, 30, 70, 80)
{}


RightTriangle::RightTriangle(unsigned sideA, unsigned sideB, unsigned sideC, unsigned angleA, unsigned angleB) :
    Triangle(sideA, sideB, sideC, angleA, angleB, 90)
{
    name = "Прямоугольный треугольник";

    if (angleC != 90) throw FigureException("угол C не равен 90");
}