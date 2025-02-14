#include "FiguresException.h"

FigureException::FigureException(std::string errorMsg) : 
    errorMessage(errorMsg)
{}

const char* FigureException::what() const noexcept
{ return errorMessage.c_str(); }