#pragma once

#include <string>
#include "Transport.h"

class AirTransport : public Transport{
public:
    AirTransport(std::string name, int velocity, float distanceReductionFactorinPercent);
    int getDistanceReductionFactorInPercent() const;

    virtual float move(float distance) = 0;

protected:
    void setDistanceReductionFactorInPercent(float newFactor);

private:
    int _distanceReductionFactorInPercent;
};
