#pragma once

#include <string>

class Transport{
public:
    Transport(std::string name, int velocity);
    std::string getName() const;
    int getVelocity() const;

    virtual float move(float distance) = 0;

private:
    std::string _name;
    int _velocity;
};