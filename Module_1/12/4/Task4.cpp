#include "Task4.h"

int** createDoubleArray(int rows, int columns)
{
  int** pp_arr = new int*[rows];
  for (int i = 0; i < rows; i++)
    {pp_arr[i] = new int[columns]{};}

  return pp_arr;
}


void fillArray(int** p_arr, int rows, int columns, std::ifstream& iStream)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if(iStream.eof())
      {
        std::cout << "Неверный размер массива. Число элементов меньше, чем размер массива" << std::endl;
        return;
      }

      iStream >> p_arr[i][j];
    }
  }

  std::string temp;
  if(iStream >> temp)
    {std::cout << "Неверный размер массива. Число элементов юольше, чем размер массива" << std::endl;}
}


void printArrayReverse(int** pp_arr, int rows, int columns)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = columns - 1; j >= 0; j--)
      {std::cout << pp_arr[i][j] << " ";}
    std::cout << std::endl;
  }
}


void deleteDoubleArray(int** pp_arr, int rows, int colums)
{
  for (int i = 0; i < rows; i++)
  {
    delete[] pp_arr[i];
  }
  delete[] pp_arr;
}