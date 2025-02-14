#include "Rhombus.h"

Rhombus::Rhombus() :
    Rhombus(30, 30, 40)
{ name = "Ромб"; }

Rhombus::Rhombus(unsigned sidesLenght, unsigned anglesAC, unsigned anglesBD) :
    Parallelogram(sidesLenght, sidesLenght, anglesAC, anglesBD)
{
    name = "Ромб";
    
    if (sideBLenght != sideCLenght) throw FigureException("все стороны должны быть равны");
}