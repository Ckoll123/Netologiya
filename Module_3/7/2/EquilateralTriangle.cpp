#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle() :
    EquilateralTriangle(30)
{}

EquilateralTriangle::EquilateralTriangle(unsigned equalSidesLenght) :
    IsoscelesTriangle(equalSidesLenght, equalSidesLenght, 60, 60)
{
    name = "Равносторонний треугольник";
    if (sideALenght != sideBLenght) throw FigureException("все стороны не равны");
    if ((angleA != angleB) && (angleA != 60)) throw FigureException("углы не равны 60");
}