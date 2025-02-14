#include "Parallelogram.h"

Parallelogram::Parallelogram() :
    Parallelogram(20, 30, 30, 40)
{ name = "Параллелограмм"; }


Parallelogram::Parallelogram(unsigned sidesACLenght, unsigned sidesBDLenght, unsigned anglesAC, unsigned anglesBD) :
    Quadrangle(sidesACLenght, sidesBDLenght, sidesACLenght, sidesBDLenght, anglesAC, anglesBD, anglesAC, anglesBD)
{
    name = "Параллелограмм";
    
    if ((sideALenght != sideCLenght) && (sideBLenght != sideDLenght)) throw FigureException("стороны a,c и b,d попарно не равны");
    if ((angleA != angleC) && (angleB != angleD)) throw FigureException("углы A,C и B,D попарно не равны");
}