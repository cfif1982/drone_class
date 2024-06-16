#include <iostream>
#include <string>    // для работы с типом string
#include <cmath>     // для использования sin и cos
#include <windows.h> // нужна для вывода русских букв в консоли. Иначе иероглифы выводятся.

using namespace std; // для удобства использования cin и cout

// структура для храения действия дрона
struct action
{
  string actionType; //  тип действия: m - move, t - turn ...
  int actionParam;   // параметр для этого действия: move(30)/ Здесь 30 - это параметр дейсттвия
};

// класс дрона
class drone
{
public:
  // выводит текущие координаты и угол поворота дрона
  void printCurrentCoords()
  {
    cout << "координаты: " << "(" << x << ", " << y << ", " << z << ")" << "; угол: " << angle << endl;
  }

  // движение дрона по направлению поворота на заданную дистанцию
  void move(int distance)
  {
    // переводим угол из градусов в радианы. Это нужно для использования функций sin и cos
    double radians = angle * 3.14 / 180.0;

    // находим синус и косинус угла направления дрона
    double sine = sin(radians);
    double cosine = cos(radians);

    // нгаходим координаты перемещения дрона
    double x1 = distance * cosine;
    double y1 = distance * sine;

    // если высота дрона равна 0, то дрон не двигается
    // в протвном случае - перемещаемся на заданные координаты
    if (z != 0)
    {
      x = x + x1;
      y = y + y1;
    }
  }

  // меняем угол поворота дрона
  void turn(int _angle)
  {
    angle = _angle;
  }

  // меняем высоту дрона
  void changeHeight(int height)
  {
    z = z + height;

    // высота дрона не может быть меньше 0
    if (z < 0)
    {
      z = 0;
    }
  }

  void loadProgram(const string mas[], int masSize)
  {
    // // разбираем строку
    // string str = "m 200";
    // string part1 = str.substr(0, 1);
    // int len = str.size() - 2;
    // string part2 = str.substr(2, len);
    // cout << part1 << endl;
    // cout << part2 << endl;
    // cout << len << endl;

    // // переводим строку в число
    // int num = stoi(part2);
    // cout << num << endl;

    program[0].actionType = part1;
  }

private:
  // храним координаты дрона
  double x = 0;
  double y = 0;

  double z = 0; // храним высоту дрона

  double angle = 0; // храним угол поворота дрона

  action program[10]; // массив из 10 элементов типа action
};

int main()
{
  // этой функцией мы устанавливаем нужную кодировку. И русские буквы правильно отображаюьтся
  SetConsoleOutputCP(CP_UTF8); // нужна для вывода русских букв в консоли. Иначе иероглифы выводятся

  drone copter;

  const int size = 10;
  string mas[size]; // массив для хранения введенных пользователем строк

  int commandCount = 0; // счетчик индекса массива

  string cmd; // храним строку-команду от юзера

  // цикл запроса команд от юзера
  while (true)
  {
    cout << "Введите команду: ";
    cin >> cmd;

    // если команда start, то выходим из цикла
    if (cmd == "start")
    {
      break;
    }

    // сохраняем команду в массив из переменной cmd
    mas[commandCount++] = cmd;
  }

  // загружаем команды в дрон
  copter.loadProgram(mas, size);

  //  for (int i = 0; i <= size; ++i)
  //  {
  //    string _cmd = mas[i];

  //   if (_cmd == "m")
  //   {
  //     int _distance;
  //     cout << "Введите расстояние: ";
  //     cin >> _distance;
  //     copter.move(_distance);
  //     copter.printCurrentCoords();
  //   }
  //   else if (_cmd == "r")
  //   {
  //     int _angle;
  //     cout << "Введите угол поворота: ";
  //     cin >> _angle;
  //     copter.turn(_angle);
  //     copter.printCurrentCoords();
  //   }
  //   else if (_cmd == "h")
  //   {
  //     int _rise;
  //     cout << "Введите изменение высоты: ";
  //     cin >> _rise;
  //     copter.changeHeight(_rise);
  //     copter.printCurrentCoords();
  //   }
  //   else
  //   {
  //     cout << "Неизвестная команда. Попробуйте ещё раз." << endl;
  //   }
  // }

  return 0;
}
