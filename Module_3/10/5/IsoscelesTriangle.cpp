#include "IsoscelesTriangle.h"


IsoscelesTriangle::IsoscelesTriangle() : 
    IsoscelesTriangle(10, 20, 50, 80)
{}

IsoscelesTriangle::IsoscelesTriangle(unsigned equalSidesLenght, unsigned lastSideLength, unsigned equalAngles, unsigned lastAngle) :
    Triangle(equalSidesLenght, lastSideLength, equalSidesLenght, equalAngles, lastAngle, equalAngles)
{
    name = "Равнобедренный треугольник";

    if (sideALenght != sideCLenght) throw FigureException("стороны a и c не равны");
    if (angleA != angleC) throw FigureException("углы A и C не равны");
}