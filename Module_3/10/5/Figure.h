#pragma once

#include <iostream>

class Figure
{
public:
    Figure();
    virtual void printInfo();
    virtual void printFigureInfo();

protected:
    Figure(unsigned figureSides);
    Figure(std::string figureName, unsigned figureSides);

protected:
    std::string name;
    unsigned sides;
};