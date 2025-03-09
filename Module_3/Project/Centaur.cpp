#include "Centaur.h"

Centaur::Centaur() :
    LandTransport("Кентавр", 15, 8, 2)
{}


float Centaur::move(float distance) {
    float travelingHours{0};
    int stopsNumber{0};
    int restingTime{0};

    travelingHours = distance / getVelocity();
    stopsNumber = travelingHours / getTravelTimeToStop();
    restingTime = stopsNumber * getRestDurationFirst();
    travelingHours += restingTime;

    return travelingHours;
}
