#pragma once

#include <string>
#include "LandTransport.h"

class Camel : public LandTransport {
public:
    Camel();
    virtual ~Camel() override {};
    float getRestDurationLast() const;

    virtual float move(float distance) override;

protected:
    Camel(std::string name, int velocity, int timeToRest, int restDurationFirst);
    
private:
    float _restDurationLast;
};
