#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle() :
    EquilateralTriangle("Равносторонний треугольник", 30)
{}

EquilateralTriangle::EquilateralTriangle(std::string figureName, unsigned equalSidesLenght) :
    Triangle(figureName, 30, 0)
{}