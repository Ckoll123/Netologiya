#include "Rhombus.h"

Rhombus::Rhombus() :
    Rhombus("Параллелограмм", 30, 30, 40)
{}

Rhombus::Rhombus(std::string figureName, unsigned sidesLenght, unsigned anglesAC, unsigned anglesBD) :
    Quadrangle(figureName, sidesLenght, anglesAC, anglesBD)
{}