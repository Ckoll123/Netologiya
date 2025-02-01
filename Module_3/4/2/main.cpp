#include <iostream>

class Figure
{
public:
    Figure() :
        name("Фигура"),
        sides(0)
    {}
    virtual void printFigureInfo();

protected:
    Figure(std::string figureName, unsigned figureSides) :
        name(figureName),
        sides(figureSides)
    {}

private:
    std::string name;
    unsigned sides;
};

void Figure::printFigureInfo()
{ std::cout << name << ": " << std::endl; }


//--------------------------------------Triangles-----------------------------------------------

class Triangle : public Figure
{
public:
    Triangle() : Figure("Треугольник", 3),
        sideALenght(10),
        sideBLenght(20),
        sideCLenght(30),
        angleA(50),
        angleB(60),
        angleC(70)
    {}

    void printFigureInfo() override;

protected:

// RightTriangle
    Triangle(std::string figureName, unsigned angleC) : Figure(figureName, 3),
        sideALenght(10),
        sideBLenght(20),
        sideCLenght(30),
        angleA(50),
        angleB(60),
        angleC(angleC)
    {}

// IsoscelesTriangle
    Triangle(std::string figureName, unsigned equalSidesLenght, unsigned equalAnglesLenght) : Figure(figureName, 3),
        sideALenght(equalSidesLenght),
        sideBLenght(20),
        sideCLenght(equalSidesLenght),
        angleA(equalAnglesLenght),
        angleB(60),
        angleC(equalAnglesLenght)
    {}

// EquilateralTriangle
    Triangle(std::string figureName, unsigned equalSidesLenght, int) : Figure(figureName, 3),
        sideALenght(equalSidesLenght),
        sideBLenght(equalSidesLenght),
        sideCLenght(equalSidesLenght),
        angleA(60),
        angleB(60),
        angleC(60)
    {}


private:
    unsigned sideALenght;
    unsigned sideBLenght;
    unsigned sideCLenght;

    unsigned angleA;
    unsigned angleB;
    unsigned angleC;
};

void Triangle::printFigureInfo()
{
    Figure::printFigureInfo();
    std::cout << "Стороны: " << "a = " << sideALenght << " b = " << sideBLenght << " c = " << sideCLenght << std::endl;
    std::cout << "Углы: " << "A = " << angleA << " B = " << angleB << " C = " << angleC << std::endl;
    std::cout << std::endl;
}


class RightTriangle : public Triangle
{
public:
    RightTriangle() : RightTriangle("Прямоугольный треугольник", 90)
    {}

private:
    RightTriangle(std::string figureName, unsigned angleC) : Triangle(figureName, angleC)
    {}
};


class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle() : IsoscelesTriangle("Равнобедренный треугольник", 10, 50)
    {}

private:
    IsoscelesTriangle(std::string figureName, unsigned equalSidesLenght, unsigned equalAngleLength) :
        Triangle(figureName, equalSidesLenght, equalAngleLength)
    {}
};


class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle() : EquilateralTriangle("Равносторонний треугольник", 30)
    {}

private:
    EquilateralTriangle(std::string figureName, unsigned equalSidesLenght) : Triangle(figureName, 30, 0)
    {}
};


//--------------------------------------Quadrangles-----------------------------------------------

class Quadrangle : public Figure
{
public:
    Quadrangle() : Figure("Четырёхугольник", 4),
        sideALenght(10),
        sideBLenght(20),
        sideCLenght(30),
        sideDLenght(40),
        angleA(50),
        angleB(60),
        angleC(70),
        angleD(80)
    {}

    void printFigureInfo() override;
    void func()
    {}

protected:

// Rectangle
    Quadrangle(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght) : Figure(figureName, 4),
        sideALenght(sidesACLenght),
        sideBLenght(sidesBDLenght),
        sideCLenght(sidesACLenght),
        sideDLenght(sidesBDLenght),
        angleA(90),
        angleB(90),
        angleC(90),
        angleD(90)
    {}

// Square
    Quadrangle(std::string figureName, unsigned sidesLenght) : Figure(figureName, 4),
        sideALenght(sidesLenght),
        sideBLenght(sidesLenght),
        sideCLenght(sidesLenght),
        sideDLenght(sidesLenght),
        angleA(90),
        angleB(90),
        angleC(90),
        angleD(90)
    {}

// Parallelogram
    Quadrangle(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght, unsigned anglesAC, unsigned anglesBD) : Figure(figureName, 4),
        sideALenght(sidesACLenght),
        sideBLenght(sidesBDLenght),
        sideCLenght(sidesACLenght),
        sideDLenght(sidesBDLenght),
        angleA(anglesAC),
        angleB(anglesBD),
        angleC(anglesAC),
        angleD(anglesBD)
    {}

// Rhombus
    Quadrangle(std::string figureName, unsigned sidesLenght, unsigned anglesAC, unsigned anglesBD) : Figure(figureName, 4),
        sideALenght(sidesLenght),
        sideBLenght(sidesLenght),
        sideCLenght(sidesLenght),
        sideDLenght(sidesLenght),
        angleA(anglesAC),
        angleB(anglesBD),
        angleC(anglesAC),
        angleD(anglesBD)
    {}

private:
    unsigned sideALenght;
    unsigned sideBLenght;
    unsigned sideCLenght;
    unsigned sideDLenght;

    unsigned angleA;
    unsigned angleB;
    unsigned angleC;
    unsigned angleD;
};

void Quadrangle::printFigureInfo()
{
    Figure::printFigureInfo();
    std::cout << "Стороны: " << "a = " << sideALenght << " b = " << sideBLenght << " c = " << sideCLenght << " d = " << sideDLenght << std::endl;
    std::cout << "Углы: " << "A = " << angleA << " B = " << angleB << " C = " << angleC << " D = " << angleD << std::endl;
    std::cout << std::endl;
}


class Rectangle : public Quadrangle
{
public:
    Rectangle() : Rectangle("Прямоугольник", 10, 20)
    {}

private:
    Rectangle(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght) :
        Quadrangle(figureName, sidesACLenght, sidesBDLenght)
    {}
};


class Square : public Quadrangle
{
public:
    Square() : Square("Квадрат", 10)
    {}

private:
    Square(std::string figureName, unsigned sidesLenght) : Quadrangle(figureName, sidesLenght)
    {}
};


class Parallelogram : public Quadrangle
{
public:
    Parallelogram() : Parallelogram("Параллелограмм", 20, 30, 30, 40)
    {}

private:
    Parallelogram(std::string figureName, unsigned sidesACLenght, unsigned sidesBDLenght, unsigned anglesAC, unsigned anglesBD) :
        Quadrangle(figureName, sidesACLenght, sidesBDLenght, anglesAC, anglesBD)
    {}
};


class Rhombus : public Quadrangle
{
public:
    Rhombus() : Rhombus("Параллелограмм", 30, 30, 40)
    {}

private:
    Rhombus(std::string figureName, unsigned sidesLenght, unsigned anglesAC, unsigned anglesBD) :
        Quadrangle(figureName, sidesLenght, anglesAC, anglesBD)
    {}
};


void printInfo(Figure* figure)
{ figure->printFigureInfo(); }

int main()
{
    std::cout << "Задача 2. Фигуры. Стороны и углы" << std::endl << std::endl;

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
