#pragma once
#include <iostream>
#include <pqxx/pqxx>

class DBcontrol{
public:
    DBcontrol(std::string conectionSetup);

    void createTables();
    void updateDB(const std::string& citeName, const std::map<std::string, int>& wordCount);
    std::vector<std::string> querryProcessing(std::vector<std::string> words);

private:
    pqxx::connection c;
    std::string tableCites;
    std::string tableWords;
    std::string tableCites_Words;
};
