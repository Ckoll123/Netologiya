#pragma once

#include <iostream>

#include "Array.h"


namespace game
{
  extern int rows;
  extern int columns;
  extern int generation;
  extern int cellsAlive;
  extern bool gameOver;

  void solveForNewGeneration(char** ppNewGeneration, char** ppOldGeneration, const int rows, const int columns);
  void checkDeadCell(char** const ppRealArray, char** ppTempArray, const int linePosition, const int columnPosition);
  void checkAliveCell(char** const ppRealArray, char** ppTempArray, const int linePosition, const int columnPosition);
  bool isCurrentCell(int currentLine, int linePosition, int currentColumn, int columnPosition);

  void checkForTheEndOfGame(char** ppNewGeneration, char** ppOldGeneration, const int rows, const int columns);

  void printGenerationState(char** ppNewGeneration, const int rows, const int columns);
  void printNewGeneration(char** ppArr, const int rows, const int columns, const int generation, const int cellsAlive);
  void printBadEnd(char** ppArr, const int rows, const int columns, const int generation, const int cellsAlive);
  void printHappyEnd(char** ppArr, const int rows, const int columns, const int generation, const int cellsAlive);

  void deleteArrays(char** ppNewGeneration, char** ppOldGeneration, const int rows, const int columns);
}