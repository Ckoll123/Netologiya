#pragma once

#include <iostream>
#include "Figure.h"

class Quadrangle : public Figure
{
public:
    Quadrangle();
    void printFigureInfo() override;

protected:

// Rectangle
    Quadrangle(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght);
// Square
    Quadrangle(std::string figureName, unsigned sidesLenght);
// Parallelogram
    Quadrangle(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght, unsigned anglesAC, unsigned anglesBD);
// Rhombus
    Quadrangle(std::string figureName, unsigned sidesLenght, unsigned anglesAC, unsigned anglesBD);

private:
    unsigned sideALenght;
    unsigned sideBLenght;
    unsigned sideCLenght;
    unsigned sideDLenght;

    unsigned angleA;
    unsigned angleB;
    unsigned angleC;
    unsigned angleD;
};