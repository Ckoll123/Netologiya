#pragma once

#include <string>
#include "AirTransport.h"

class Eagle : public AirTransport {
public:
    Eagle();
    virtual ~Eagle() override {};
    virtual float move(float distance) override;
};
