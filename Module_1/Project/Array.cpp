#include "Array.h"

char** createDoubleArray(int rows, int columns)
{
  char** pp_arr = new char*[rows];
  for (int i = 0; i < rows; i++)
    {pp_arr[i] = new char[columns]{};}

  return pp_arr;
}


void fillArray(char** ppArr, int rows, int columns, std::ifstream& iStream)
{
  int row{rows};
  int column{columns};

  iStream >> row;
  iStream >> column;
  if ((row >= rows) || (column >= columns))
    {std::cout << "Неверный размер массива. Некоторые значения выходят за размер массива" << std::endl;}

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if ((i == row) && (j == column))
      {
        ppArr[i][j] = '*';
        iStream >> row;
        iStream >> column;

        if ((row >= rows) || (column >= columns))
          {std::cout << "Неверный размер массива. Некоторые значения выходят за размер массива" << std::endl;}
      }
      else {ppArr[i][j] = '-';}
    }
  }

  int temp{0};
  iStream >> temp;
  if(temp) 
    {std::cout << "Неверный размер массива. Некоторые значения выходят за размер массива" << std::endl;}
}


void fillArray(char** ppArr, int rows, int columns, char initSymbol)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      {ppArr[i][j] = initSymbol;}
  }
}


void fillArray(char** ppArrCopyTo, int rows, int columns, char** ppArrCopyFrom)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      {ppArrCopyTo[i][j] = ppArrCopyFrom[i][j];}
  }
}


void printArray(char** pp_arr, const int rows, const int columns)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      {std::cout << pp_arr[i][j] << " ";}
    std::cout << std::endl;
  }
}


void deleteDoubleArray(char** pp_arr, const int rows, const int columns)
{
  for (int i = 0; i < rows; i++)
    {delete[] pp_arr[i];}
  delete[] pp_arr;
}