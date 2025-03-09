#pragma once

#include <iostream>

#include "RaceCoordinator.h"


enum class States{
    IDLE,
    START,
    DISTANCE_CHOISE,
    REGISTRATION,
    EXIT
};


class FSM{
public:
    FSM();
    void run();

private:
    void start();
    void distanceChoise();

private:
    States state;
    void (FSM::*ptrFunc)();
    race::RaceCoordinator raceCoordinator;
};
