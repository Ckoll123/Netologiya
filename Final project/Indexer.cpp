#include "Indexer.h"

Indexer::Indexer(size_t recursionLimit) :
    _host(),
    _target(),
    _inFile(),
    _html_page(),
    _recursionLimit(recursionLimit),
    _currentRecursionDepth(),
    _links(),
    _wordsCountMap()
{}


// void Indexer::indexPage(const std::string& _inFileName){
// void Indexer::indexPage(std::vector<std::string> citeData){
    // citeName = _inFileName;
    // _inFile.open(citeName);
    // if(!_inFile.is_open()){
        //     throw std::runtime_error("Не удалось открыть файл " + citeName);
        // }
        // std::stringstream buffer;
        // buffer << _inFile.rdbuf();
        // _html_page = buffer.str();
        
void Indexer::indexPage(std::pair<Link, std::string> citeData){
    _host = citeData.first.host;
    _target = citeData.first.target;
    _currentRecursionDepth = citeData.first.currentRecursionDepth;
    _html_page = citeData.second;
    
    if(_currentRecursionDepth && _currentRecursionDepth < _recursionLimit){
        extractLinks();
    }
    cleanHtmlPage();

    std::istringstream iss(_html_page);
    std::string word;

    while (iss >> word){
        _wordsCountMap[word]++;
    }
    
    // std::ofstream out("output.txt");
    // int count = _wordsCountMap["wiki"];
    // if (out.is_open()) {
    //     out << _html_page;
    //     out.close();
    // } else {
    //     std::cerr << "Не удалось выходной открыть файл!\n";
    // }
}


bool Indexer::isAllPagesIndexed() const{
    return _links.empty();
}


Link Indexer::getLink(){     // добавить проверку на пустой вектор?
    Link result = std::move(_links.back());
    _links.pop_back();
    return result;
}


void Indexer::extractLinks(){
    std::regex href_regex("<a\\s+[^>]*href=[\"']([^\"']+)[\"']", std::regex::icase);
    std::smatch match;

    std::string::const_iterator searchStart(_html_page.cbegin());
    while (std::regex_search(searchStart, _html_page.cend(), match, href_regex)) {
        std::string url = match[1];
        // if (url[0] != '#'){
        if (url.find("http://") == 0 || url.find("/") == 0){
            _links.emplace_back(splitURL(url), ++_currentRecursionDepth);
        }
        searchStart = match.suffix().first;
    }
}


std::pair<std::string, std::string> Indexer::splitURL(std::string url){
    std::string host;
    std::string target;

    size_t protocol_end = url.find("://");
    if (protocol_end == std::string::npos) {
        host = _host;
        target = url;
        return {host, target};
    } else {
        protocol_end += 3; 
    }
    
    size_t slash_pos = url.find('/', protocol_end);
    if (slash_pos == std::string::npos) {
        host = url.substr(protocol_end);
        target = "/";
    } else {
        host = url.substr(protocol_end, slash_pos - protocol_end);
        target = url.substr(slash_pos);
    }

    return {host, target};
}


void Indexer::cleanHtmlPage(){
    std::regex tag_re("<[^>]*>");
    std::string noTagsHtml = std::regex_replace(_html_page, tag_re, " ");

    std::string result;
    for (unsigned char ch : noTagsHtml) {
        // if (std::isalpha(ch) || std::isdigit(ch)) {
        if (std::isalpha(ch)) {
            result += std::tolower(ch);
        } else {
            result += ' ';
        }
    }

    std::regex spaces("\\s+");
    _html_page = std::regex_replace(result, spaces, " ");
}


void Indexer::sendDataToDB(DBcontrol& db){
    db.updateDB(_host + _target, _wordsCountMap);
}


