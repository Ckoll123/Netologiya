#pragma once

#include <iostream>
#include "Figure.h"
#include "Quadrangle.h"

class Square : public Quadrangle
{
public:
    Square() : Square("Квадрат", 10)
    {}

private:
    Square(std::string figureName, unsigned sidesLenght) : Quadrangle(figureName, sidesLenght)
    {}
};