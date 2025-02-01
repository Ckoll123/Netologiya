#pragma once

#include <iostream>
#include "Figure.h"
#include "Quadrangle.h"

class Rhombus : public Quadrangle
{
public:
    Rhombus() : Rhombus("Параллелограмм", 30, 30, 40)
    {}

private:
    Rhombus(std::string figureName, unsigned sidesLenght, unsigned anglesAC, unsigned anglesBD) :
        Quadrangle(figureName, sidesLenght, anglesAC, anglesBD)
    {}
};