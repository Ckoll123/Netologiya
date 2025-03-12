#include "CamelFast.h"

CamelFast::CamelFast() :
    Camel("Верблюд-быстроход", 40, 10, 5),
    _restDurationTimeSecond(6.5)
{}


float CamelFast::move(float distance){
    float travelingHours{0};
    int stopsNumber{0};
    int restingTime{0};

    travelingHours = distance / getVelocity();
    stopsNumber = travelingHours / getTravelTimeToStop();
    if (stopsNumber){
        if (stopsNumber >= 2)
            restingTime = (stopsNumber - 2) * getRestDurationLast() + getRestDurationFirst() + _restDurationTimeSecond;
        else
            restingTime = getRestDurationFirst() + _restDurationTimeSecond;
        
        if (!(static_cast<int>(travelingHours) % getTravelTimeToStop()))
        restingTime -= getRestDurationLast();
        travelingHours += restingTime;
    }

    return travelingHours;
}
