#pragma once

#include <iostream>
#include "Figure.h"
#include "Triangle.h"

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle() : EquilateralTriangle("Равносторонний треугольник", 30)
    {}

private:
    EquilateralTriangle(std::string figureName, unsigned equalSidesLenght) : Triangle(figureName, 30, 0)
    {}
};