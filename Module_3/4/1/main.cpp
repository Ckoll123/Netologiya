#include <iostream>

class Figure
{
public:
    Figure() :
        name("Фигура"),
        sides(0)
    {}
    void getNumberOfSides();

protected:
    Figure(std::string figureName, unsigned figureSides) :
        name(figureName),
        sides(figureSides)
    {}

private:
    std::string name;
    unsigned sides;
};


class Triangle : public Figure
{
public:
    Triangle() : Triangle("Треугольник", 3)
    {}

private:
    Triangle(std::string figureName, unsigned figureSides) : Figure(figureName, figureSides)
    {}

};


class Rectangle : public Figure
{
public:
    Rectangle() : Rectangle("Четырёхугольник", 4)
    {}

private:
    Rectangle(std::string figureName, unsigned figureSides) : Figure(figureName, figureSides)
    {}
    
};


int main()
{
    std::cout << "Задача 1. Фигуры. Количество сторон" << std::endl << std::endl;

    class Figure figure;
    class Triangle triangle;
    class Rectangle rectangle;

    std::cout << "Количество сторон:" << std::endl;
    figure.getNumberOfSides();
    triangle.getNumberOfSides();
    rectangle.getNumberOfSides();
}


void Figure::getNumberOfSides()
{ std::cout << name << ": " << sides << std::endl; }