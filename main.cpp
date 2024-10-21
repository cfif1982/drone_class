#include <iostream>
#include <string>
#include <cmath>
#include <windows.h> // нужна для вывода русских букв в консоли. Иначе иероглифы выводятся. 

using namespace std;

class drone
{
public:
  void command()
  {
    cout << "Введите команду (m - движение вперёд, r - поворот, h - изменение высоты): ";
    cin >> com;
  } //получаем команду

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
    double radians = angle * M_PI / 180.0;

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
  double angle = 0; //поля класса дрона
};
int main()
{
  // этой функцией мы устанавливаем нужную кодировку. И русские буквы правильно отображаются
  SetConsoleOutputCP(CP_UTF8); // нужна для вывода русских букв в консоли

  drone copter;

  const int size = 3;
  string mas[size]; //массив для хранения команд и их значений

  //считывание команд в массив
  cout << "Введите команды: " << endl;
  for (int i = 0; i < size; ++i) //считываем команды и значения
  {
    getline(cin, mas[i]);

    char command = mas[i][0]; //здесь хранится команда
    string value_str = mas[i].substr(2);
    int value = stoi(value_str); //здесь хранится значение

    if (command == 'h')
    {
      copter.heightChange(value);
    }
    else if (command == 't')
    {
      copter.turn(value);
    }
    else if (command =='m')
    {
      copter.move(value);
    }
    else
    {
      cout << "Неверная команда." << endl;
      return 0;
    }
    copter.printCurrentCoords();
  }
  return 0;
}