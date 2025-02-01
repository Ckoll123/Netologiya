#pragma once

#include <iostream>
#include "Figure.h"
#include "Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
    Parallelogram() : Parallelogram("Параллелограмм", 20, 30, 30, 40)
    {}

private:
    Parallelogram(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght, unsigned anglesAC, unsigned anglesBD) :
        Quadrangle(figureName, sidesACLenght, sidesBDLenght, anglesAC, anglesBD)
    {}
};