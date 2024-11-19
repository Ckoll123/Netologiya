#include <iostream>

int main() {
  // Task 1
  std::cout << "Задание №1. Таблица истинности:\n\n";
  std::cout << "Оператор ||\n";
  std::cout << "true\t" << "true\t" << "true\t" << std::endl;
  std::cout << "false\t" << "true\t" << "true\t" << std::endl;
  std::cout << "true\t" << "false\t" << "true\t" << std::endl;
  std::cout << "false\t" << "false\t" << "false\t" << '\n' << std::endl;

  std::cout << "Оператор &&\n";
  std::cout << "true\t" << "true\t" << "true\t" << std::endl;
  std::cout << "false\t" << "true\t" << "false\t" << std::endl;
  std::cout << "true\t" << "false\t" << "false\t" << std::endl;
  std::cout << "false\t" << "false\t" << "false\t" << std::endl;
          
  // Task 2
  std::cout << "\nЗадание №2. Упорядочить числа:\n\n";
  std::cout << "Введите первое число:\n";
  float firstNumber;
  std::cin >> firstNumber;
  std::cout << "Введите первое число:\n";
  float secondNumber;
  std::cin >> secondNumber;
  std::cout << "Введите третье число:\n";
  float thirdNumber;
  std::cin >> thirdNumber;

  // Change first two numbers
  float temp{firstNumber};
  firstNumber = firstNumber > secondNumber ? firstNumber : secondNumber;
  secondNumber = firstNumber == secondNumber ? temp : secondNumber;

  // Change last two numbers
  temp = secondNumber;
  secondNumber = secondNumber > thirdNumber ? secondNumber : thirdNumber;
  thirdNumber = secondNumber == thirdNumber ? temp : thirdNumber;

  // Change first two numbers
  temp = firstNumber;
  firstNumber = firstNumber > secondNumber ? firstNumber : secondNumber;
  secondNumber = firstNumber == secondNumber ? temp : secondNumber;

  std::cout << "Результат: " << firstNumber << ' ' << secondNumber << ' ' 
            << thirdNumber << '\n' << std::endl;  
}


/*
#include <iostream>
#include <string> 

std::string intToText(int inputNumber);  // for 4th task

int main() {
  // Task 3
  std::cout << "Задание №3. Гороскоп\n\n";

  std::cout << "Введите пол: ";
  std::string gender;
  std::getline(std::cin >> std::ws, gender);

  std::cout << "Введите знак зодиака: ";
  std::string zodiacSign;
  std::getline(std::cin >> std::ws, zodiacSign);

  std::cout << "Введите возраст: ";
  int age;
  std::cin >> age;

  // bool fireSign = zodiacSign == "овен" || zodiacSign == "лев" || zodiacSign
  // == "стрелец";
  bool earthSign =
    zodiacSign == "телец" || zodiacSign == "дева" || zodiacSign == "козерог";
  //  bool airSign = zodiacSign == "близнецы" || zodiacSign == "весы" ||
  //  zodiacSign == "водолей";
  bool waterSign =
    zodiacSign == "рак" || zodiacSign == "скорпион" || zodiacSign == "рыбы";

  std::cout << "Ваше предсказание: ";

  if (gender == "м" && waterSign && age <= 40) {
  std::cout << "Сегодня очень плодотворный день. Можно добиться того, что "
         "прежде казалось почти невозможным."
        << std::endl;
  } else if (gender == "ж" && earthSign && age >= 15 && age <= 30) {
  std::cout
    << "Сегодняшний вечер подходит для общения с друзьями, проведения "
       "домашних праздников и импровизированных вечеринок. Будет не только "
       "весело, но и интересно: найдётся дело, которое увлечёт всех."
    << std::endl;
  } else {
  std::cout
    << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)"
    << std::endl;
  }

  // Task 4
  std::cout << "\nЗадание №4. Сравнить числа\n\n"; 

  std::cout << "Введите целое число: " << std::endl;
  int firstNumber;
  std::cin >> firstNumber;

  std::cout << "Введите целое число: " << std::endl;
  int secondNumber;
  std::cin >> secondNumber;

  std::string number1{};
  number1 = intToText(firstNumber);
  
  std::string number2{};
  number2 = intToText(secondNumber);

  if ((number1 == "Ошибка!") || (number2 == "Ошибка!"))
  {
    std::cout << "Ошибка! Одно из чисел вне диапазона." << std::endl;
  }
  else
  {
    std::string compareSign{};
    compareSign = firstNumber > secondNumber ? " больше чем " : (firstNumber < secondNumber ? " меньше чем " : " равно ");
    std::cout << number1 << compareSign << number2 << std::endl;
  }

}

std::string intToText(int inputNumber)
{
    std::string firstAndSecondDecade[]{"один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять", "десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
  std::string decadesFrom2To9[]{"двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};

  if(inputNumber < 0)
  {return "минус " + intToText(-inputNumber);}

  if(!inputNumber)
    {return "ноль";}
  else if (inputNumber == 100)
    {return "сто";}
  else if(inputNumber < 20)
    {return firstAndSecondDecade[inputNumber-1];}
  else if(inputNumber < 100)
    {
      std::string num = decadesFrom2To9[(inputNumber/10) - 2]; 
      num = inputNumber % 10 == 0 ? num : (num + intToText(inputNumber % 10));
      return num;
    }

  return "Ошибка!";
}
*/