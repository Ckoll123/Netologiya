#include <iostream>
#include <sstream>

class Functor{
public:
    Functor() : 
        _sum(0),
        _counter(0)
    {};
    void operator()(int value){
        if (!(value % 3)){
            _sum += value;
            _counter++;
        }
    };
    int get_sum() const {return _sum;}
    int get_count() const {return _counter;}

private:
    int _counter;
    int _sum;
};


int main(){
    Functor functor;

    std::string line;
    std::cout << "Введите end чтобы закончить" << std::endl;
    while (true) {
        std::getline(std::cin, line);

        if (line == "end") {
            break;
        }

        std::istringstream stream(line);
        int num;
        while (stream >> num) {
            functor(num);
        }
    }

    std::cout << "get_sum() = " << functor.get_sum() << std::endl;
    std::cout << "get_count() = " << functor.get_count() << std::endl;


    return 0;
}

