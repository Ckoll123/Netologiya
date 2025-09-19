#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <map>

#include "DBcontrol.h"

class Indexer{
public:
    Indexer();
    void indexPage(const std::string& inFileName);
    void sendDataToDB(DBcontrol& DB);

private:
    void extractLinks();
    void cleanHtmlPage();
    void convertToLowerCase(std::string);
    void analizeWordsInPage(std::string);

private:
    std::string citeName;
    std::ifstream inFile;
    std::string html_page;
    std::vector<std::string> links;
    std::map<std::string, int> wordsCountMap;
};