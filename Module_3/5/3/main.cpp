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

    Figure figure;

    Triangle triangle;
    RightTriangle rightTriangle;
    IsoscelesTriangle isoscelesTriangle;
    EquilateralTriangle equilateralTriangle;

    Quadrangle quadrangle;
    Rectangle rectangle;
    Square square;
    Parallelogram parallelogram;
    Rhombus rhombus;

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
