#include <iostream>

int* create_dynamic_array(int logical_size, int actual_size);
void print_dynamic_array(int* arr, int logical_size, int actual_size);

int main(){

    int logical_size{};
    int actual_size{};
    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;
    
    if (logical_size > actual_size){
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
    }
    else{
        int* arr = create_dynamic_array(logical_size, actual_size);
        print_dynamic_array(arr, logical_size, actual_size);
        delete[] arr;
    }

    return 0;
}


int* create_dynamic_array(int logical_size, int actual_size){
    int* arr = new int[actual_size];
    for (int i = 0; i < logical_size; i++){
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    return arr;
}


void print_dynamic_array(int* arr, int logical_size, int actual_size){
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; i++){
        if (i < logical_size)
            std::cout << arr[i] << " ";
        else
            std::cout << "_ ";
    }
    std::cout << std::endl;
}
