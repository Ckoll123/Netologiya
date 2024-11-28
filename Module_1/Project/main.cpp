#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstdlib>

#include "Array.h"
#include "LiveGame.h"

int main() { 

  std::cout << "Игра \"Жизнь\"\n\n";

  std::ifstream iFile ("in.txt");

  char** ppCurrentGen;

  if (iFile.is_open())
  {
    iFile >> game::rows;
    iFile >> game::columns;

    ppCurrentGen = createDoubleArray(game::rows, game::columns);
    fillArray(ppCurrentGen, game::rows, game::columns, iFile);
  }
  else
  {
    std::cout << "Не удалось открыть файл" << std::endl;
    std::cout << "Применён стандарный массив 3х3 проинициализированный '-'" << std::endl;
    ppCurrentGen = createDoubleArray(game::rows, game::columns);
    fillArray(ppCurrentGen, game::rows, game::columns, '-');
  }
  iFile.close();

  char** ppPrevGen = createDoubleArray(game::rows, game::columns);
  fillArray(ppPrevGen, game::rows, game::columns, '-');

  game::checkForTheEndOfGame(ppCurrentGen, ppPrevGen, game::rows, game::columns);
  game::printGenerationState(ppCurrentGen, game::rows, game::columns);
  
  while(!game::gameOver)
  {
    game::solveForNewGeneration(ppCurrentGen, ppPrevGen, game::rows, game::columns);
    game::checkForTheEndOfGame(ppCurrentGen, ppPrevGen, game::rows, game::columns);
    // std::system("clear");
    game::printGenerationState(ppCurrentGen, game::rows, game::columns);
    // sleep(1);
  }

  game::deleteArrays(ppCurrentGen, ppPrevGen, game::rows, game::columns);
}
