#include <iostream>
#include <math.h>

enum class CommandType {
    UNKNOWN,
    RIGHT,
    LEFT,
    UP,
    EXIT
};

void print_array(int* arr, int size);

void changePosition(int* arr, int size, CommandType command, int& position);
void printPosition(int* arr, int size, int position);
void print_pyramid(int* arr, int size);


int main(){
    int arr[] = {1, 3, 6, 5, 9, 8};
    int size {sizeof(arr) / sizeof(arr[0])};
    std::cout << "Исходный массив: ";
    print_array(arr, size);
    print_pyramid(arr, size);

    CommandType commandType;
    std::string command;
    int currentPosition{};
    
    printPosition(arr, size, currentPosition);

    // printPosition(arr, size, 0);
    // printPosition(arr, size, 1);
    // printPosition(arr, size, 2);
    // printPosition(arr, size, 3);
    // printPosition(arr, size, 4);
    // printPosition(arr, size, 5);
    // printPosition(arr, size, 6);
    // printPosition(arr, size, 7);
    // printPosition(arr, size, 8);
    // printPosition(arr, size, 9);
    // printPosition(arr, size, 10);

    while (true){
        std::cout << "Введите команду: ";
        std::cin >> command;

        if (command == "right") commandType = CommandType::RIGHT;
        else if (command == "left") commandType = CommandType::LEFT;
        else if (command == "up") commandType = CommandType::UP;
        else if (command == "exit") commandType = CommandType::EXIT;
        else commandType = CommandType::UNKNOWN;

        if (commandType == CommandType::EXIT) break;

        changePosition(arr, size, commandType, currentPosition);
        printPosition(arr, size, currentPosition);

    }

    return 0;
}


void print_array(int* arr, int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void changePosition(int* arr, int size, CommandType command, int& position){
    switch (command)
    {
    case CommandType::RIGHT:
        if (size > (position * 2 + 2)){
            std::cout << "OK" << std::endl;
            position = position * 2 + 2;
        }
        else{
            std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
        }
        break;
    
    case CommandType::LEFT:
        if (size > (position * 2 + 1)){
            std::cout << "OK" << std::endl;
            position = position * 2 + 1;
        }
        else{
            std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
        }
        break;
    
    case CommandType::UP:
        if(!position){
            std::cout << "Ошибка! Отсутствует родитель" << std::endl;
        }
        else{
            std::cout << "OK" << std::endl;
            if (position % 2) position = (position - 1) / 2;
            else position = (position - 2) / 2;
        }
        break;
    
    default:
        std::cout << "Неизвестная команда!" << std::endl;
        break;
    }
}


void printPosition(int* arr, int size, int position){
    if (!position){
        std::cout << "Вы находитесь здесь: ";
        std::cout << "0 root 1" << std::endl;;
        return;
    }

    int level{1};
    int counter{1};

    bool left = true;
    for (int i = 1; i < size; i++){
        if (i == position){
            std::cout << "Вы находитесь здесь: ";
            // std::cout << level << " " << (position % 2 ? "left" : "right") << "(" << arr[(i - 1) / 2] << ") " << arr[i] << std::endl;
            std::cout << level << " " << (position % 2 ? "left" : "right") << "("
                      << (position % 2 ? arr[(i - 1) / 2] : arr[(i - 2) / 2]) << ") " << arr[i] << std::endl;
            return;
        }

        if(!counter){
            level++;
            counter = pow(2, level) - 1;
        }
        else
            counter--;
    }

    std::cerr << "Несуществующая позиция!" << std::endl;
}


void print_pyramid(int* arr, int size){
    std::cout << "Пирамида:" << std::endl;

    std::cout << "0 root " << arr[0] << std::endl;

    int level{1};
    int counter{1};

    bool left = true;
    for (int i = 1; i < size; i++){
        if(left){
            left = !left; 
            std::cout << level << " left(" << arr[(i - 1) / 2] << ") " << arr[i] << std::endl;
        }
        else{
            left = !left; 
            std::cout << level << " right(" << arr[(i - 2) / 2] << ") " << arr[i] << std::endl;
        }

        if(!counter){
            level++;
            counter = pow(2, level) - 1;
        }
        else
            counter--;
    }
}
