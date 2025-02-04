#pragma once

#include <iostream>
#include "Figure.h"
#include "Quadrangle.h"

class Rhombus : public Quadrangle
{
public:
    Rhombus();

private:
    Rhombus(std::string figureName, unsigned sidesLenght, unsigned anglesAC, unsigned anglesBD);
};