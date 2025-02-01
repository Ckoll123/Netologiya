#pragma once

#include <iostream>
#include "Figure.h"
#include "Triangle.h"

class RightTriangle : public Triangle
{
public:
    RightTriangle() : RightTriangle("Прямоугольный треугольник", 90)
    {}

private:
    RightTriangle(std::string figureName, unsigned angleC) : Triangle(figureName, angleC)
    {}
};