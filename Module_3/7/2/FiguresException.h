#pragma once

#include <iostream>
#include <exception>

class FigureException : public std::exception
{
public:
    FigureException(std::string errorMsg);
    const char* what() const noexcept override;
private:
    std::string errorMessage;
};