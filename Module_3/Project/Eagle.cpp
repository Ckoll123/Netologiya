#include "Eagle.h"

Eagle::Eagle() : 
    AirTransport("Орёл", 8, 6)
{}


float Eagle::move(float distance){
    float travelingHours{0};

    distance *= (1 - (getDistanceReductionFactorInPercent() / 100));
    travelingHours = distance / getVelocity();

    return travelingHours;
}