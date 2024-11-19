#include <iostream>
#include <string> 

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
}