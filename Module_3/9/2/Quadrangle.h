#pragma once

#include <iostream>
#include "Figure.h"
#include "FiguresException.h"

class Quadrangle : public Figure
{
public:
    Quadrangle();
    Quadrangle(unsigned sideA, unsigned sideB, unsigned sideC, unsigned sideD, unsigned angleA, unsigned angleB, unsigned angleC, unsigned angleD);
    void printFigureInfo() override;
    void printInfo() override;

protected:
    unsigned sideALenght;
    unsigned sideBLenght;
    unsigned sideCLenght;
    unsigned sideDLenght;

    unsigned angleA;
    unsigned angleB;
    unsigned angleC;
    unsigned angleD;
};