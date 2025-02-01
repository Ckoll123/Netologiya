#pragma once

#include <iostream>
#include "Figure.h"
#include "Quadrangle.h"

class Rectangle : public Quadrangle
{
public:
    Rectangle() : Rectangle("Прямоугольник", 10, 20)
    {}

private:
    Rectangle(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght) :
        Quadrangle(figureName, sidesACLenght, sidesBDLenght)
    {}
};