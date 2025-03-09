#include "Broom.h"

Broom::Broom() : 
    AirTransport("Метла", 10, 0)
{}


float Broom::move(float distance){
    float travelingHours{0};

    setDistanceReductionFactorInPercent(distance / 1000);
    
    distance *= (1 - getDistanceReductionFactorInPercent());
    travelingHours = distance / getVelocity();

    return travelingHours;
}