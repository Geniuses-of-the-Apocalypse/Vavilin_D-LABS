#include <iostream>
#include <string>
using namespace std;

const int M = 5;

//Класс
class TMyClass
{
private:
 char ch;
 long int* n;
 float statMas[M];
 double* dinMas;
 int dinSize;

public:
 TMyClass(char kch = 'S', long int kn = 12, float ksMas = 2.3, double kdMas = 25.2, int kdS = 5);
 TMyClass(const TMyClass& x);
 ~TMyClass();

 void input();
 void output();
 void fff(double d);

 friend void friendInput(TMyClass& obj);
};

//Конструктор по умолчанию
TMyClass::TMyClass(char kch, long int kn, float ksMas, double kdMas, int kdS)
{
 ch = kch;
 n = new long int;
 *n = kn;
 dinSize = kdS;

 for (int i = 0; i < M; i++)
  statMas[i] = ksMas;

 dinMas = new double[dinSize];
 for (int i = 0; i < dinSize; i++)
  dinMas[i] = kdMas;//22 * i;
}
 
 //Конструктор копирования
TMyClass::TMyClass(const TMyClass& x)
{
 ch = x.ch;
 n = new long int;
 *n = *x.n;

 for (int i = 0; i < M; i++)
  statMas[i] = x.statMas[i];

 dinSize = x.dinSize;
 dinMas = new double[dinSize];
 for (int j = 0; j < dinSize; j++)
  dinMas[j] = x.dinMas[j];
}

//Деструктор
TMyClass::~TMyClass()
{
 delete n;
 delete[] dinMas;
}

//Функция ввода
void TMyClass::input()
{
 cout << "Введите переменную типа char: " << endl;
 cin >> ch;
 cout << "Введите указатель типа long int: " << endl;
 cin >> *n;

 do 
 {
  cout << "Введите количество элементов динамического массива ( >0 ): ";
  cin >> dinSize;
 } while (dinSize <= 0);

 delete[] dinMas;
 dinMas = new double[dinSize];

 cout << "Введите эlементы динамического массива:" << endl;
 for (int i = 0; i < dinSize; i++)
 {
  cout << "Элемент: " << i + 1 << " : ";
  cin >> dinMas[i];
 }

 cout << "Введите элементы статического массива: " << endl;
 for (int j = 0; j < M; j++)
 {
  cout << "Введите " << j + 1 << " элемент: ";
  cin >> statMas[j];
 }
}

 //Дружественный класс
void friendInput(TMyClass& obj)
{
    cout << "Введите переменную типа char: " << endl;
 cin >> obj.ch;
 cout << "Введите указатель типа long int: " << endl;
 cin >> *obj.n;

 do 
 {
  cout << "Введите количество элементов динамического массива ( >0 ): ";
  cin >> obj.dinSize;
 } while (obj.dinSize <= 0);

 delete[] obj.dinMas;
 obj.dinMas = new double[obj.dinSize];

 cout << "Введите эlементы динамического массива:" << endl;
 for (int i = 0; i < obj.dinSize; i++)
 {
  cout << "Элемент: " << i + 1 << " : ";
  cin >> obj.dinMas[i];
 }

 cout << "Введите элементы статического массива: " << endl;
 for (int j = 0; j < M; j++)
 {
  cout << "Введите " << j + 1 << " элемент: ";
  cin >> obj.statMas[j];
 }
}

 //Функция вывода
void TMyClass::output()
{
 cout << "Переменная типа char: " << ch << endl;
 cout << "Указтель типа long int: " << *n << endl;

 cout << "Вывод статического массива: " << endl;
 for (int i = 0; i < M; i++)
  cout << statMas[i] << ' ';
 cout << endl;

 cout << "Вывод динамического массива:" << endl;
 for (int j = 0; j < dinSize; j++)
  cout << dinMas[j] << ' ';
 cout << endl;
}
 
 //Функция ффф
void TMyClass::fff(double d)
{
 for (int i = 0; i < dinSize; i++)
    dinMas[i] *= d;
}
//Реализация
int main()
{
 setlocale(LC_ALL, "RUS");

 cout << "ЛАБОРАТОРНАЯ РАБОТА 13." << endl;
 cout << "=================================" << endl;

  cout << endl << "Введите параметр для функции fff: ";
 double num;
 cin >> num;
 cout << endl;

TMyClass py;
 cout << "Объект py:" << endl;
 py.output(); cout << endl;
 py.fff(num);
 cout << ">>Элементы нового объекта py: : " << endl;
 py.output(); cout << endl;
 
 TMyClass a;
 a.input();
  cout << endl << "Вывод объекта a:" << endl;
 a.output(); cout << endl;
 a.fff(num);
 cout << ">>Элементы нового объекта а: " << endl;
 a.output(); cout << endl;

TMyClass b = a;
cout << "Вывод объекта б:" << endl; 
 b.output(); cout << endl;
 b.fff(num);
 cout << ">>Элементы нового объекта b: " << endl;
 b.output(); cout << endl;

 TMyClass* px = new TMyClass();
 friendInput(*px);
 cout << "Вывод объекта px:" << endl;
 px->output(); cout << endl;
 px->fff(num);
 cout << ">>Элементы нового объекта px: : " << endl;
 px->output(); cout << endl;
 
 //Массив объектов
 cout << "Создание массива объектов: " << endl;
 TMyClass mas1[3];
 for (int i = 0; i < 3; i++)
 {
  cout << endl << "Объект " << i + 1 << " :" << endl;
  mas1[i].output();
 }

//Удаление
 delete px;
 return 0;
}
