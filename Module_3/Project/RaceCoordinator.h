#pragma once

#include <string>
#include <stdexcept>
#include <vector>

#include "Transport.h"
#include "LandTransport.h"
#include "AirTransport.h"
#include "AllTerrainBoots.h"
#include "Broom.h"
#include "Camel.h"
#include "Centaur.h"
#include "Eagle.h"
#include "CamelFast.h"
#include "FlyingCarpet.h"

namespace race {

enum class RaceType{
    NONE,
    LAND,
    AIR,
    ALL_TERRAIN
};


enum class Participants{
    ALL_TERRAIN_BOOTS = 1,
    BROOM,
    CAMEL,
    CENTAUR,
    EAGLE,
    CAMEL_FAST,
    FLYING_CARPET
};

struct ParticipantData{
    Transport* participant;
    float result;
};



class RaceCoordinator{
public:
    RaceCoordinator();
    ~RaceCoordinator();
    void setRaceType(int type);
    RaceType getRaceType() const;
    void setDistance(float distance);
    int getDistance() const;
    void addParticipant(int participant);
    int getParticipantsNumber();
    std::string getParticipantName(int number) const;
    std::string getLastParticipantName() const;
    void raceStart();
    float getPatricipantResult(int number);

private:
    void sortResultsFastestFirst();

private:
    RaceType _raceType;
    float _distance;
    int _numberOfParticipants;
    std::vector<ParticipantData> _raceParticipants;

    int _bootsCounter;
    int _broomCounter;
    int _camelCounter;
    int _centaurCounter;
    int _eagleCounter;
    int _camelFastCounter;
    int _carpetCounter;

    // AllTerrainBoots* _ptrBoots;
    // Broom* _ptrBroom;
    // Camel* _ptrCamel;
    // Centaur* _ptrCentaur;
    // Eagle* _ptrEagle;
    // CamelFast* _ptrCamelFast;
    // FlyingCarpet* _ptrCarpet;
};

}   // race namespace
