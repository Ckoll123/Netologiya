#include <iostream>
#include <stdexcept>

#include "RaceCoordinator.h"

enum class States{
    IDLE,
    DISTANCE_CHOISE,
    PRE_REGISTRATION,
    REGISTRATION,
    PRE_START,
    RACE_START,
    RACE_RESULTS,
    EXIT
};


States state;
void (*ptrFunc)();
race::RaceCoordinator raceCoordinator;

void idle();
void distanceChoise();
void preRegistration();
void registration();
void preStart();
void raceStart();
void raceResults();


int main(){

    std::cout << "Привет" << std::endl;

    States state = States::IDLE;
    while (state != States::EXIT){
        switch (state)
        {
            case States::IDLE:
                ptrFunc();
                ptrFunc = distanceChoise;
                state = States::DISTANCE_CHOISE;
                break;
            
            case States::DISTANCE_CHOISE:
                ptrFunc();
                if (raceCoordinator.getDistance() > 0){
                    ptrFunc = preRegistration;
                    state = States::PRE_REGISTRATION;
                }
                else{ state = States::EXIT; }
                break;
            
            case States::PRE_REGISTRATION:
                ptrFunc();
                ptrFunc = registration;
                state = States::REGISTRATION;
                break;
            
            case States::REGISTRATION:
                ptrFunc();

                int command;
                std::cin >> command;
                std::cout << std::endl;
                
                if (!command){
                    if (raceCoordinator.getParticipantsNumber() < 2) {
                    ptrFunc = preRegistration;
                    state = States::PRE_REGISTRATION;
                    break;
                    }
                    else{
                        ptrFunc = preRegistration;
                        state = States::PRE_REGISTRATION;
                        break;
                    }
                }
                
                try {
                    raceCoordinator.addParticipant(command);
                    std::cout << raceCoordinator.getLastParticipantName() << std::endl;
                }
                catch(std::logic_error &ex){
                    std::cout << ex.what() << std::endl;
                }

                break;
            
            case States::PRE_START:
                ptrFunc();

                int command;
                std::cin >> command;
                std::cout << std::endl;
                
                if (command == 1){
                    ptrFunc = registration;
                    state = States::REGISTRATION;
                }
                else if (command == 2){
                    ptrFunc = raceStart;
                    state = States::RACE_START;
                }
                else { std::cout << "Введена неверная команда!" << std::endl;}
                
                break;

            case States::RACE_START:
                ptrFunc();
                
                ptrFunc = raceResults;
                state = States::RACE_RESULTS;
                break;

            case States::RACE_RESULTS:
                ptrFunc();

                std::cout << "1. Провести ещё одну гонку" << std::endl;
                std::cout << "2. Выйти" << std::endl;
                std::cout << "Выберите действие";
                int command;
                std::cin >> command;
                std::cout << std::endl;
                if (command == 1){
                    ptrFunc = idle;
                    state = States::IDLE;
                }
                else if(command == 2){
                    state = States::EXIT;
                }
                else{
                    std::cout << "Неверная команда! Выход из программы." << std::endl;
                    state = States::EXIT;
                }

                break;
            
            default:
                std::cout << "Несуществующее состояние! Выход из программы." << std::endl;
                state = States::EXIT;
                break;

        }   // switch
    }   // while
}   // main


void idle(){
    int raceType;
    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
    std::cout << "1. Гонка для наземнрго транспорта!" << std::endl;
    std::cout << "2. Гонка для воздушного транспорта!" << std::endl;
    std::cout << "3. Гонка для наземного и воздушного транспорта!" << std::endl;
    std::cout << "Выберите тип гонки: ";
    std::cin >> raceType;
    std::cout << std::endl;
    raceCoordinator.setRaceType(raceType);
}


void distanceChoise(){
    float distance;
    std::cout << "Укажите длину дистанции (должна быть положительна): ";
    std::cin >> distance;
    try{
        raceCoordinator.setDistance(distance);
    }
    catch(std::invalid_argument &ex){
        std::cout << ex.what() << std::endl;
    }
}


void preRegistration(){
    int command;
    std::cout << "Должно быть зарегистрирвано хотя бы 2 транспортных средства" << std::endl;
    std::cout << "1. Зарегистрировать транспорт" << std::endl;
    std::cout << "Выберите действитвие: " << std::endl;
    std::cin >> command;
    
    while (command != 1){
        std::cout << "Выберите действитвие: " << std::endl;
        std::cin >> command;
    }
}


void registration(){
    race::RaceType raceType;
    raceType = raceCoordinator.getRaceType();
    std::string raceFor;

    switch (raceType)
    {
        case race::RaceType::LAND:
            raceFor = "Гонка для наземного транспорта.";
            break;

        case race::RaceType::AIR:
            raceFor = "Гонка для воздушного транспорта.";
            break;

        case race::RaceType::ALL_TERRAIN:
            raceFor = "Гонка для всех видов транспорта.";
            break;
        
        default:
            break;
    }

    std::cout << raceFor << "Расстояние: " << raceCoordinator.getDistance() << std::endl;

    if (raceCoordinator.getParticipantsNumber()){
        std::cout << "Зарегистрированные транспортные средства: " << std::endl;
        for (int i = 0; i < raceCoordinator.getParticipantsNumber(); i++){
            std::cout << raceCoordinator.getParticipantName(i), " ";
        }
        std::cout << std::endl;
    }

    std::cout << "1. Ботинки вездеходы" << std::endl;
    std::cout << "2. Метла" << std::endl;
    std::cout << "3. Верблюд" << std::endl;
    std::cout << "4. Кентавр" << std::endl;
    std::cout << "5. Орёл" << std::endl;
    std::cout << "6. Верблюд-быстроход" << std::endl;
    std::cout << "7. Ковёр-самолёт" << std::endl;
    std::cout << "0. Закончить регистрацию" << std::endl;
    std::cout << "Выберите транспорт или 0 для окончания регистрации" << std::endl;
}


void preStart(){
    std::cout << "1. Зарегистрировать транспорт" << std::endl;
    std::cout << "2. Начать гонку" << std::endl;
    std::cout << "Выберете действие: ";
}


void raceStart(){
    raceCoordinator.raceStart();
}


void raceResults(){
    std::cout << "Результаты гонки: " << std::endl;
    for (int i = 0; i < raceCoordinator.getParticipantsNumber(); i++){
        std::cout << raceCoordinator.getParticipantName(i) << ". Время: " << raceCoordinator.getPatricipantResult(i) << std::endl;
    }
    std::cout << std::endl;
}
