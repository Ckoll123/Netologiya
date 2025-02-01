#pragma once

#include <iostream>
#include "Figure.h"

class Triangle : public Figure
{
public:
    Triangle();
    void printFigureInfo() override;

protected:

// RightTriangle
    Triangle(std::string figureName, unsigned angleC);

// IsoscelesTriangle
    Triangle(std::string figureName, unsigned equalSidesLenght, unsigned equalAnglesLenght);

// EquilateralTriangle
    Triangle(std::string figureName, unsigned equalSidesLenght, int);


private:
    unsigned sideALenght;
    unsigned sideBLenght;
    unsigned sideCLenght;

    unsigned angleA;
    unsigned angleB;
    unsigned angleC;
};