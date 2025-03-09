#pragma once

#include <string>
#include "LandTransport.h"

class AllTerrainBoots : public LandTransport {
public:
    AllTerrainBoots();
    virtual float move(float distance) override;

private:
    float _restDurationLast;
};
