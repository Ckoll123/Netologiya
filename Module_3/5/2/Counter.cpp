#include "Counter.h"

Counter::Counter():
    counterValue(1)
{}

Counter::Counter(int initValue):
    counterValue(initValue)
{}

void Counter::increment()
{ counterValue++; }

void Counter::decrement()
{ counterValue--; }

int Counter::showCurrentValue()
{ return counterValue; }
