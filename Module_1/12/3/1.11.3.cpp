#include <iostream>
#include <fstream>


int* createArray(int size);
void fillArray(int* p_arr, int size);
void printArrayReverse(int* p_arr, int size);

int main() { 

  std::cout << "Задание №3. Пользовательский массив в файл:\n\n";

  std::cout << "Введите размер массива: ";
  int sizeArr;
  std::cin >> sizeArr;

  int* pArr{createArray(sizeArr)};
  fillArray(pArr, sizeArr);

  std::ofstream oFile("out.txt");
  
  oFile << sizeArr << std::endl;
  for (int i = sizeArr - 1; i >= 0; i--)
  {
    oFile << pArr[i] << " ";
  } 
  oFile.close();
  delete[] pArr;
}


int* createArray(int size)
{
  int* p_arr = new int[size]{};
  return p_arr;
}


void fillArray(int* p_arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << "arr[" << i << "] = ";
    std::cin >> p_arr[i];
  }
}