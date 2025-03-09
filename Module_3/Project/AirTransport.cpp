#include "AirTransport.h"

AirTransport::AirTransport(std::string name, int velocity, float distanceReductionFactorInPercent) :
    Transport(name, velocity),
    _distanceReductionFactorInPercent(distanceReductionFactorInPercent)
{}


int AirTransport::getDistanceReductionFactorInPercent() const {
    return _distanceReductionFactorInPercent;
}

void AirTransport::setDistanceReductionFactorInPercent(float newFactor){
    if (newFactor >= 0) _distanceReductionFactorInPercent = newFactor;
}
