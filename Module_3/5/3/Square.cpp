#include "Square.h"


Square::Square() :
    Square("Квадрат", 10)
{}

Square::Square(std::string figureName, unsigned sidesLenght) :
    Quadrangle(figureName, sidesLenght)
{}