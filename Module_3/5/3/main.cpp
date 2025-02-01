#include <iostream>

#include "Figure.h"

#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"

#include "Quadrangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"


void printInfo(Figure* figure)
{ figure->printFigureInfo(); }

int main()
{
    std::cout << "Задача 3. Иерархия классов" << std::endl << std::endl;

    class Figure figure;

    class Triangle triangle;
    class RightTriangle rightTriangle;
    class IsoscelesTriangle isoscelesTriangle;
    class EquilateralTriangle equilateralTriangle;

    class Quadrangle quadrangle;
    class Rectangle rectangle;
    class Square square;
    class Parallelogram parallelogram;
    class Rhombus rhombus;

    printInfo(&figure);
    std::cout << std::endl;

    printInfo(&triangle);
    printInfo(&rightTriangle);
    printInfo(&isoscelesTriangle);
    printInfo(&equilateralTriangle);

    printInfo(&quadrangle);
    printInfo(&rectangle);
    printInfo(&square);
    printInfo(&parallelogram);
    printInfo(&rhombus);
}
