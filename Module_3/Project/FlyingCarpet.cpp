#include "FlyingCarpet.h"

FlyingCarpet::FlyingCarpet() : 
    AirTransport("Ковёр-самолёт", 10, 0)
{}


float FlyingCarpet::move(float distance){
    float travelingHours{0};

    if ((distance > 1000) && (distance < 5000)) setDistanceReductionFactorInPercent(3);
    else if (distance < 10000) setDistanceReductionFactorInPercent(10);
    else setDistanceReductionFactorInPercent(5);
    
    distance *= (1 - getDistanceReductionFactorInPercent());
    travelingHours = distance / getVelocity();

    return travelingHours;
}