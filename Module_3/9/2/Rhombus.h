#pragma once

#include <iostream>
#include "Parallelogram.h"

class Rhombus : public Parallelogram
{
public:
    Rhombus();
    Rhombus(unsigned sidesLenght, unsigned anglesAC, unsigned anglesBD);
};