#include <iostream>
#include <fstream>

int** createDoubleArray(int rows, int columns);
bool* createArrayBool(int rows, int columns);
void fillArray(int** p_arr, int rows, int columns, std::ifstream& iStream);
void fillArray(bool* p_arr, int size);
void deleteDoubleArray(int** pp_arr, int rows, int colums);
bool dfs(int** pp_graph, int startVertex, bool* visitedVertexesArr, int size, int prevVertex);


int main(){
    std::ifstream iFile("input.txt");

    if (iFile.is_open())
    {
        int vertexes;
        iFile >> vertexes;

        int** pp_graph = createDoubleArray(vertexes, vertexes);
        bool* p_visitedVertexes = createArrayBool(vertexes, vertexes);
        fillArray(pp_graph, vertexes, vertexes, iFile);
        fillArray(p_visitedVertexes, vertexes);
        // bool visitedVertexes[vertexes] = {};
        bool isCycle{false};

        // std::cout << "Порядок обхода вершин: ";

        for (int i = 0; i < vertexes; i++){
            if (!p_visitedVertexes[i])
                isCycle = dfs(pp_graph, i, p_visitedVertexes, vertexes, -1);
        }

        if(isCycle)
          std::cout << "В графе есть цикл!" << std::endl;
        else
          std::cout << "В графе нет циклов" << std::endl;

        deleteDoubleArray(pp_graph, vertexes, vertexes);
        delete[] p_visitedVertexes;
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

bool* createArrayBool(int rows, int columns){
  bool* p_arr = new bool[rows];

  return p_arr;
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


void fillArray(bool* p_arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    p_arr[i] = false;
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


bool dfs(int** pp_graph, int startVertex, bool* visitedVertexesArr, int size, int prevVertex){
    if (startVertex > size){
        std::cerr << "Не существует вершины № " << startVertex <<"!" << std::endl;
    }

    bool isCycle{false};

    visitedVertexesArr[startVertex] = true;
    // std::cout << startVertex + 1 << " ";

    for (int i = 0; i < size; i++){
		if(pp_graph[startVertex][i]){
			if(!visitedVertexesArr[i]){
				dfs(pp_graph, i, visitedVertexesArr, size, startVertex);
			}
			else if (i != prevVertex)
				return true;
		}
    }
	return false;
}

// 0 0 1 0
// 0 0 1 1
// 1 1 0 0
// 0 1 0 0
