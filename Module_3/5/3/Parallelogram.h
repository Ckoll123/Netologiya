#pragma once

#include <iostream>
#include "Figure.h"
#include "Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
    Parallelogram();

private:
    Parallelogram(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght, unsigned anglesAC, unsigned anglesBD);
};