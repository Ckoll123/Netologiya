#pragma once

#include <iostream>
#include "Figure.h"
#include "Triangle.h"

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle();

private:
    EquilateralTriangle(std::string figureName, unsigned equalSidesLenght);
};