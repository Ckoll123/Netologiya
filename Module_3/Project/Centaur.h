#pragma once

#include <string>
#include "LandTransport.h"

class Centaur : public LandTransport {
public:
    Centaur();
    virtual ~Centaur() override {};
    virtual float move(float distance) override;
};
