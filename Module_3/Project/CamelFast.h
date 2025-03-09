#pragma once

#include <string>
#include "Camel.h"

class CamelFast : public Camel{
public:
    CamelFast();
    virtual float move(float distance) override;
    
private:
    float _restDurationTimeSecond;
};
