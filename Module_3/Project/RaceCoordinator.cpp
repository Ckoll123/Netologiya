#include "RaceCoordinator.h"

namespace race {

RaceCoordinator::RaceCoordinator() :
    _raceType(RaceType::NONE),
    _distance(0),
    _numberOfParticipants(0),
    _raceParticipants(),
    _bootsCounter(0),
    _broomCounter(0),
    _camelCounter(0),
    _centaurCounter(0),
    _eagleCounter(0),
    _camelFastCounter(0),
    _carpetCounter(0)
{}

RaceCoordinator::~RaceCoordinator(){
    for (ParticipantData& participantData : _raceParticipants){
        delete participantData.participant;
    }
}


void RaceCoordinator::setRaceType(int type){
    _raceType = static_cast<RaceType>(type);
}


RaceType RaceCoordinator::getRaceType() const{
    // return static_cast<int>(_raceType);
    return _raceType;
}


void RaceCoordinator::setDistance(float distance){
    if (distance > 0) 
        _distance = distance;
    else 
        throw std::invalid_argument("Длина дистанции должна быть положительная");
}


int RaceCoordinator::getDistance() const{
    return _distance;
}


void RaceCoordinator::addParticipant(int participant){

    Participants member = static_cast<Participants>(participant);
    switch (member)
    {
        case Participants::ALL_TERRAIN_BOOTS:
            if (_raceType == RaceType::AIR){
                throw std::invalid_argument( "Попытка зарегистрировать неправильный тип транспортного средства!");
            }

            if (!_bootsCounter){
                _raceParticipants.push_back(ParticipantData() = { .participant = new AllTerrainBoots(), .result = 0 });
                _bootsCounter++;
                _numberOfParticipants++;
            }
            else 
                throw std::invalid_argument( AllTerrainBoots().getName() + " уже зарегестрированы");
            break;

        case Participants::BROOM:
            if (_raceType == RaceType::LAND){
                throw std::invalid_argument( "Попытка зарегистрировать неправильный тип транспортного средства!");
            }

            if (!_broomCounter){
                _raceParticipants.push_back(ParticipantData() = { .participant = new Broom(), .result = 0 });
                _broomCounter++;
                _numberOfParticipants++;
            }
            else 
                throw std::invalid_argument( Broom().getName() + " уже зарегестрирована");
            break;

        case Participants::CAMEL:
            if (_raceType == RaceType::AIR){
                throw std::invalid_argument( "Попытка зарегистрировать неправильный тип транспортного средства!");
            }

            if (!_camelCounter){
                _raceParticipants.push_back(ParticipantData() = { .participant = new Camel(), .result = 0 });
                _camelCounter++;
                _numberOfParticipants++;
            }
            else 
                throw std::invalid_argument( Camel().getName() + " уже зарегестрирован");
            break;

        case Participants::CENTAUR:
            if (_raceType == RaceType::AIR){
                throw std::invalid_argument( "Попытка зарегистрировать неправильный тип транспортного средства!");
            }

            if (!_centaurCounter){
                _raceParticipants.push_back(ParticipantData() = { .participant = new Centaur(), .result = 0 });
                _centaurCounter++;
                _numberOfParticipants++;
            }
            else 
                throw std::invalid_argument( Centaur().getName() + " уже зарегестрирован");
            break;

        case Participants::EAGLE:
            if (_raceType == RaceType::LAND){
                throw std::invalid_argument( "Попытка зарегистрировать неправильный тип транспортного средства!");
            }

            if (!_eagleCounter){
                _raceParticipants.push_back(ParticipantData() = { .participant = new Eagle(), .result = 0 });
                _eagleCounter++;
                _numberOfParticipants++;
            }
            else 
                throw std::invalid_argument( Eagle().getName() + " уже зарегестрирован");
            break;

        case Participants::CAMEL_FAST:
            if (_raceType == RaceType::AIR){
                throw std::invalid_argument( "Попытка зарегистрировать неправильный тип транспортного средства!");
            }

            if (!_camelFastCounter){
                _raceParticipants.push_back(ParticipantData() = { .participant = new CamelFast(), .result = 0 });
                _camelFastCounter++;
                _numberOfParticipants++;
            }
            else 
                throw std::invalid_argument( CamelFast().getName() + " уже зарегестрирован");
            break;

        case Participants::FLYING_CARPET:
            if (_raceType == RaceType::LAND){
                throw std::invalid_argument( "Попытка зарегистрировать неправильный тип транспортного средства!");
            }

            if (!_carpetCounter){
                _raceParticipants.push_back(ParticipantData() = { .participant = new FlyingCarpet(), .result = 0 });
                _carpetCounter++;
                _numberOfParticipants++;
            }
            else 
                throw std::invalid_argument( FlyingCarpet().getName() + " уже зарегестрирован");
            break;
        
        default:
            throw std::invalid_argument("Неизвестное ТС");
            break;
    }   // switch
}


int RaceCoordinator::getParticipantsNumber(){
    return _numberOfParticipants;
}


std::string RaceCoordinator::getParticipantName(int number) const{
    return _raceParticipants.at(number).participant->getName(); // Добавить проверку на пустой? Ловить исключение at?
}


std::string RaceCoordinator::getLastParticipantName() const{
    if (!_raceParticipants.empty()){
        return _raceParticipants.back().participant->getName();
    }
    else{
        throw std::domain_error("Нет зарегистрированных участников!");
    }

}


void RaceCoordinator::raceStart(){
    for (auto& raceParticipant : _raceParticipants){
        raceParticipant.result = raceParticipant.participant->move(_distance);
    }
    
    sortResultsFastestFirst();
}


void RaceCoordinator::sortResultsFastestFirst(){
    for (int elementToSort = 1; elementToSort < _raceParticipants.size(); elementToSort++){
        ParticipantData sortingElementData;
        int elementToSortNumber;

        sortingElementData = _raceParticipants.at(elementToSort);
        elementToSortNumber = elementToSort;

        while ((elementToSortNumber > 0) && (_raceParticipants.at(elementToSortNumber - 1).result > sortingElementData.result)){
            _raceParticipants.at(elementToSortNumber) = _raceParticipants.at(elementToSortNumber - 1); 
            elementToSortNumber--;
        }
        _raceParticipants.at(elementToSortNumber) = sortingElementData;
    }
}


float RaceCoordinator::getPatricipantResult(int number){
    return _raceParticipants.at(number).result;
}


void RaceCoordinator::reset(){
    _distance = 0;
    _numberOfParticipants = 0;

    for (auto& participantData : _raceParticipants){
        delete participantData.participant;
    }
    std::vector<ParticipantData>().swap(_raceParticipants);
}

}   // race namespace
