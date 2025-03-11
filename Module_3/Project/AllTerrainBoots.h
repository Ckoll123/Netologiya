#pragma once

#include <string>
#include "LandTransport.h"

class AllTerrainBoots : public LandTransport {
public:
    AllTerrainBoots();
    virtual ~AllTerrainBoots() override {};
    virtual float move(float distance) override;

private:
    float _restDurationLast;
};
