#include "IsoscelesTriangle.h"


IsoscelesTriangle::IsoscelesTriangle() : 
    IsoscelesTriangle("Равнобедренный треугольник", 10, 50)
{}

IsoscelesTriangle::IsoscelesTriangle(std::string figureName, unsigned equalSidesLenght, unsigned equalAngleLength) :
    Triangle(figureName, equalSidesLenght, equalAngleLength)
{}