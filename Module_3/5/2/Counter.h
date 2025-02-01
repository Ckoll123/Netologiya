#pragma once

#include <iostream>

class Counter{
public:
    Counter();
    Counter(int initValue);
    void increment();
    void decrement();
    int showCurrentValue();

private:
    int counterValue;
};