#include <iostream>

void printArray(int* arr, int size);
void swap(int* a, int* b);
void reverse(int* arr, int size);

int main(int argc, char** argv)
{   
  // Task 1
  std::cout << "Задание №1. Вывод массива:\n\n";

  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size1 = sizeof(arr1) / sizeof(int);
  printArray(arr1, size1);
  std::cout << std::endl;
  
  int arr2[] = {-1, -2, -3, -4};
  int size2 = sizeof(arr2) / sizeof(int);
  printArray(arr2, size2);
  std::cout << std::endl;
  
  int arr3[] = {1, 2, 3, 4, -5, -6, -7, -8, -9, 10, 11, 12, 13};
  int size3 = sizeof(arr3) / sizeof(int);
  printArray(arr3, size3);
  std::cout << std::endl;
  
  //-----------------------------------------------------------------

  // Task 2
  std::cout << std::endl << std::endl;
  std::cout << "Задание №2. Снова swap:\n\n";
  
  int a{10};
  int b{-5};
  std::cout << "a = " << a << ", b = " << b << std::endl;
  swap(&a, &b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  
  //-----------------------------------------------------------------

  // Task 3
  std::cout << std::endl << std::endl;
  std::cout << "Задание №3. Переворот массива:\n\n";

  int arr4[]{1, 2, 3, 4, 5, 6};
  int size4 = sizeof(arr4) / sizeof(int);
  // int arr4[]{1, 2, 3, 4, 5};
  // int size4 = sizeof(arr4) / sizeof(int);
  std::cout << "До функции reverse: ";
  printArray(arr4, size4);
  
  std::cout << std::endl;
  std::cout << "После функции reverse: ";
  reverse(arr4, size4);
  printArray(arr4, size4);
  
  return 0;
}


void printArray(int* arr, int size)
{
  for(int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
}

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void reverse(int* arr, int size)
{
  for(int i = 0; i <= size/2 - 1; i++)
  {
    swap(&arr[i], &arr[size - 1 - i]);
  }
}