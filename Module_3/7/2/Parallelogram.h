#pragma once

#include <iostream>
#include "Figure.h"
#include "Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
    Parallelogram();
    Parallelogram(unsigned sidesACLenght, unsigned sidesBDLenght, unsigned anglesAC, unsigned anglesBD);
};