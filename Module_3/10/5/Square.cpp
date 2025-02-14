#include "Square.h"


Square::Square() :
    Square(10)
{ name = "Квадрат"; }

Square::Square(unsigned sidesLenght) :
    Rectangle(sidesLenght, sidesLenght)
{
    name = "Квадрат";
    if (sideBLenght != sideCLenght) throw FigureException("все стороны должны быть равны");
}