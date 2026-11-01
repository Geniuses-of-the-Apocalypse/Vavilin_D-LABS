#include <iostream>
//#include "windows.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int M = 4;
const string F_ERR = "\n Ошибка содержания файла.";

//Класс TUVELIR
class TUvelir
{
private:
 friend class TFile;
 string name;
 string creator;
 string vstavType;
 float vstavMas;
 float opravMas;
 float metalSostav[M];

public:
 TUvelir(string n = "-", string c = "-", string vT = "-", float vM = 0, float oM = 0, float mS = 0);
 TUvelir(const TUvelir& t);

 TUvelir& operator = (const TUvelir& t);
 bool operator == (const TUvelir& t) const;

 friend istream& operator >> (istream& i, TUvelir& u);
 friend ostream& operator << (ostream& o, TUvelir& u);

 void shapka();
 void input();
 void output();
};

TUvelir::TUvelir(string n, string c, string vT, float vM, float oM, float mS)
{
 name = n;
 creator = c;
 vstavType = vT;
 vstavMas = vM;
 opravMas = oM;
 for (int i = 0; i < M; i++)
  metalSostav[i] = mS;
}

TUvelir::TUvelir(const TUvelir& t)
{
 name = t.name;
 creator = t.creator;
 vstavType = t.vstavType;
 vstavMas = t.vstavMas;
 opravMas = t.opravMas;
 for (int i = 0; i < M; i++)
  metalSostav[i] = t.metalSostav[i];
}

TUvelir& TUvelir::operator = (const TUvelir& t)
{
 if (this != &t)
 {
  name = t.name;
  creator = t.creator;
  vstavType = t.vstavType;
  vstavMas = t.vstavMas;
  opravMas = t.opravMas;
  for (int i = 0; i < M; i++)
   metalSostav[i] = t.metalSostav[i];
 }
 return *this;
}

bool TUvelir::operator == (const TUvelir& t) const
{
 if ((name != t.name) || (creator != t.creator) || (vstavType != t.vstavType) || (vstavMas != t.vstavMas) || (opravMas != t.opravMas))
  return false;
 for (int i = 0; i < M; i++)
  if (metalSostav[i] != t.metalSostav[i])
   return false;
 return true;
}

istream& operator >> (istream& i, TUvelir& u)
{
 i >> u.name >> u.creator >> u.vstavType >> u.vstavMas >> u.opravMas;
 for (int j = 0; j < M; j++)
  i >> u.metalSostav[j];
 return i;
}

ostream& operator << (ostream& o, TUvelir& u)
{
 o << u.name << " " << u.creator << " " << u.vstavType << " " << u.vstavMas << " " << u.opravMas << " ";
 for (int i = 0; i < M; i++)
  o << u.metalSostav[i] << " ";
 o << endl;
 return o;
}

void TUvelir::shapka()
{
 cout << setw(15) << "Nazvanie" << setw(15) << "Izgotovitel" << setw(15) << "Tip vstavka"
  << setw(15) << "Massa vstavki" << setw(15) << "Massa opravi" << setw(10) << "Zoloto" << 
   setw(10) << "Serebro" << setw(10) << "Med" << setw(10) << "Nickel" << endl;
 cout << "===================================================================================================================" << endl;
}

void TUvelir::input()
{
 cout << ">Введите назавние изделия: ";
 cin >> name;
 if(name.length()>10)
 {
  name =name.substr(0,10);
  cout<<"после обрубки имя = " << name << endl;
 }

 cout << ">Введите изготовителя: ";
 cin >> creator;
 if(creator.length()>10)
 {
  creator =creator.substr(0,10);
  cout<<"после обрубки создатель = " << creator << endl;
 }

 cout << ">Введите тип вставки: ";
 cin >> vstavType;
 if(vstavType.length()>10)
 {
  vstavType =vstavType.substr(0,10);
  cout<<"после обрубки вставка = " << vstavType << endl;
 }
 if (vstavType != "-")
 {
  do{
    cout << ">Введите массу вставки: ";
    cin >> vstavMas;
  } while(vstavMas < 0);
 }

do{
 cout << ">Введите массу оправы: ";
 cin >> opravMas;
} while (opravMas < 0);

do {
 cout << ">Введите содержание метталов (золото, серебро, медь, никель): " << endl;
 cout << "Золото: "; cin >> metalSostav[0];
 cout << "Серебро: "; cin >> metalSostav[1];
 cout << "Медь: "; cin >> metalSostav[2];
 cout << "Никель: "; cin >> metalSostav[3];
} while ((metalSostav[0] + metalSostav[1] + metalSostav[2] + metalSostav[3]) != 100);
}

