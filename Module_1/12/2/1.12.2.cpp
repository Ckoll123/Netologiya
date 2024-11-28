#include <iostream>
#include <fstream>
#include <string>


int* createArray(int size);
void fillArray(int* p_arr, int size, std::ifstream& iStream);
void printArrayReverse(int* p_arr, int size);

int main() { 

  std::cout << "Задание №2. Чтение массива из файла:\n\n";

  std::ifstream iFile("in.txt");
  if (iFile.is_open())
  {
    int arrSize;
    iFile >> arrSize;

    int* p_arr = createArray(arrSize); 
    fillArray(p_arr, arrSize, iFile);
    printArrayReverse(p_arr, arrSize);
    delete[] p_arr;
  }
  else
    {std::cout << "Не удалось открыть файл" << std::endl;}
  
  iFile.close();
}


int* createArray(int size)
{
  int* p_arr = new int[size]{};
  return p_arr;
}


void fillArray(int* p_arr, int size, std::ifstream& iStream)
{
  for (int i = 0; i < size; i++)
  {
    if(iStream.eof())
    {
      std::cout << "Неверный размер массива. Число элементов меньше, чем размер массива" << std::endl;
      return;
    }
    iStream >> p_arr[i];
  }

  std::string temp;
  if(iStream >> temp)
    {std::cout << "Неверный размер массива. Число элементов юольше, чем размер массива" << std::endl;}
}

void printArrayReverse(int* p_arr, int size)
{
  for (int i = size - 1; i >= 0; i--)
    {std::cout << p_arr[i] << " ";}
}