#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

struct CharCount {
    char character;
    int count;
};

int main(){
    std::string line{"Hello world!!"};
    std::cout << "[IN]: " << line << std::endl;

    std::map<char, int> charCountMap; 
    for(char c : line){
        charCountMap[c]++;
    }

    std::vector<CharCount> charCountVector;
    for(const std::pair<char, int>& pair : charCountMap){
        charCountVector.push_back({pair.first, pair.second});
    }

    std::sort(charCountVector.begin(), charCountVector.end(), [](const CharCount& a, const CharCount& b){
        if(a.count > b.count) return true;
        else return false;
    });

    std::cout << "[OUT]: " << std::endl;
    for (const CharCount& pair: charCountVector){
        std::cout << pair.character << ": " << pair.count << std::endl;
    }
}