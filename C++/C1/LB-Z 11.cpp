#include <iostream>
#include <string>
using namespace std;

void StringInfo(string str)
{
 int cnt = 0;
 for (char c : str)
 {
  cout << c << endl;
  if (c == '#')
   cnt++;
 }
 cout << "Количество символов '#': " << cnt << endl;
 cout << "Общее количество символов в строке: " << str.length() << endl;
}

void StringSravn(string str)
{
 cout << "Совпадения: ";
 if (str == "11#22#33#44#55")
  cout << "Строка совпадает со строкой '11#22#33#44#55'." << endl;
 else
  cout << "Совпадений нет." << endl;
}

string PlusString(string str)
{
 string newStr;
 for (char c : str)
 {
  newStr += c;
  newStr += '+';
 }
 return newStr;
}

int main()
{
 setlocale(LC_ALL, "RUS");

 cout << "ЛАБОРАТОРНАЯ РАБОТА 11.2: STRING." << endl;
 cout << "==================================" << endl;
 cout << "2)РАБОТА СО STRING:" << endl;

 string str; 
 string X;

 cout << "Введите строку, разделённую символами # :" << endl;
 getline(cin, str);

 cout << "==================================" << endl;

 cout << "СТРОКА STR:" << endl;
 StringInfo(str);
 StringSravn(str);

 str = "YES";
 X = "March, 2012" + str;

 cout << endl << "СТРОКА X:" << endl;
 StringInfo(X);
 
 cout << endl << "НОВАЯ СТРОКА STR:" << endl;
 str = PlusString(str);
 StringInfo(str);
}
