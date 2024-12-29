#include <iostream>
#include <string>
#include <cmath>
#include <windows.h> // нужна для вывода русских букв в консоли. Иначе иероглифы выводятся.

using namespace std;

const int SIZE1 = 10; // количество элементов в массиве команд
// move_50;height_30;rotate_40;
// move:50;height:30;rotate:40;

struct Command
{
  string type;
  int value;
};

class drone
{
public:
  // получаем данные от юзера
  void dataReceive()
  {
    string data;               // храним введенные юзером данные
    string next_command = ";"; // отделяет команды
    string next_value = "_";   // отделяет тип и значение
    int com_counter = 0;       // счетчик команд в массиве
    bool flag_type = true;     // флаг для определения с чем работаем: тип или значение
    // временная переменная для хранения значения команды в виде строки
    // когда эта строку будет полностью сформирована, тогда конвертирем ее в число
    string temp = "";

    cout << "Введите данные: ";
    cin >> data; // сохраняем введенные данные в com

    for (int i = 0; i < data.size(); i++)
    {
      // если текущий символ == ";" то это означает
      // что мы начинаем работать со следующей командой
      // а текущая команда закончилась
      if (data.substr(i, 1) == next_command)
      {
        // переводим строку в число и сохраняем его в массив команд
        commands[com_counter].value = stoi(temp);

        temp = "";        // обнуляем строку для числа
        flag_type = true; // устанавливаем флаг типа. Это означает что будет записываться тип команды

        com_counter++; // переходим к записи в следующий элемент массива команд
      }
      // если текущий символ == " "
      else if (data.substr(i, 1) == next_value)
      {
        // снимаем флаг работы с типом команды
        // это значит, что мы закончили работать с типом комнады
        // и начинаем рабоать со значением команды
        flag_type = false;
      }
      // если это любой другой символ
      else
      {
        // если мы сейчас работаем с типом команды
        if (flag_type == true)
        {
          // добавляем текущий символ к полю тип команды
          commands[com_counter].type += data.substr(i, 1);
        }
        // иначе означает, что мы сейчас рабоатем со значением команды
        else
        {
          // добавляем текущий символ к переменной в которой хранится значение команды
          // чтобы в дальнейшем перевести эту строку в число
          temp += data.substr(i, 1);
        }
      }
    }

    for (int i = 0; i < com_counter; i++)
    {
      cout << "Команда:" << commands[i].type << endl;
      cout << "Значение:" << commands[i].value << endl;
    }
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
  // поля класса дрона
  double x = 0;
  double y = 0;
  double z = 0;
  double angle = 0;

  Command commands[SIZE1]; // массив команд
};
int main()
{
  // этой функцией мы устанавливаем нужную кодировку. И русские буквы правильно отображаются
  SetConsoleOutputCP(CP_UTF8); // нужна для вывода русских букв в консоли

  drone copter;

  copter.dataReceive();

  return 0;
}