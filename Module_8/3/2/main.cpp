#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};


class WarningsObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "[WARNING] " << message << std::endl;
    }
};


class ErrorObserver : public Observer {
public:
    ErrorObserver(const std::string& filePath) : _filePath(filePath) {}

    void onError(const std::string& message) override{
        std::ofstream oFile(_filePath);
        oFile << "[ERROR] " << message << std::endl;
        oFile.close();  oFile.close();
    }
    
private:
    std::string _filePath;
};


class FatalErrorObserver : public Observer {
public:
    FatalErrorObserver(const std::string& filePath) : _filePath(filePath) {}

    void onFatalError(const std::string& message) override{
        std::cout << "[FATAL ERROR] " << message << std::endl;
        std::ofstream oFile(_filePath);
        oFile << "[FATAL ERROR] " << message << std::endl;
        oFile.close();  oFile.close();
    }

private:
    std::string _filePath;
};



class Informer{
public:
    void addObserver(Observer* obs){
        _observers.push_back(obs);
    }

    void removeObserver(Observer* obs){
        auto it = std::remove(_observers.begin(), _observers.end(), obs);
        _observers.erase(it, _observers.end());
    }

    void warning(const std::string& message) const{
        for (Observer* obsIt : _observers){
            obsIt->onWarning(message);
        }
    }

    void error(const std::string& message) const{
        for (Observer* obsIt : _observers){
            obsIt->onError(message);
        }
    }

    void fatalError(const std::string& message) const{
        for (Observer* obsIt : _observers){
            obsIt->onFatalError(message);
        }
    }

private:
    std::vector<Observer*> _observers;
};



int main (){
    Informer informer;

    WarningsObserver warningObserver;
    ErrorObserver errorObserver("error.log");
    FatalErrorObserver fatalErrorObserver("fatal_error.log");

    informer.addObserver(&warningObserver);
    informer.addObserver(&errorObserver);
    informer.addObserver(&fatalErrorObserver);

    informer.warning("Превышение номинального значения");
    informer.error("Сбой связи");
    informer.fatalError("Выход устройства из строя");

    return 0;
}