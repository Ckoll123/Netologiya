#include "Rectangle.h"

Rectangle::Rectangle() :
    Rectangle("Прямоугольник", 10, 20)
{}

Rectangle::Rectangle(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght) :
    Quadrangle(figureName, sidesACLenght, sidesBDLenght)
{}