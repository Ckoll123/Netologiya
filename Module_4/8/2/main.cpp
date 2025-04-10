#include <iostream>
#include <fstream>
#include <list>

int** createDoubleArray(int rows, int columns);
void fillArray(int** p_arr, int rows, int columns, std::ifstream& iStream);
void deleteDoubleArray(int** pp_arr, int rows, int colums);
void dfs(int** pp_graph, int startVertex, bool* visitedVertexesArr, int size, std::list<int>& graphOrderList);


int main(){
    std::ifstream iFile("input.txt");

    if (iFile.is_open())
    {
        int vertexes;
        iFile >> vertexes;

        int** pp_graph = createDoubleArray(vertexes, vertexes);
        fillArray(pp_graph, vertexes, vertexes, iFile);
        bool visitedVertexes[vertexes] = {};
        std::list<int> graphOrderList{};

        int startVertex{1};
        bool exit{false};
        for (int i = startVertex - 1; i < vertexes; i++){
          if (!visitedVertexes[i])
              dfs(pp_graph, i, visitedVertexes, vertexes, graphOrderList);

          if ((i == vertexes - 1) && !exit) {
            i = 0;
            vertexes = startVertex;
            exit = true;
          }
        }

        std::cout << "Топологический порядок вершин: ";
        while (!graphOrderList.empty()){
          std::cout << graphOrderList.front() << " ";
          graphOrderList.pop_front();
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


void dfs(int** pp_graph, int startVertex, bool* visitedVertexesArr, int size, std::list<int>& graphOrderList){
    if (startVertex > size){
        std::cerr << "Не существует вершины № " << startVertex <<"!" << std::endl;
        return;
    }

    visitedVertexesArr[startVertex] = true;

    for (int i = 0; i < size; i++){
        if(pp_graph[startVertex][i] && !visitedVertexesArr[i]){
            dfs(pp_graph, i, visitedVertexesArr, size, graphOrderList);
        }
    }
    graphOrderList.push_front(startVertex + 1);
}

// 1    0 0 1 0 0 0 0 0 0 
// 2    0 0 0 0 0 0 0 0 0 
// 3    0 0 0 0 1 0 1 0 0 
// 4    0 0 0 0 0 0 0 0 0 
// 5    0 0 0 0 0 1 0 0 0 
// 6    0 1 0 1 0 0 1 0 0 
// 7    0 0 0 0 0 0 0 1 0 
// 8    0 0 0 0 0 0 0 0 0 
// 9    1 0 0 0 0 0 0 0 0 