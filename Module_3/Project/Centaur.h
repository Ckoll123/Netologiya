#pragma once

#include <string>
#include "LandTransport.h"

class Centaur : public LandTransport {
public:
    Centaur();
    virtual float move(float distance) override;
};
