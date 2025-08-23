#include <iostream>
#include <fstream>
#include <memory>
#include <exception>


enum class Type {WARNING, ERROR, FATAL_ERROR, UNKNOWN_MESSAGE};

class LogMessage {
public:
    LogMessage(Type type, std::string message) : _type(type), _message(message) {}

    Type type() const{
        return _type;
    }

    const std::string& message() const{
        return _message;
    }

private:
    Type _type;
    std::string _message;
};


class MessageHandler{
public:
    void setNextHandler(std::unique_ptr<MessageHandler> nextHandler){
        _nextHandler = std::move(nextHandler);
    };
    virtual void handleMessage(const LogMessage& logMessage) = 0;
protected:
    std::unique_ptr<MessageHandler> _nextHandler;
};


class WarningMessageHandler : public MessageHandler{
public:
    void handleMessage(const LogMessage& logMessage) override{
        if (logMessage.type() == Type::WARNING){
            std::cout << "[WARNING] " << logMessage.message() << std::endl;
        }
        else if (_nextHandler){
            _nextHandler->handleMessage(logMessage);
        }
    }
};


class ErrorMessageHandler : public MessageHandler{
public:
    ErrorMessageHandler(std::string filePath) : _filePath(filePath) {}

    void handleMessage(const LogMessage& logMessage) override{
        if (logMessage.type() == Type::ERROR){
            std::ofstream oFile(_filePath);
            oFile << "[ERROR] " << logMessage.message() << std::endl;
            oFile.close();
        }
        else if (_nextHandler){
            _nextHandler->handleMessage(logMessage);
        }
    }
private:
    std::string _filePath;
};


class FatalErrorMessageHandler : public MessageHandler{
public:
    void handleMessage(const LogMessage& logMessage) override{
        if (logMessage.type() == Type::FATAL_ERROR){
            std::string errorMsg{"[FATAL_ERROR] " + logMessage.message() + '\n'};
            throw std::runtime_error(errorMsg);
        }
        else if (_nextHandler){
            _nextHandler->handleMessage(logMessage);
        }
    }
};


class UnknownMessageHandler : public MessageHandler{
public:
    void handleMessage(const LogMessage& logMessage) override{
        if (logMessage.type() == Type::UNKNOWN_MESSAGE){
            std::string errorMsg{"[UNKNOWN_MESSAGE] " + logMessage.message() + '\n'};
            throw std::logic_error(errorMsg);
        }
        else if (_nextHandler){
            _nextHandler->handleMessage(logMessage);
        }
        else{
            std::cerr << "Такого типа сообщения не существует" << std::endl;
        } 
    }
};


int main(){
    std::unique_ptr<MessageHandler> warning = std::make_unique<WarningMessageHandler>();
    std::unique_ptr<MessageHandler> error = std::make_unique<ErrorMessageHandler>("error.log");
    std::unique_ptr<MessageHandler> fatalError = std::make_unique<FatalErrorMessageHandler>();
    std::unique_ptr<MessageHandler> unknownMessage = std::make_unique<UnknownMessageHandler>();

    warning->setNextHandler(std::move(unknownMessage));
    error->setNextHandler(std::move(warning));
    fatalError->setNextHandler(std::move(error));

    try{
        fatalError->handleMessage(LogMessage(Type::WARNING, "Опасность!"));
        fatalError->handleMessage(LogMessage(Type::ERROR, "Ошибка!"));
        fatalError->handleMessage(LogMessage(Type::FATAL_ERROR, "Авария!"));
        fatalError->handleMessage(LogMessage(Type::UNKNOWN_MESSAGE, "Просто сообщение"));
    }
    catch(const std::exception& ex){
        std::cout << "Исключение: " << ex.what() << std::endl;
    }

    return 0;
}