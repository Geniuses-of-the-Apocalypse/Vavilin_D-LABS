#include <iostream>
#include <string>
using namespace std;

const int M = 6;
const int N = 1;

string MonthName(int n)
{
 switch (n)
 {
 case 0:
  return "Январь";
  break;
 case 1:
  return "Февраль";
  break;
 case 2:
  return "Март";
  break;
 case 3:
  return "Апрель";
  break;
 case 4:
  return "Май";
  break;
 case 5:
  return "Июнь";
  break;
 }
}

class DEStation
{
 string shifr;
 string name;
 string type;
 int month[M][N];
public:
 void Input();
 void Output();
 double Producton();
};

void DEStation::Input()
{
 cout << "Введите шифр: ";
 cin >> shifr;
 cout << "Введите название: ";
 cin.ignore();
 getline(cin, name);
 cout << "Введите тип: ";
 cin >> type;
 cout << "Введите выработку за полугодие." << endl;
 for (int i = 0; i < M; i++)
 {
  string text = MonthName(i);
  cout << text << " :";
  for (int j = 0; j < N; j++)
   cin >> month[i][j];
 }
}

void DEStation::Output()
{
 cout << "Шифр: " << shifr << endl;
 cout << "Название: " << name << endl;
 cout << "Тип: " << type << endl;
 cout << "Выработка за полугодие:" << endl;
 for (int i = 0; i < M; i++)
 {
  string text = MonthName(i);
  cout << text << " :";
  for (int j = 0; j < N; j++)
   cout << month[i][j] << " ";
  cout << endl;
 }
}

double DEStation::Producton()
{
 double sum = 0;
 for (int i = 0; i < M; i++)
  for (int j = 0; j < N; j++)
   sum += month[i][j];
 sum /= M;
 return sum;
}

int main()
{
 setlocale(LC_ALL, "RUS");

 cout << "ЛАБОРАТОРНАЯ РАБОТА 12: КЛАССЫ." << endl;
 cout << "================================" << endl;

 //Обычный объект
 DEStation a;
 a.Input();
 cout << "============" << endl;
 cout << ">>ИНФОРМАЦИЯ:" << endl;
 a.Output();
 double srz1 = a.Producton();
 cout << "Средняя выработка энергии за полугодие: " << srz1 << endl << endl;

 //Указатель
 DEStation* b = new DEStation;
 b->Input();
 cout << "============" << endl;
 cout << ">>ИНФОРМАЦИЯ:" << endl;
 b->Output();
 double srz2 = b->Producton();
 cout << "Средняя выработка энергии за полугодие: " << srz2 << endl << endl;

 //Массив
 DEStation* mas = new DEStation[3];
 for (int i = 0; i < 3; i++)
 {
  cout << ">ВВЕДИТЕ ДАННЫЕ " << i + 1 << ":" << endl;
  mas[i].Input();
 }
 cout << "============" << endl;
 cout << ">>ИНФОРМАЦИЯ:" << endl;
 for (int j = 0; j < 3; j++)
 {
  cout << "ДАННЫЕ " << j + 1 << ":" << endl;
  mas[j].Output();
  double srz3 = mas[j].Producton();
  cout << "Средняя выработка энергии за полугодие: " << srz3 << endl << endl;
 }

 //Освобождение памяти
 delete b;
 delete[] mas;
 return 0;
}
