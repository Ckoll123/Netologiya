#include "LandTransport.h"

LandTransport::LandTransport(std::string name, int velocity, int movingTime, int restDurationFirst) :
    Transport(name, velocity),
    _travelTimeToStop(movingTime),
    _restDurationTimeFirst(restDurationFirst)
{}


int LandTransport::getTravelTimeToStop() const{
    return _travelTimeToStop;
}


int LandTransport::getRestDurationFirst() const{
    return _restDurationTimeFirst;
}
