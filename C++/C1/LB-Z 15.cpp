#include <iostream>
#include <string>
using namespace std;

const int N = 4;

//Класс
class TUvelir
{
private:
 string vid;
 string creator;
 string vstavkaType;
 double vstavkaMas;
 double opravaMas;
 double metalSostav[N];

public:
 //Конструктор по умолчанию
 TUvelir(string v = "Кольцо", string cr = "Неизвестно", string vT = "-", double vM = 0, double oM = 1, double gold = 57.8, double silver = 35, double copper = 15, double nickel = 1.3);
 TUvelir(const TUvelir& t);

 void vvod();
 void vivod();

 //Перегрузки операторов
 TUvelir& operator=(const TUvelir& t);
 bool operator==(const TUvelir& t) const;
 double& operator [](int index);
 TUvelir& operator--();
};

//Реализация конструктора с параметрами
TUvelir::TUvelir(string v, string cr, string vT, double vM, double oM, double gold, double silver, double copper, double nickel)
{
 vid = v;
 creator = cr;
 vstavkaType = vT;
 vstavkaMas = vM;
 opravaMas = oM;
 metalSostav[0] = gold;
 metalSostav[1] = silver;
 metalSostav[2] = copper;
 metalSostav[3] = nickel;
}

//Конструктор копирования
TUvelir::TUvelir(const TUvelir& t)
{
 vid = t.vid;
 creator = t.creator;
 vstavkaType = t.vstavkaType;
 vstavkaMas = t.vstavkaMas;
 opravaMas = t.opravaMas;
 for (int i = 0; i < N; i++)
  metalSostav[i] = t.metalSostav[i];
}

//Метод ввода
void TUvelir::vvod()
{
 cout << "Введите вид изделия: ";
 getline(cin, vid);
 cout << "Введите изготовителя: ";
 getline(cin, creator);
 cout << "Введите тип вставки (- если нет): ";
 getline(cin, vstavkaType);
 cout << "Введите массу вставки: ";
 cin >> vstavkaMas;
 cout << "Введите массу оправы: ";
 cin >> opravaMas;
 cout << ">Введите состав изделия: " << endl;
 cout << "Золото: ";
 cin >> metalSostav[0];
 cout << "Серебро: ";
 cin >> metalSostav[1];
 cout << "Медь: ";
 cin >> metalSostav[2];
 cout << "Никель: ";
 cin >> metalSostav[3];

 cin.ignore();
 cout << endl;
}

//Метод вывода
void TUvelir::vivod()
{
 cout << ">Информация о Ювелирном изделии:" << endl;
 cout << "Вид: " << vid << endl;
 cout << "Изготовитель: " << creator << endl;
 cout << "Тип вставки: " << vstavkaType << endl;
 cout << "Масса вставки: " << vstavkaMas << endl;
 cout << "Масса оправы: " << opravaMas << endl;
 cout << ">Состав изделия(%):" << endl;
 cout << "Золото: " << metalSostav[0] << endl;
 cout << "Серебро: " << metalSostav[1] << endl;
 cout << "Медь: " << metalSostav[2] << endl;
 cout << "Никель: " << metalSostav[3] << endl;
}

//Перегрузка оператора присваивания
TUvelir& TUvelir::operator = (const TUvelir& t)
{
 if (this != &t)
 {
     vid = t.vid;
     creator = t.creator;
     vstavkaType = t.vstavkaType;
     vstavkaMas = t.vstavkaMas;
     opravaMas = t.opravaMas;
     for (int i = 0; i < N; i++)
      metalSostav[i] = t.metalSostav[i];
 }
 return *this;
}

//Перегрузка оператора равно
bool TUvelir::operator==(const TUvelir& t) const
{
 bool flag = true;
 if ((vid != t.vid) || (creator != t.creator) || (vstavkaType != t.vstavkaType) || (vstavkaMas != t.vstavkaMas) || (opravaMas != t.opravaMas))
  flag = false;
 else
 {
  for (int i = 0; i < N; i++)
   if (metalSostav[i] != t.metalSostav[i])
   {
    flag = false;
    break;
   }
 }
 return flag;
}

//Перегрузка оператора индексирования
double& TUvelir::operator[](int index)
{
 if (index < 0 || index >= N)
 {
  cout << "Неверный индекс! Допустимые значения: 0-" << N - 1 << endl;
  exit(-1);
 }
 return metalSostav[index];
}

//Перегрузка оператора минус
TUvelir& TUvelir::operator--()
{
 vstavkaType = "-";
 vstavkaMas = 0;
 return *this;
}
int main()
{
 setlocale(LC_ALL, "RUS");

 cout << "ЛАБОРАТОРНАЯ РАБОТА 15-1: Перегрузка операций." << endl;
 cout << "==============================================" << endl;

 //Объекты класса
 TUvelir a("Кольцо", "Фёдор", "Бриллиант", 0.4, 3.4, 56.3, 36, 11, 1.4);
 TUvelir b("Кулон", "Алексей", "-", 0, 0.3, 5.6, 45, 4.3, 4.5);
 cout << endl;

 //Вывод объектов а и б
 cout << ">>Объект а: " << endl;
 a.vivod(); cout << endl;
 cout << ">>Объект b: " << endl;
 b.vivod(); cout << endl;

 //Приравниевание б = а
 cout << ">>Объект b = a:" << endl;
 b = a;
 b.vivod(); cout << endl;
 
 //Приравнивание а = а
 cout << ">>Объект а = а: " << endl;
 a = a;
 a.vivod(); cout << endl;

 //Проверка перегрузки ==
 cout << ">>Проверка оператора == : " << endl;
 cout << "a == b:" << (a == b ? " Да" : " Нет") << endl;
 b[0] = 75.3;
  b.vivod(); cout << endl;
 cout << "Вывод с изменёным параметром Золото в b: " << (a == b ? "Да" : "Нет") << endl << endl;

 //Ввод объекта с
 TUvelir c;
 cout << ">>Введите данные объекта c:" << endl;
 c.vvod();
 cout << ">>Объект c: " << endl;
 c.vivod();
 cout << ">Сравнение объектов а и с:" << endl;
 cout << "a == c: " << (a == c ? " Да" : " Нет") << endl << endl;

 //Проверка перегрузки -
 cout << ">>Перегрузка - для объекта c:" << endl;
 --c;
 c.vivod(); cout << endl;

 //Проверка перегрузки []
 cout << ">>Чтение состава через оператор [] для объекта c:" << endl;
 cout << "Золото: " << c[0] << endl;
 cout << "Серебро: " << c[1] << endl;
 cout << "Медь: " << c[2] << endl;
 cout << "Никель: " << c[3] << endl << endl;

 cout << ">>Вывод с(объект) с изменённым составом:" << endl;
 c[1] = 28.5;
 c[2] = 37.5;
 c.vivod(); cout << endl;

 cout << ">>Попытка доступа к несуществующему индексу:" << endl;
 double x = c[5];

 return 0;
}
