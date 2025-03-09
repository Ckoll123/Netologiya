#include "AllTerrainBoots.h"

AllTerrainBoots::AllTerrainBoots() :
    LandTransport("Ботинки-вездеходы", 6, 60, 10),
    _restDurationLast(5)
{}


float AllTerrainBoots::move(float distance){
    float travelingHours{0};
    int stopsNumber{0};
    int restingTime{0};

    travelingHours = distance / getVelocity();
    stopsNumber = travelingHours / getTravelTimeToStop();
    restingTime = (stopsNumber - 1) * _restDurationLast + getRestDurationFirst();
    travelingHours += restingTime;

    return travelingHours;
}
