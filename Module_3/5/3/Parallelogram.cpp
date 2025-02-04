#include "Parallelogram.h"

Parallelogram::Parallelogram() :
    Parallelogram("Параллелограмм", 20, 30, 30, 40)
{}


Parallelogram::Parallelogram(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght, unsigned anglesAC, unsigned anglesBD) :
    Quadrangle(figureName, sidesACLenght, sidesBDLenght, anglesAC, anglesBD)
{}