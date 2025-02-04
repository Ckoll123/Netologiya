#include "RightTriangle.h"

RightTriangle::RightTriangle() :
    RightTriangle("Прямоугольный треугольник", 90)
{}


RightTriangle::RightTriangle(std::string figureName, unsigned angleC) :
    Triangle(figureName, angleC)
{}