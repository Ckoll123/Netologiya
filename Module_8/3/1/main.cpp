#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};


class LogConsole : public LogCommand {
public:
    void print(const std::string& message){
        std::cout << message << std::endl;
    };
};

class LogFile : public LogCommand {
public:
    void print(const std::string& message){
        std::ofstream oFile("log.txt");
        oFile << message << std::endl;
        oFile.close();  oFile.close();
    };
};

void print(LogCommand& command, std::string message){
    command.print(message);
}


int main(){
    LogConsole logConsole;
    LogFile logFile;

    print(logConsole, "log into console");
    print(logFile, "log into file \"log.txt\"");

    return 0;
}