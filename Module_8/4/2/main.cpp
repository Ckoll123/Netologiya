#include <fstream>
#include <iostream>

class Printable{
public:
    virtual ~Printable() = default;
    virtual std::string print() const = 0;
};


class Data {
public:
    Data(std::string data)
        : _data(std::move(data))
    {}

    std::string getData() const{ return _data; }
private:
    std::string _data;
};


class PrintDataHTML : public Printable{
public:
    PrintDataHTML(std::string data) :
        _data(std::move(data))
    {}

    std::string print() const override {
        return "<html>" + _data.getData() + "<html/>";
    }

private:
    Data _data;
};


class PrintDataText : public Printable{
public:
    PrintDataText(std::string data) :
        _data(std::move(data))
    {}

    std::string print() const override {
        return _data.getData();
    }

private:
    Data _data;
};


class PrintDataJSON : public Printable{
public:
    PrintDataJSON(std::string data) :
        _data(std::move(data))
    {}

    std::string print() const override {
        return "{ \"data\": \"" + _data.getData() + "\"}";
    }

private:
    Data _data;
};


void saveTo(std::ofstream &file, const Printable& printable){
    file << printable.print();
}

int main(){
    PrintDataHTML html("html");
    PrintDataText text("text");
    PrintDataJSON json("json");

    Printable* printable = &html;
    std::cout << printable->print();
    std::cout << std::endl;

    printable = &text;
    std::cout << printable->print();
    std::cout << std::endl;

    printable = &json;
    std::cout << printable->print();
    std::cout << std::endl;

    std::ofstream file1("html_file.txt");
    std::ofstream file2("text_file.txt");
    std::ofstream file3("json_file.txt");

    saveTo(file1, html);
    saveTo(file2, text);
    saveTo(file3, json);

    return 0;
}