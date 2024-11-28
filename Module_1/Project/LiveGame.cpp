#include "LiveGame.h"

namespace game
{
  int rows{3};
  int columns{3};
  int generation{1};
  int cellsAlive{0};
  bool gameOver{false};

  void solveForNewGeneration(char** ppNewGeneration, char** ppOldGeneration, const int rows, const int columns)
  {
    fillArray(ppOldGeneration, rows, columns, ppNewGeneration);

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
      {
        if (ppOldGeneration[i][j] == '-')
          {checkDeadCell(ppNewGeneration, ppOldGeneration, i, j);}
        else if (ppOldGeneration[i][j] == '*')
          {checkAliveCell(ppNewGeneration, ppOldGeneration, i, j);}
      }
    }

    game::generation++;
  }


  void checkDeadCell(char** const ppRealArray, char** ppTempArray, const int linePosition, const int columnPosition)
  {
    cellsAlive = 0;

    int lineStart = (linePosition - 1) < 0 ? linePosition : (linePosition - 1);
    int lineEnd = (linePosition + 1) >= game::rows ?  linePosition: (linePosition + 1);

    int columnStart = (columnPosition - 1) < 0 ? columnPosition : (columnPosition - 1);
    int columnEnd = (columnPosition + 1) >= game::rows ?  columnPosition: (columnPosition + 1);

    for(int i = lineStart; i <= lineEnd; i++)
    {
      for (int j = columnStart; j <= columnEnd; j++)
      {
        if (!isCurrentCell(i, linePosition, j, columnPosition))
          {if (ppTempArray[i][j] == '*') {cellsAlive++;}}
      }
    }

    if (cellsAlive == 3)
      {ppRealArray[linePosition][columnPosition] = '*';}
  }


  void checkAliveCell(char** const ppRealArray, char** ppTempArray, const int linePosition, const int columnPosition)
  {
    cellsAlive = 0;

    int lineStart = (linePosition - 1) < 0 ? linePosition : (linePosition - 1);
    int lineEnd = (linePosition + 1) >= game::rows ?  linePosition: (linePosition + 1);

    int columnStart = (columnPosition - 1) < 0 ? columnPosition : (columnPosition - 1);
    int columnEnd = (columnPosition + 1) >= game::rows ?  columnPosition: (columnPosition + 1);

    for(int i = lineStart; i <= lineEnd; i++)
    {
      for (int j = columnStart; j <= columnEnd; j++)
      {
        if (!isCurrentCell(i, linePosition, j, columnPosition))
          {if (ppTempArray[i][j] == '*') {cellsAlive++;}}
      }
    }

    if ( (cellsAlive < 2) || (cellsAlive > 3) )
      {ppRealArray[linePosition][columnPosition] = '-';}
  }


  bool isCurrentCell(int currentLine, int linePosition, int currentColumn, int columnPosition)
  {
    if ( (currentLine == linePosition) && (currentColumn == columnPosition) )
      {return true;}
    else {return false;}
  }


  void checkForTheEndOfGame(char** ppNewGeneration, char** ppOldGeneration, const int rows, const int columns)
  {
    cellsAlive = 0;
    bool nextGenerationsBegins{false};
    
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
      {
        if (ppNewGeneration[i][j] == '*') {cellsAlive++;}
        
        if ( (ppNewGeneration[i][j] != ppOldGeneration[i][j]) && !nextGenerationsBegins)
          {nextGenerationsBegins = true;}
      }
    }

    if ( (!cellsAlive) || !nextGenerationsBegins)
      {gameOver = true;}
    else {gameOver = false;}
  }


  void printGenerationState(char** ppNewGeneration, const int rows, const int columns)
  {
    if (!gameOver) {printNewGeneration(ppNewGeneration, rows, columns, generation, cellsAlive);}
    else
    {
      if (!cellsAlive) {printBadEnd(ppNewGeneration, rows, columns, generation, cellsAlive);}
      else {printHappyEnd(ppNewGeneration, rows, columns, generation, cellsAlive);}
    }

    std::cout << std::endl;
  }


  void printNewGeneration(char** ppArr, const int rows, const int columns, const int generation, const int cellsAlive)
  {
    printArray(ppArr, rows, columns);
    std::cout << "Generation: " << generation << ". Alive cells: " << cellsAlive << std::endl;
  }


  void printBadEnd(char** ppArr, const int rows, const int columns, const int generation, const int cellsAlive)
  {
    printArray(ppArr, rows, columns);
    std::cout << "Generation: " << generation << ". Alive cells: " << cellsAlive << std::endl;
    std::cout << "All cells are dead. Game over" << std::endl;
  }


  void printHappyEnd(char** ppArr, const int rows, const int columns, const int generation, const int cellsAlive)
  {
    printArray(ppArr, rows, columns);
    std::cout << "Generation: " << generation << ". Alive cells: " << cellsAlive << std::endl;
    std::cout << "The world has stagnated. Game over" << std::endl;
  }


  void deleteArrays(char** ppNewGeneration, char** ppOldGeneration, const int rows, const int columns)
  {
    deleteDoubleArray(ppNewGeneration, rows, columns);
    deleteDoubleArray(ppOldGeneration, rows, columns);
  }

}