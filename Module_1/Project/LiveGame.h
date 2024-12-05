#pragma once

#include <iostream>

#include "Array.h"

#define AliveCell '*'
#define DeadCell '-'

namespace game
{
  extern int rows;
  extern int columns;
  extern int generation;
  extern int cellsAlive;
  extern bool gameOver;

  void solveForNewGeneration(char** ppNewGeneration, char** ppOldGeneration, const int rows, const int columns);
  void checkDeadCell(char** ppRealArray, char** ppTempArray, const int linePosition, const int columnPosition);
  void checkAliveCell(char** ppRealArray, char** ppTempArray, const int linePosition, const int columnPosition);
  bool isCurrentCell(const int currentLine, const int linePosition, const int currentColumn, const int columnPosition);

  void checkForTheEndOfGame(const char* const* ppNewGeneration, const char* const* ppOldGeneration, const int rows, const int columns);

  void printGenerationState(const char* const* ppNewGeneration, const int rows, const int columns);
  void printNewGeneration(const char* const* ppArr, const int rows, const int columns, const int generation, const int cellsAlive);
  void printBadEnd(const char* const* ppArr, const int rows, const int columns, const int generation, const int cellsAlive);
  void printHappyEnd(const char* const* ppArr, const int rows, const int columns, const int generation, const int cellsAlive);

  void deleteArrays(char** ppNewGeneration, char** ppOldGeneration, const int rows, const int columns);
}