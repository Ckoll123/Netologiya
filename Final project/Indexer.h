#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <map>
#include <utility>

#include "DBcontrol.h"

class Indexer{
public:
    Indexer();
    // void indexPage(const std::string& inFileName);
    void indexPage(std::vector<std::string> citeData);
    void sendDataToDB(DBcontrol& DB);
    bool isAllPagesIndexed() const;
    std::pair<std::string, std::string> getLink();

private:
    void extractLinks();
    std::pair<std::string, std::string> splitURL(std::string url);
    void cleanHtmlPage();
    void convertToLowerCase(std::string);
    void analizeWordsInPage(std::string);

private:
    std::string _host;
    std::string _target;
    std::ifstream inFile;
    std::string html_page;
    std::vector<std::string> links;
    std::map<std::string, int> wordsCountMap;
};