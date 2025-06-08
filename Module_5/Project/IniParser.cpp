#include "IniParser.h"

IniParser::IniParser(const std::string& inFileName) :
        inFile(),
        fileParsed(),    
        lineNumber(0)
    {
        inFile.open(inFileName);
        if(!inFile.is_open()){
            throw std::runtime_error("Не удалось открыть файл " + inFileName);
        }

        parseFile();
    }


IniParser::~IniParser(){
    if(inFile.is_open())
        inFile.close();
}


void IniParser::parseFile(){
    std::string line;
    while (!inFile.eof()){
        std::getline(inFile, line);
        lineNumber++;
        removeWhiteSpacesFromStart(line);
        removeComments(line);
        removeWhiteSpacesFromEnd(line);
        if(line.empty()) continue;
        
        sectionHandling(line);
        variableHandling(line);
    }

}


void IniParser::removeComments(std::string& line){
    size_t variable = line.find(';');
    if(variable != std::string::npos){
        line.erase(variable);
    }
}


void IniParser::removeWhiteSpacesFromStart(std::string& line){
    line.erase(line.begin(), std::find_if(line.begin(), line.end(),
                                            [](int ch){ return !std::isspace(ch); })
    );
}


void IniParser::removeWhiteSpacesFromEnd(std::string& line){
    line.erase(std::find_if(line.rbegin(), line.rend(), [](int ch){ return !std::isspace(ch); }).base(),
                line.end()
    );
}


void IniParser::sectionHandling(std::string& line){
    if (line.front() == '['){
        if (line.back() != ']') 
            throw std::logic_error("Неправильный синтаксис в строке " + std::to_string(lineNumber));

        currentSection = line.substr(1, line.size() - 2);
        fileParsed[currentSection];
    }            
}


void IniParser::variableHandling(std::string& line){
    if (line.find('=') == std::string::npos) return;

    size_t equalSignPos = line.find('=');
    if (equalSignPos == 0 || equalSignPos == line.size() - 1)
        throw std::logic_error("Неправильный синтаксис в строке " + std::to_string(lineNumber));

    std::string varName = line.substr(0, equalSignPos);
    removeWhiteSpacesFromEnd(varName);

    std::string value = line.substr(equalSignPos + 1);
    removeWhiteSpacesFromStart(value);

    fileParsed[currentSection][varName] = value;
}
 

void IniParser::printAvailableVars(const std::string& section){
    for (const auto& itVar : fileParsed.at(section)){
        std::cerr << itVar.first << std::endl;
    }
}

