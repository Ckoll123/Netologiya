#pragma once

#include <iostream>
#include "Figure.h"
#include "Triangle.h"

class RightTriangle : public Triangle
{
public:
    RightTriangle();

private:
    RightTriangle(std::string figureName, unsigned angleC);
};