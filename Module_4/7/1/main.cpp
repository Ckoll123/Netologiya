#include <iostream>
#include <fstream>

int** createDoubleArray(int rows, int columns);
void fillArray(int** p_arr, int rows, int columns, std::ifstream& iStream);
void deleteDoubleArray(int** pp_arr, int rows, int colums);
void graphDepthRounds(int** pp_graph, int startVertex, bool* visitedVertexesArr, int size);


int main(){
    std::ifstream iFile("input.txt");

    if (iFile.is_open())
    {
        int vertexes;
        iFile >> vertexes;

        int** pp_graph = createDoubleArray(vertexes, vertexes);
        fillArray(pp_graph, vertexes, vertexes, iFile);
        bool visitedVertexes[vertexes] = {};

        std::cout << "Порядок обхода вершин: ";

        for (int i = 0; i < vertexes; i++){
            if (!visitedVertexes[i])
                graphDepthRounds(pp_graph, i, visitedVertexes, vertexes);
        }

        deleteDoubleArray(pp_graph, vertexes, vertexes);
    }
    else
      {std::cerr << "Не удалось открыть файл" << std::endl;}
    
    iFile.close();

    return 0;
}


int** createDoubleArray(int rows, int columns){
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
        std::cerr << "Неверный размер массива. Число элементов меньше, чем размер массива" << std::endl;
        return;
      }

      iStream >> p_arr[i][j];
    }
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


void graphDepthRounds(int** pp_graph, int startVertex, bool* visitedVertexesArr, int size){
    if (startVertex > size){
        std::cerr << "Не существует вершины № " << startVertex <<"!" << std::endl;
        return;
    }

    visitedVertexesArr[startVertex] = true;
    std::cout << startVertex + 1 << " ";

    for (int i = 0; i < size; i++){
        if(pp_graph[startVertex][i] && !visitedVertexesArr[i]){
            graphDepthRounds(pp_graph, i, visitedVertexesArr, size);
        }
    }
}
