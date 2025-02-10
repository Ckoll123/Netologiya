#include "Rectangle.h"

Rectangle::Rectangle() :
    Rectangle(10, 20)
{}

Rectangle::Rectangle(unsigned sidesACLenght, unsigned sidesBDLenght) :
    Quadrangle(sidesACLenght, sidesBDLenght, sidesACLenght, sidesBDLenght, 90, 90, 90, 90)
{
    name = "Прямоугольник";
    
    if ((sideALenght != sideCLenght) && (sideBLenght != sideDLenght)) throw FigureException("стороны a,c и b,d попарно не равны");
    if ((angleA != 90) && (angleB != 90) && (angleC != 90) && (angleD != 90)) throw FigureException("все углы должны быть равны 90");
}