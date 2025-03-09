#include "Transport.h"


Transport::Transport(std::string name, int velocity) :
    _name(name),
    _velocity(velocity)
{}

std::string Transport::getName() const {
    return _name;
}

int Transport::getVelocity() const{
    return _velocity;
}
