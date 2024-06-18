#include <iostream>
#include <string>    // для работы с типом string
#include <cmath>     // для использования sin и cos
#include <windows.h> // нужна для вывода русских букв в консоли. Иначе иероглифы выводятся.

#include "drone_class.h" // подключаем класс дрона

using namespace std; // для удобства использования cin и cout

const int array_size = 10; // размер массива mas

void printStrings(const std::string arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    std::cout << arr[i] << std::endl;
  }
}

/*
в tasks.json измени строчки:
"-g",
"*.cpp", - вот так должжна строка выглядеть
*/
int main()
{
  action obj1;
  obj1.actionType = "q1";
  obj1.actionParam = 200;

  action obj2;
  obj1.actionType = "q2";
  obj1.actionParam = 300;

  action obj3;
  obj1.actionType = "q3";
  obj1.actionParam = 100;

  string name1 = "Nastya1";
  string name2 = "Nastya2";
  string name3 = "Nastya3";

  string mas_string[3];

  mas_string[0] = name1;
  mas_string[1] = name2;
  mas_string[2] = name3;

  cout << mas_string[0] << endl;

  action mas_act[3]; // массив из 10 элементов типа action
  mas_act[0] = obj1;
  mas_act[1] = obj2;
  mas_act[2] = obj3;

  cout << mas_act[0].actionParam << endl;

  mas_act[1].actionParam = 400;

  int a = mas_act[2].actionParam;

  // этой функцией мы устанавливаем нужную кодировку. И русские буквы правильно отображаюьтся
  SetConsoleOutputCP(CP_UTF8); // нужна для вывода русских букв в консоли. Иначе иероглифы выводятся

  drone copter; // инициализируем объект коптер

  string mas[array_size]; // массив для хранения введенных пользователем строк

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
  copter.loadProgram(mas, array_size);

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
