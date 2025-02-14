#pragma once

#include <iostream>
#include "Figure.h"
#include "Triangle.h"

class RightTriangle : public Triangle
{
public:
    RightTriangle();
    RightTriangle(unsigned sideA, unsigned sideB, unsigned sideC, unsigned angleA, unsigned angleB);
};