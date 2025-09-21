#pragma once

#include <iostream>


struct Link{
    std::string host;
    std::string target;
    size_t currentRecursionDepth;

    Link() :
        host(),
        target(),
        currentRecursionDepth()
    {}

    Link (std::pair<std::string, std::string> url, size_t depth = 0) :
        host(url.first),
        target(url.second),
        currentRecursionDepth(depth)
    {}

    // Link(Link&& other) noexcept :
    //     host(std::move(other.host)),
    //     target(std::move(other.target)),
    //     currentRecursionDepth(std::move(other.currentRecursionDepth))
    // {
    //     other.host = "";
    //     other.target = "";
    //     other.currentRecursionDepth = 0;
    // }
};