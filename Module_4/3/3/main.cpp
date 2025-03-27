#include <iostream>

void count_sort(int* arr, int size);
void printArray(int* arr, int lenght);

int main(){

    int arr1[] = {19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17};
    int arr2[] = {16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21,
                  17, 11, 17, 16, 12, 11, 16, 22, 23, 16};
    int arr3[] = {21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22,
                  19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10};

    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr1[0]);
    int len3 = sizeof(arr3) / sizeof(arr1[0]);

    std::cout << "Массив 1 до сортировки: " << std::endl;
    printArray(arr1, len1);
    std::cout << "Массив 1 после сортировки: " << std::endl;
    count_sort(arr1, len1);
    printArray(arr1, len1);
    std::cout << std::endl;

    std::cout << "Массив 2 до сортировки: " << std::endl;
    printArray(arr2, len2);
    std::cout << "Массив 2 после сортировки: " << std::endl;
    count_sort(arr2, len2);
    printArray(arr2, len2);
    std::cout << std::endl;

    std::cout << "Массив 3 до сортировки: " << std::endl;
    printArray(arr3, len3);
    std::cout << "Массив 3 после сортировки: " << std::endl;
    count_sort(arr3, len3);
    printArray(arr3, len3);
    std::cout << std::endl;

    return 0;
}


void count_sort(int* arr, int size){
    int left = 10;
    int right = 24;
    int k {right + 1 - left};
    int tempArr[k] = {};

    for (int i = 0; i < size; i++){
        tempArr[arr[i] - left]++;
    }

    for (int i = 0, j = 0; i < size; i++){

        while (!tempArr[j]){
            j++;
        }

        arr[i] = left + j;
        tempArr[j]--;
    }

}


void printArray(int* arr, int lenght){
    for (int i = 0; i < lenght; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
