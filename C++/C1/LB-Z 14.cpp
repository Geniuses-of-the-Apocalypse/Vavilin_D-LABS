#include <iostream>
#include <string>
using namespace std;

//Класс TOne.
class TOne
{
public:
 double a1, a2;
 double *p1, *p2;
 TOne(double aa1 = 25.5, double pp1 = 37.9);
 ~TOne();
};

//Конструктор класса TOne
TOne::TOne(double aa1, double pp1)
{
 a1 = aa1;
 p1 = new double;
 *p1 = pp1;
 p2 = new double;
}

//Деструктор класса TOne
TOne::~TOne()
{
 delete p1;
 delete p2;
}

//=============================================

//Класс TTwo
class TTwo
{
public:
 TOne* pone;
 TTwo(double aa2 = 3.14);
 ~TTwo();
};

//Конструктор класса TTwo
TTwo::TTwo(double aa2)
{
 pone = new TOne;
 pone->a2 = aa2;
}

//Деструктор класса TTwo
TTwo::~TTwo()
{
 delete pone;
}

int main()
{
 setlocale(LC_ALL, "RUS");

 cout << "ЛАБОРАТОРНАЯ РАБОТА 14: АГРЕГИРОВАНИЕ." << endl;
 cout << "===============================================" << endl;

 TTwo* t = new TTwo(15.38);
 t->pone->p2 = new double(25.71);
 double* p3 = &t->pone->a2;

 cout << "Вывод значений и адресов:" << endl;
 cout << "Значение a1: " << t->pone->a1 << "; Адрес a1: " << &t->pone->a1 << "." << endl;
 cout << "Значение a2: " << t->pone->a2 << "; Адрес a2: " << &t->pone->a2 << "." << endl;
 cout << "Значение *p1: " << *t->pone->p1 << "; Адрес p1: " << t->pone->p1 << "." << endl;
 cout << "Значение *p2: " << *t->pone->p2 << "; Адрес p2: " << t->pone->p2 << "." << endl;
 cout << "Значение p3: " << p3 << "." << endl;

 delete t;
 return 0;
}
