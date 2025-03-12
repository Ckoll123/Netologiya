#include "Camel.h"

Camel::Camel() : 
    LandTransport("Верблюд", 10, 30, 5),
    _restDurationLast(8)
{}


Camel::Camel(std::string name, int velocity, int timeToRest, int restDurationFirst) : 
    LandTransport(name, velocity, timeToRest, restDurationFirst),
    _restDurationLast(8)
{}


float Camel::getRestDurationLast() const {
    return _restDurationLast;
}


float Camel::move(float distance){
    float travelingHours{0};
    int stopsNumber{0};
    int restingTime{0};

    travelingHours = distance / getVelocity();
    stopsNumber = travelingHours / getTravelTimeToStop();
    if (stopsNumber){
        restingTime = (stopsNumber - 1) * _restDurationLast + getRestDurationFirst();
        if (!(static_cast<int>(travelingHours) % getTravelTimeToStop()))
            restingTime -= _restDurationLast;
        travelingHours += restingTime;
    }

    return travelingHours;
}



