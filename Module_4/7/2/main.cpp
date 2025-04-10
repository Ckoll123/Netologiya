#include <iostream>
#include <fstream>
#include <queue>

int** createDoubleArray(int rows, int columns);
void fillArray(int** p_arr, int rows, int columns, std::ifstream& iStream);
void deleteDoubleArray(int** pp_arr, int rows, int colums);
void graphWidthRounds(int** pp_graph, int startVertex, bool* visitedVertexesArr, int size);


int main(){
    std::ifstream iFile("input.txt");

    if (iFile.is_open())
    {
        int vertexes;
        iFile >> vertexes;

        int** pp_graph = createDoubleArray(vertexes, vertexes);
        fillArray(pp_graph, vertexes, vertexes, iFile);
        bool visitedVertexes[vertexes] = {};

        int startVertex{};
        std::cout << "В графе " << vertexes << " вершин. Введите номер вершины, с которой начнётся обход: ";
        std::cin >> startVertex;
        while ((startVertex > vertexes) && (startVertex <= 0)){
            std::cout << "Введите корректный номер вершины, с которой начнётся обход: ";
            std::cin >> startVertex;
        }
        std::cout << "Порядок обхода вершин: ";

        graphWidthRounds(pp_graph, startVertex, visitedVertexes, vertexes);

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


void graphWidthRounds(int** pp_graph, int startVertex, bool* visitedVertexesArr, int size){
    if (startVertex > size || startVertex < 1){
        std::cerr << "Не существует вершины № " << startVertex <<"!" << std::endl;
        return;
    }

    std::queue<int>queue{};
    startVertex--;

    // queue.push(startVertex);
    // visitedVertexesArr[startVertex] = true;
    // std::cout << startVertex + 1 << " ";
    bool exit{false};
    for (int i = startVertex; i < size; i++){

        if ((i == size - 1) && !exit) {
            i = 0;
            size = startVertex;
            exit = true;
        }

        if (!visitedVertexesArr[i]){
            queue.push(startVertex);
            visitedVertexesArr[startVertex] = true;
            while (!queue.empty()){
                int currentVertex{};
                currentVertex = queue.front();
                queue.pop();

                std::cout << currentVertex + 1 << " ";

                for (int j = 0; j < size; j++){
                    if(pp_graph[currentVertex][j] && !visitedVertexesArr[j]){
                        visitedVertexesArr[j] = true;
                        queue.push(j);
                    }
                }
            }
        }
    // 1    0 0 1 0 0 1 1
    // 2    0 0 1 1 0 0 1
    // 3    1 1 0 0 0 0 1
    // 4    0 1 0 0 1 0 0 
    // 5    0 0 0 1 0 0 1 
    // 6    1 0 0 0 0 0 1 
    // 7    1 1 1 0 1 1 0

        // 1 3 6 7 2 5 4

        // if (!visitedVertexesArr[i]){
        //     visitedVertexesArr[i] = true;
        //     std::cout << i + 1 << " ";

        //     for (int j = 0; j < size; j++){
        //         if(pp_graph[i][j] && !visitedVertexesArr[j]){
        //             visitedVertexesArr[j] = true;
        //             std::cout << j + 1 << " ";
        //         }
        //     }
        // }


    }
}
