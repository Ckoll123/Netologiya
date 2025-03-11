#include "AirTransport.h"

AirTransport::AirTransport(std::string name, int velocity, float distanceReductionFactorInPercent) :
    Transport(name, velocity),
    _distanceReductionFactorInPercent(distanceReductionFactorInPercent)
{}


float AirTransport::getDistanceReductionFactorInPercent() const {
    return _distanceReductionFactorInPercent;
}

void AirTransport::setDistanceReductionFactorInPercent(float newFactor){
    if (newFactor >= 0) _distanceReductionFactorInPercent = static_cast<int>(newFactor);
}
