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

  fillArray(ppArr, rows, columns, '-');

  while (iStream >> row)
  {
    if (iStream >> column)
    {
      if ((row >= rows) || (column >= columns))
      {
        std::cout << "Неверный размер массива. Некоторые значения выходят за размер массива" << std::endl;
        continue;
      }

      ppArr[row][column] = '*';
    }
    else
    {
      std::cout << "Неверный формат файла. Нет значения столбца для указанной строки. Последняя ячейка отброшена" << std::endl;
      return;
    }
  }
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


void printArray(const char* const* pp_arr, const int rows, const int columns)
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