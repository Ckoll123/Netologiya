#pragma once

#include <iostream>
#include "Figure.h"
#include "Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle();

private:
    IsoscelesTriangle(std::string figureName, unsigned equalSidesLenght, unsigned equalAngleLength);
};