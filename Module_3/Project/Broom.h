#pragma once

#include <string>
#include "AirTransport.h"

class Broom : public AirTransport {
public:
    Broom();
    virtual float move(float distance) override;
};
