#include "drone_class.h"

// выводит текущие координаты и угол поворота дрона
void drone::printCurrentCoords()
{
  cout << "координаты: " << "(" << x << ", " << y << ", " << z << ")" << "; угол: " << angle << endl;
};

// движение дрона по направлению поворота на заданную дистанцию
void drone::move(int distance)
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
};

// меняем угол поворота дрона
void drone::turn(int _angle)
{
  angle = _angle;
};

// меняем высоту дрона
void drone::changeHeight(int height)
{
  z = z + height;

  // высота дрона не может быть меньше 0
  if (z < 0)
  {
    z = 0;
  }
};

// загружаем программу в дрон
void drone::loadProgram(const string mas[], int masSize)
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

  // program[0].actionType = part1;

  for (int i = 0; i < masSize; i++)
  {
    string temp = mas[i];

    string com = temp.substr(0, 1);

    program[0].actionType = com;
    int len = temp.size() - 2;
    string param = temp.substr(2, len);

    int num = stoi(param);

    program[0].actionParam = num;
  }
};