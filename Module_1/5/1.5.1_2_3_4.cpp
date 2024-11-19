#include <iostream>
#include <cstdlib>  // for 3rd task
#include <ctime>  // for 3rd task

int main() {

  std::cout << "Задание №1. Вывод массива на экран\n\n";

  const int arraySize1 = 10;
  int array1[arraySize1]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  for(int i = 0; i < arraySize1; i++)
  {
    if(i == arraySize1 - 1)
    {
      std::cout << array1[i] << std::endl;
      break;
    }

    std::cout << array1[i] << ", ";
  }

  std::cout << std::endl << std::endl;


  //--------------------------------------------------------------------------

  std::cout << "Задание №2. Максимум и минимум\n\n";

  const int arraySize2 = 10;
  int array2[arraySize2]{ 4, 34, 124, -56, 8, -35, 90, 0, -46, 43 };
  int maxValue2{array2[0]};
  int minValue2{array2[0]};
  
  std::cout << "Массив: ";
  for(int i = 0; i < arraySize2; i++)
  {
    std::cout << array2[i] << " ";
    
    if(maxValue2 < array2[i])
      {maxValue2 = array2[i];}
    
    if(minValue2 > array2[i])
      {minValue2 = array2[i];}
  }
  std::cout << std::endl;
    
  std::cout << "Минимальный элемент: " << minValue2 << std::endl;
  std::cout << "Максимальный элемент: " << maxValue2 << std::endl;
  std::cout << std::endl;

  //--------------------------------------------------------------------------

  std::cout << "Задание №3. Двумерный массив\n\n";

  const int raw = 3;
  const int column = 6;
  int array3[raw][column]{};
  srand(time(0));
  for(int i = 0; i < raw; i++)
  {
    for(int j = 0; j < column; j++)
    {
      array3[i][j] = std::rand() % 201 - 100;      
    }
  }

  int maxValue3{array3[0][0]};
  int minValue3{array3[0][0]};

  int maxIndex3[2]{};
  int minIndex3[2]{};

  std::cout << "Массив:" << std::endl;
  for(int i = 0; i < raw; i++)
  {
    for(int j = 0; j < column; j++)
    {
      std::cout << array3[i][j] << "\t\t";
      
      if(maxValue3 < array3[i][j])
      {
        maxValue3 = array3[i][j];
        maxIndex3[0] = i;
        maxIndex3[1] = j;
      }

      if(minValue3 > array3[i][j])
      {
        minValue3 = array3[i][j];
        minIndex3[0] = i;
        minIndex3[1] = j;
      }
    }
    std::cout << std::endl;
  }

  std::cout << "Индекс минимального элемента: " << minIndex3[0] << " " << minIndex3[1] << std:: endl;
  std::cout << "Индекс максимального элемента: " << maxIndex3[0] << " " << maxIndex3[1] << std::endl;
  std::cout << std::endl;

  //--------------------------------------------------------------------------

  std::cout << "Задание №4. Обратный пузырёк\n\n";

  const int arraySize4 = 10;
  int array4[arraySize4]{ 124, 84, 72, 36, 18, 5, 0, -7, -26, -43 };

  std::cout << "Массив до сортировки: ";
  for(int element : array4)
    {std::cout << element << " ";}
  std::cout << std::endl;

  for(int i = 0; i < arraySize4 - 1; i++)
  {
    for(int j = arraySize4 - 1; j > 0; j--)
    {
      if(array4[j] < array4[j - 1])
      {
        int temp = array4[j - 1];
        array4[j - 1] = array4[j];
        array4[j] = temp;
      }
    }
  }

  std::cout << "Массив после сортировки: ";
  for(int element : array4)
    {std::cout << element << " ";}
  std::cout << std::endl;

  return 0;
}