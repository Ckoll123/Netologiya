#include "Indexer.h"

Indexer::Indexer() :
    _host(),
    _target(),
    inFile(),
    html_page(),
    links(),
    wordsCountMap()
{}


// void Indexer::indexPage(const std::string& inFileName){
void Indexer::indexPage(std::vector<std::string> citeData){
    // citeName = inFileName;
    // inFile.open(citeName);
    // if(!inFile.is_open()){
    //     throw std::runtime_error("Не удалось открыть файл " + citeName);
    // }
    // std::stringstream buffer;
    // buffer << inFile.rdbuf();
    // html_page = buffer.str();

    _host = citeData.at(0);
    _target = citeData.at(1);
    html_page = citeData.at(2);

    extractLinks();
    cleanHtmlPage();

    std::istringstream iss(html_page);
    std::string word;

    while (iss >> word){
        wordsCountMap[word]++;
    }
    
    // std::ofstream out("output.txt");
    // int count = wordsCountMap["wiki"];
    // if (out.is_open()) {
    //     out << html_page;
    //     out.close();
    // } else {
    //     std::cerr << "Не удалось выходной открыть файл!\n";
    // }
}


bool Indexer::isAllPagesIndexed() const{
    return links.empty();
}


std::pair<std::string, std::string> Indexer::getLink(){     // добавить проверку на пустой вектор?
    std::pair result = splitURL(links.back());
    links.pop_back();
    return result;
}


void Indexer::extractLinks(){
    std::regex href_regex("<a\\s+[^>]*href=[\"']([^\"']+)[\"']", std::regex::icase);
    std::smatch match;

    std::string::const_iterator searchStart(html_page.cbegin());
    while (std::regex_search(searchStart, html_page.cend(), match, href_regex)) {
        std::string url = match[1];
        // if (url[0] != '#'){
        if (url.find("http://") == 0 || url.find("/") == 0){
            links.push_back(match[1]);
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
    std::string noTagsHtml = std::regex_replace(html_page, tag_re, " ");

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
    html_page = std::regex_replace(result, spaces, " ");
}


void Indexer::sendDataToDB(DBcontrol& db){
    db.updateDB(_host + _target, wordsCountMap);
}


