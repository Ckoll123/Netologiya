#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>

#include <algorithm>
#include <cctype>


class IniParser{
public:
    IniParser(const std::string& inFileName);
    ~IniParser();

    template <typename T>
    T get_value(std::string sectionAndVariable);

private:
    void parseFile();
    void removeComments(std::string& line);
    void removeWhiteSpacesFromStart(std::string& line);
    void removeWhiteSpacesFromEnd(std::string& line);
    void sectionHandling(std::string& line);
    void variableHandling(std::string& line);
    void printAvailableVars(const std::string& section);
    
private:
    std::ifstream inFile;
    std::map<std::string, std::map<std::string, std::string>> fileParsed;
    std::string currentSection;
    unsigned lineNumber;
};

#include "IniParser.inl"
