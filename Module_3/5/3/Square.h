#pragma once

#include <iostream>
#include "Figure.h"
#include "Quadrangle.h"

class Square : public Quadrangle
{
public:
    Square();

private:
    Square(std::string figureName, unsigned sidesLenght);
};