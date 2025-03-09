#pragma once

#include <string>
#include "Transport.h"

class LandTransport : public Transport{
public:
    LandTransport(std::string name, int velocity, int timeToRest, int restDurationFirst);
    int getTravelTimeToStop() const;
    int getRestDurationFirst() const;

    virtual float move(float distance) = 0;

private:
    int _travelTimeToStop;
    float _restDurationTimeFirst;
};
