#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <map>
#include <utility>

#include "DBcontrol.h"
#include "Link.h"
#include "SafeSet.h"

class Indexer{
public:
    Indexer(size_t recursionLimit);
    // void indexPage(const std::string& _inFileName);
    // void indexPage(std::vector<std::string> citeData);
    void indexPage(std::pair<Link, std::string> citeData);
    void sendDataToDB(DBcontrol& DB);
    bool isAllPagesIndexed() const;
    Link getLink();

private:
    void extractLinks();
    std::pair<std::string, std::string> splitURL(std::string url);
    void cleanHtmlPage();
    void convertToLowerCase(std::string);
    void analizeWordsInPage(std::string);

private:
    std::string _host;
    std::string _target;
    std::ifstream _inFile;
    std::string _html_page;
    size_t _recursionLimit;
    size_t _currentRecursionDepth;
    std::vector<Link> _links;
    std::map<std::string, int> _wordsCountMap;
    SafeSet<std::string> _safeSet;
};