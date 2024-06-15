#include <iostream>
#include <string>
#include <cmath>
#include <windows.h> // нужна для вывода русских букв в консоли. Иначе иероглифы выводятся. 

using namespace std;

// m 50
// start
// print

class drone
{
public:
  void command()
  {
    cout << "Введите команду (m - движение вперёд, r - поворот, h - изменение высоты): ";
    cin >> com;
  }

  char getCom()
  {
    return com;
  }

  void printCurrentCoords()
  {
    cout << "Текущие координаты дрона: " << "(" << x << ", " << y << ", " << z << ")" << " Текущий угол поворота дрона: " << angle << " градусов" << endl;
  }

  void move(int distance)
  {
    double radians = angle * 3.14 / 180.0;

    double sine = sin(radians);
    double cosine = cos(radians);

    double x1 = distance * cosine;
    double y1 = distance * sine;

    if (z != 0)
    {
      x = x + x1;
      y = y + y1;
    }
  }

  void turn(int _angle)
  {
    angle = _angle;
  }

  void heightChange(int _rise)
  {
    z = z + _rise;

    if (z < 0)
    {
      z = 0;
    }
  }

private:
  char com;
  double x = 0;
  double y = 0;
  double z = 0;
  double angle = 0;
};


// у тебя другой компилятор((( сейчас настройки поправим. Но тогда каждый раз придется у меня их  менять, чтобы на моем компе можно было запускать без проблем
//а потом у тебя обратно менять
// чтобы этого не делать, мы исключим файлы launch и tasks из обновления в git

int main()
{
  // этой функцией мы устанавливаем нужную кодировку. И русские буквы правильно отображаюьтся
  SetConsoleOutputCP(CP_UTF8); // нужна для вывода русских букв в консоли. Иначе иероглифы выводятся

  drone copter;

  const int size = 10;
  string mas[size];

  cout << "Введите команду: ";
  // for (int i = 0; i < size; ++i)
  // {
  //   cin >> mas[i];
  // }
  int i = 0;

  while (true)
  {
    string cmd;

    cin >> cmd;

    if (cmd == "start")
    {
      break;
    }

    mas[i] = cmd;

    i++;
  }

  /*while (true)
  {
    copter.command();
    char command = copter.getCom();

    if (command == 'm')
    {
      int _distance;
      cout << "Введите расстояние: ";
      cin >> _distance;
      copter.move(_distance);
      copter.printCurrentCoords();
    }
    else if (command == 'r')
    {
      int _angle;
      cout << "Введите угол поворота: ";
      cin >> _angle;
      copter.turn(_angle);
      copter.printCurrentCoords();
    }
    else if (command == 'h')
    {
      int _rise;
      cout << "Введите изменение высоты: ";
      cin >> _rise;
      copter.heightChange(_rise);
      copter.printCurrentCoords();
    }
    else if (command == 'q')
    {
      break;
    }
    else
    {
      cout << "Неизвестная команда. Попробуйте ещё раз." << endl;
    }
  }*/

  return 0;
}
