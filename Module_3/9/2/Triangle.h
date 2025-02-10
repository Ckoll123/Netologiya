#pragma once

#include <iostream>
#include "Figure.h"
#include "FiguresException.h"

class Triangle : public Figure
{
public:
    Triangle();
    Triangle(unsigned sideA, unsigned sideB, unsigned sideC, unsigned angleA, unsigned angleB, unsigned angleC);
    void printFigureInfo() override;
    void printInfo() override;

protected:
    unsigned sideALenght;
    unsigned sideBLenght;
    unsigned sideCLenght;

    unsigned angleA;
    unsigned angleB;
    unsigned angleC;
};