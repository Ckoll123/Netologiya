#include <iostream>
#include <math.h>

void print_array(int* arr, int size);
void print_pyramid(int* arr, int size);

int main(){
    int arr[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    std::cout << "Исходный массив: ";
    print_array(arr, sizeof(arr) / sizeof(arr[0]));
    print_pyramid(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}


void print_array(int* arr, int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
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
