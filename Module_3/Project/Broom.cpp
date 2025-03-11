#include "Broom.h"

Broom::Broom() : 
    AirTransport("Метла", 20, 0)
{}


float Broom::move(float distance){
    float travelingHours{0};

    setDistanceReductionFactorInPercent(distance / 1000);
    
    distance *= (1 - (getDistanceReductionFactorInPercent() / 100));
    travelingHours = distance / getVelocity();

    return travelingHours;
}