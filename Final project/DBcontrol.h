#pragma once
#include <iostream>
#include <pqxx/pqxx>

class DBcontrol{
public:
    DBcontrol(std::string conectionSetup);

    void createTables();
    void updateDB(const std::string& citeName, const std::map<std::string, int>& wordCount);
    // void addClient(std::string name, std::string surname, std::string email);
    // void addClientPhone(size_t id, std::string phone);
    // void changeClientData(size_t id, std::string name, std::string surname, std::string email, std::string phone);
    // void removeClientPhone(size_t id);
    // void removeClient(size_t id);
    // void findClient(std::string name, std::string surname, std::string email, std::string phone);

private:
    pqxx::connection c;
    std::string tableCites;
    std::string tableWords;
    std::string tableCites_Words;
};
