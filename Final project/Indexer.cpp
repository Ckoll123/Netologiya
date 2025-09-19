#include "Indexer.h"

Indexer::Indexer() :
    citeName(),
    inFile(),
    html_page(),
    links(),
    wordsCountMap()
{}


void Indexer::indexPage(const std::string& inFileName){
    citeName = inFileName;
    inFile.open(citeName);
    if(!inFile.is_open()){
        throw std::runtime_error("Не удалось открыть файл " + citeName);
    }
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    html_page = buffer.str();

    extractLinks();
    cleanHtmlPage();

    std::istringstream iss(html_page);
    std::string word;

    while (iss >> word){
        wordsCountMap[word]++;
    }
    
    std::ofstream out("output.txt");
    int count = wordsCountMap["wiki"];
    if (out.is_open()) {
        out << html_page;
        out.close();
    } else {
        std::cerr << "Не удалось выходной открыть файл!\n";
    }
}


void Indexer::extractLinks(){
    std::regex href_regex("<a\\s+[^>]*href=[\"']([^\"']+)[\"']", std::regex::icase);
    std::smatch match;

    std::string::const_iterator searchStart(html_page.cbegin());
    while (std::regex_search(searchStart, html_page.cend(), match, href_regex)) {
        std::string url = match[1];
        if (url[0] != '#'){
            links.push_back(match[1]);
        }
        searchStart = match.suffix().first;
    }
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
    db.updateDB(citeName, wordsCountMap);
}