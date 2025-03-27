#include <iostream>

void merge_sort(int* arr, int size);
void merge_arr(int* arr1, int lenght1, int* arr2, int lenght2, int* result);
void printArray(int* arr, int lenght);

int main(){

    int arr1[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int arr3[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};

    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr1[0]);
    int len3 = sizeof(arr3) / sizeof(arr1[0]);

    std::cout << "Массив 1 до сортировки: " << std::endl;
    printArray(arr1, len1);
    std::cout << "Массив 1 после сортировки: " << std::endl;
    merge_sort(arr1, len1);
    printArray(arr1, len1);

    std::cout << "Массив 2 до сортировки: " << std::endl;
    printArray(arr2, len2);
    std::cout << "Массив 2 после сортировки: " << std::endl;
    merge_sort(arr2, len2);
    printArray(arr2, len2);

    std::cout << "Массив 3 до сортировки: " << std::endl;
    printArray(arr3, len3);
    std::cout << "Массив 3 после сортировки: " << std::endl;
    merge_sort(arr3, len3);
    printArray(arr3, len3);
    
    return 0;
}


void merge_sort(int* arr, int size){
    if (size <= 1) return;

    int arr_left[size / 2] = {};
    int arr_right[size - (size / 2)] = {};

    for (int i = 0; i < size / 2; ++i) {
        arr_left[i] = arr[i];
    }
    for (int i = 0; i < size - (size / 2); ++i) {
        arr_right[i] = arr[size / 2 + i];
    }

    merge_sort(arr_left, size / 2);
    merge_sort(arr_right, size - (size / 2));

    merge_arr(arr_left, (size / 2),
              arr_right, size - (size / 2), arr);
}

void merge_arr(int* arr1, int lenght1, int* arr2, int lenght2, int* result){

    int counter1{};
    int counter2{};
    int counter3{};

    while (counter1 < lenght1 || counter2 < lenght2){
        if (counter1 == lenght1){
            result[counter3] = arr2[counter2];
            counter2++;
        }
        else if (counter2 == lenght2){
            result[counter3] = arr1[counter1];
            counter1++;
        }
        else{
            if (arr1[counter1] <= arr2[counter2]){
                result[counter3] = arr1[counter1];
                counter1++;
            }
            else {
                result[counter3] = arr2[counter2];
                counter2++;
            }
        }

        counter3++;
    }
}


void printArray(int* arr, int lenght){
    for (int i = 0; i < lenght; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
