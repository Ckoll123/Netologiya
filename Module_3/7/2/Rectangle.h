#pragma once

#include <iostream>
#include "Quadrangle.h"

class Rectangle : public Quadrangle
{
public:
    Rectangle();
    Rectangle(unsigned sidesACLenght, unsigned sidesBDLenght);
};