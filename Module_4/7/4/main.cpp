#include <iostream>
#include <fstream>

int** createDoubleArray(int rows, int columns);
int* createArray(int rows, int columns);
void fillArray(int** p_arr, int rows, int columns, std::ifstream& iStream);
void fillArray(int* p_arr, int size);
void deleteDoubleArray(int** pp_arr, int rows, int colums);
void dfs(int** pp_graph, int startVertex, int* visitedVertexesArr, int size, int cycleNumber);
void printResult(int* arr, int size, int counter);


int main(){
    std::ifstream iFile("input.txt");

    if (iFile.is_open())
    {
        int vertexes;
        iFile >> vertexes;

        int** pp_graph = createDoubleArray(vertexes, vertexes);
        int* p_visitedVertexes = createArray(vertexes, vertexes);
        fillArray(pp_graph, vertexes, vertexes, iFile);
        fillArray(p_visitedVertexes, vertexes);
        int counter{0};

        for (int i = 0; i < vertexes; i++){
            if (!p_visitedVertexes[i])
                counter++;
                dfs(pp_graph, i, p_visitedVertexes, vertexes, counter);
        }

        printResult(p_visitedVertexes, vertexes, counter);

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

int* createArray(int rows, int columns){
    int* p_arr = new int[rows];
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


void fillArray(int* p_arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        p_arr[i] = 0;
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


void dfs(int** pp_graph, int startVertex, int* visitedVertexesArr, int size, int cycleNumber){
    if (startVertex > size){
        std::cerr << "Не существует вершины № " << startVertex <<"!" << std::endl;
    }

    visitedVertexesArr[startVertex] = cycleNumber;

    for (int i = 0; i < size; i++){
        if(pp_graph[startVertex][i] && !visitedVertexesArr[i]){
            dfs(pp_graph, i, visitedVertexesArr, size, cycleNumber);
        }
    }
}


void printResult(int* arr, int size, int counter){
    std::cout << "Принадлежность вершин компонентам связности:" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << i + 1 << " - " << arr[i] << std::endl;
    }
    std::cout << "Количество компонентов связности в графе: " << counter << std::endl;
}
