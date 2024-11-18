#pragma once

#include <iostream>


int** create_two_dim_array(int rows, int cols);
void fill_two_dim_array(int** pp_arr, int rows, int colums);
void print_two_dim_array(int** pp_arr, int rows, int colums);
void delete_two_dim_array(int** pp_arr, int rows, int colums);