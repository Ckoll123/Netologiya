#include <iostream>


int func(int* arr, int length, int startPoint);

int main (){

    int array[]{14, 16, 19, 32, 32, 32, 56, 69, 72};

    std::cout << "Введите точку отсчёта: ";
    int startPoint{};
    std::cin >> startPoint;
    std::cout << std::endl;

    int result = func(array, sizeof(array)/sizeof(array[0]), startPoint);
    std::cout << "Количество элементов в массиве больших, чем " << startPoint << ": " << result << std::endl;

    return 0;
}


int func(int* arr, int length, int startPoint){
    int elementPosition{};

    int left{};
    int right{length - 1};
    int middle{};


    if (arr[0] > startPoint){
        return length;
    }

    if (arr[length - 1] <= startPoint){
        return 0;
    }
            
    while (left <= right){
        
        if (left == right) {
            if (arr[left] < startPoint) elementPosition = left + 1;
            break;
        }

        middle = (left + right)/2;

        if (arr[middle] > startPoint){
            right = middle - 1;
            elementPosition = middle;
        }
        else if (arr[middle] <= startPoint){
            left = middle + 1;
        }
    }

    return length - elementPosition;
}