#pragma once

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