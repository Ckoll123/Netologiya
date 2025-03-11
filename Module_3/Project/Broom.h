#pragma once

#include <string>
#include "AirTransport.h"

class Broom : public AirTransport {
public:
    Broom();
    virtual ~Broom() override {};
    virtual float move(float distance) override;
};
