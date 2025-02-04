#pragma once

#include <iostream>
#include "Figure.h"
#include "Quadrangle.h"

class Rectangle : public Quadrangle
{
public:
    Rectangle();

private:
    Rectangle(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght);
};