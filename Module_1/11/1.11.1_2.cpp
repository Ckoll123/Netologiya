#include <iostream>
#include <cstring>
#include <stdio.h>

int main() { 

  // Task 1
  std::cout << "Задание №1. Приветствие:\n\n";

  std::cout << "Введите имя: ";
  std::string name;
  std::getline(std::cin >> std::ws, name);
  
  std::cout << "Введите фамилию: ";
  std::string surname;
  std::getline(std::cin >> std::ws, surname);

  std::cout << "Здравствуйте, " + name + " " + surname + "!" << std::endl;


  //---------------------с C строками
  std::cout << std::endl << std::endl;
  std::cout << "Задание №1. Приветствие (C строки):\n\n";
  
  std::cout << "Введите имя: ";
  char nameC[50];
  std::cin >> nameC;
  size_t length = strlen(nameC);
  nameC[length] = ' '; 
  nameC[length+1] = '\0'; 

  std::cout << "Введите фамилию: ";
  char surnameC[25];
  std::cin >> surnameC;

  std::cout << "Здравствуйте, " << strcat(nameC, surnameC) << "!" << std::endl;


  //-----------------------------------------------------------------

  // Task 2
  std::cout << std::endl << std::endl;
  std::cout << "Задание №2. Угадайка:\n\n";

  std::string word {"малина"};
  std::cout << "Угадайте слово: ";
  std::string guess;
  std::getline(std::cin >> std::ws, guess);

  while(word != guess)
  {
    std::cout << "Угадайте слово: ";
    std::getline(std::cin >> std::ws, guess);
  }

  std::cout << "Правильно! Вы победили! Загаданное слово — " + word << std::endl;

//---------------------с C строками
  std::cout << std::endl << std::endl;
  std::cout << "Задание №2. Угадайка:\n\n";

  const char* wordC {"малина"};
  std::cout << "Угадайте слово: ";
  char guessC[50];
  std::cin >> guessC;
  
  while(strcmp(wordC, guessC))
  {
    std::cout << "Угадайте слово: ";
    std::cin >> guessC;
  }

  std::cout << "Правильно! Вы победили! Загаданное слово — " << wordC << std::endl;
  
}