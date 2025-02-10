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
{ figure->printInfo(); }

// void printFigureInfo(Figure* figure)
// { figure->printFigureInfo(); }

int main()
{
    std::cout << "Задача 3. Иерархия классов" << std::endl << std::endl;

    Figure* figure = nullptr;
    Figure* triangle = nullptr;
    Figure* rightTriangle = nullptr;
    Figure* isoscelesTriangle = nullptr;
    Figure* equilateralTriangle = nullptr;
    
    Figure* quadrangle = nullptr;
    Figure* rectangle = nullptr;
    Figure* square = nullptr;
    Figure* parallelogram = nullptr;
    Figure* rhombus = nullptr;

    try
    { 
        triangle = new Triangle(10, 20, 30, 40, 50, 90);
        printInfo(triangle);
    }
    catch(const std::exception& e)
    { std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << '\n'; }
    
    try
    { 
        rightTriangle = new RightTriangle(30, 20, 10, 40, 60);
        printInfo(rightTriangle);
    }
    catch(const std::exception& e)
    { std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << '\n'; }
    
    try
    { 
        isoscelesTriangle = new IsoscelesTriangle;
        printInfo(isoscelesTriangle);
    }
    catch(const std::exception& e)
    { std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << '\n'; }
    
    try
    { 
        equilateralTriangle = new EquilateralTriangle;
        printInfo(equilateralTriangle);
    }
    catch(const std::exception& e)
    { std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << '\n'; }
    
    
//----------------------------------------Quadrangles------------------------------------------

    try
    { 
        quadrangle = new Quadrangle;
        printInfo(quadrangle);
    }
    catch(const std::exception& e)
    { std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << '\n'; }
    
    try
    { 
        rectangle = new Rectangle;
        printInfo(rectangle);
    }
    catch(const std::exception& e)
    { std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << '\n'; }
    
    try
    { 
        square = new Square; 
        printInfo(square);
    }
    catch(const std::exception& e)
    { std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << '\n'; }
    
    try
    { 
        parallelogram = new Parallelogram;
        printInfo(parallelogram);
    }
    catch(const std::exception& e)
    { std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << '\n'; }
    
    try
    { 
        rhombus = new Rhombus;
        printInfo(rhombus);
    }
    catch(const std::exception& e)
    { std::cerr << "Ошибка создания фигуры. Причина: " << e.what() << '\n'; }


    delete figure;
    delete triangle;
    delete rightTriangle;
    delete isoscelesTriangle;
    delete equilateralTriangle;
    delete quadrangle;
    delete rectangle;
    delete square;
    delete parallelogram;
    delete rhombus;
}

