#include "Task3.h"

int** create_two_dim_array(int rows, int colums)
{
  int** pp_arr = new int*[rows];
  for (int i = 0; i < rows; i++)
    {pp_arr[i] = new int[colums]{};}

  return pp_arr;
}

void fill_two_dim_array(int** pp_arr, int rows, int colums)
{
  for(int i = 0; i < rows; i++) 
  {
    for(int j = 0; j < colums; j++)
    {
      pp_arr[i][j] = (i + 1) * (j + 1);
    }
  }
}

void print_two_dim_array(int** pp_arr, int rows, int colums)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < colums; j++)
    {
      std::cout << pp_arr[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}

void delete_two_dim_array(int** pp_arr, int rows, int colums)
{
  for (int i = 0; i < rows; i++)
  {
    delete[] pp_arr[i];
  }
  delete[] pp_arr;
}