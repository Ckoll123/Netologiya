#pragma once

#include <iostream>
#include "Triangle.h"

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle();
    IsoscelesTriangle(unsigned equalSidesLenght, unsigned lastSideLength, unsigned equalAngles, unsigned lastAngle);
};