#include <iostream>

void quick_sort(int* arr, int size);
int pivop_operation(int* arr, int size);
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
    quick_sort(arr1, len1);
    printArray(arr1, len1);
    std::cout << std::endl;

    std::cout << "Массив 2 до сортировки: " << std::endl;
    printArray(arr2, len2);
    std::cout << "Массив 2 после сортировки: " << std::endl;
    quick_sort(arr2, len2);
    printArray(arr2, len2);
    std::cout << std::endl;

    std::cout << "Массив 3 до сортировки: " << std::endl;
    printArray(arr3, len3);
    std::cout << "Массив 3 после сортировки: " << std::endl;
    quick_sort(arr3, len3);
    printArray(arr3, len3);
    std::cout << std::endl;

    return 0;
}


void quick_sort(int* arr, int size){
    if (size <= 1) return;

    int border = pivop_operation(arr, size);
    quick_sort(arr, border);
    quick_sort(arr + border, size - border);
}

int pivop_operation(int* arr, int size){
    int left{};
    int right{size - 1};

    int pivot{};
    if ((arr[0] > arr[size - 1]) ^ (arr[0] > arr[size / 2]))
        pivot = arr[0];
    else if ((arr[size - 1] > arr[0]) ^ (arr[size - 1] > arr[size / 2]))
        pivot = arr[size - 1];
    else
        pivot = arr[size / 2];

    while(true){
        while (arr[left] < pivot){
            left++;
        }
        while (arr[right] > pivot){
            right--;
        }

        if (left >= right) return left;

        arr[left] += arr[right];
        arr[right] = arr[left] - arr[right];
        arr[left] -= arr[right];

        left++;
        right--;
    }

}

void printArray(int* arr, int lenght){
    for (int i = 0; i < lenght; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