void TUvelir::output()
{
 cout << setw(15) << name << setw(15) << creator << setw(15)
  << vstavType << setw(15) << vstavMas << setw(15) <<
  opravMas;
 for (int i = 0; i < M; i++)
  cout << setw(10) << metalSostav[i];
 cout << endl;
}
//===============================================
//Класс TFILE
class TFile
{
private:
 string fn;
 TUvelir u;
public:
 TFile(string ff = "Uvelirs.aaa");
 void fSozd();
 void fOutput();
 void fAddRec();
 void fFinder(string n);
};

TFile::TFile(string ff)
{
 fn = ff;
}

void TFile::fSozd()
{
 ofstream fd(fn);
 if (!fd)
 {
  cout << F_ERR << endl;
  return;
 }

 char choice;
 do
 {
  TUvelir tovar;
  tovar.input();
  fd << tovar;
  cout << "Продолжить? (y/n): ";
  cin >> choice;
 } while (choice == 'y' || choice == 'Y');
 fd.close();
}

void TFile::fOutput()
{
 int timer = 0;
 ifstream fd(fn);
 if (!fd)
 {
  cout << F_ERR << endl;
  return;
 }

 TUvelir tovar;
 tovar.shapka();
 while (fd >> tovar)
 {
  tovar.output();
  //timer++;
  //if (timer == 10)
  //{
  // Sleep(3000);
  //}
 }
 fd.close();
}

void TFile::fAddRec()
{
 fstream fd(fn, ios::in | ios::out);
 if (!fd)
 {
  cout << F_ERR << endl;
  return;
 }
 fd.seekp(0, ios::end);
 TUvelir tovar;
 tovar.input();
 fd << tovar;
 fd.close();
}

void TFile::fFinder(string n)
{
 cout << ">>Поиск по названию." << endl << endl;
 ifstream fd(fn);
 if (!fd)
 {
  cout << F_ERR << endl;
  return;
 }

 TUvelir tovar;
 bool flag = false;
 while (fd >> tovar)
 {
  if (flag == true && tovar.name == n)
  {
   tovar.output();
   continue;
  }

  if (tovar.name == n)
  {
   tovar.shapka();
   tovar.output();
   flag = true;
  }
 }
 if (!flag)
  cout << endl << "Изделие с таким именем не найдено." << endl;
 fd.close();
}

void showMenu()
{
 cout << endl << "=== МЕНЮ ===" << endl;
 cout << "1. Создать новый фаил с изделиями." << endl;
 cout << "2. Посмотреть весь каталог." << endl;
 cout << "3. Добавить изделие." << endl;
 cout << "4. Поиск по названию изделия." << endl;
 cout << "5. Выход." << endl;
 cout << "=================================" << endl;
 cout << "Выберите опцию: ";
}

int main()
{
 setlocale(LC_ALL, "RUS");
 cout << "ЛАБОРАТОРНАЯ РАБОТА 19: ФАЙЛЫ." << endl;
 cout << "===============================" << endl;

 TFile file;
 int num;
 string izdel;

 do
 {
  showMenu();
  cin >> num;
  cout << "=================================" << endl << endl;
  cin.ignore();
  switch (num)
  {
  case 1:
   file.fSozd();
   break;
  case 2:
   file.fOutput();
   break;
  case 3:
   file.fAddRec();
   break;
  case 4:
   cout << "Введите название изделия: ";
   cin >> izdel;
   file.fFinder(izdel);
   break;
  case 5:
   cout << "Выход из программы." << endl;
   break;
  default:
   cout << "Неверно выбрана опция. Повторите попытку." << endl;
   continue;
  }
 } while (num != 5);
 return 0;
}
