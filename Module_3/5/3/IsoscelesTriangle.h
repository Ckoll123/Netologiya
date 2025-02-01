#pragma once

#include <iostream>
#include "Figure.h"
#include "Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle() : IsoscelesTriangle("Равнобедренный треугольник", 10, 50)
    {}

private:
    IsoscelesTriangle(std::string figureName, unsigned equalSidesLenght, unsigned equalAngleLength) :
        Triangle(figureName, equalSidesLenght, equalAngleLength)
    {}
};