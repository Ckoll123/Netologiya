#pragma once

#include <string>
#include "AirTransport.h"

class Eagle : public AirTransport {
public:
    Eagle();
    virtual float move(float distance) override;
};
