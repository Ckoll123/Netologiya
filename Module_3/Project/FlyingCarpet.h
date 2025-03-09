#pragma once

#include <string>
#include "AirTransport.h"

class FlyingCarpet : public AirTransport {
public:
    FlyingCarpet();
    virtual float move(float distance) override;
};