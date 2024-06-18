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
  void printCurrentCoords(); // выводит текущие координаты и угол поворота дрона

  void move(int distance); // движение дрона по направлению поворота на заданную дистанцию

  void turn(int _angle); // меняем угол поворота дрона

  void changeHeight(int height); // меняем высоту дрона

  void loadProgram(const string mas[], int masSize); // загружаем программу в дрон

private:
  // храним координаты дрона
  double x = 0;
  double y = 0;

  double z = 0; // храним высоту дрона

  double angle = 0; // храним угол поворота дрона

  action obj;

  action program[10]; // массив из 10 элементов типа action
};