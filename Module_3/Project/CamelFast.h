#pragma once

#include <string>
#include "Camel.h"

class CamelFast : public Camel{
public:
    CamelFast();
    virtual ~CamelFast() override {};
    virtual float move(float distance) override;
    
private:
    float _restDurationTimeSecond;
};
