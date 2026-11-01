#include <iostream> 
using namespace std; 
 
int main() 
{ 
 setlocale(LC_ALL, "RUS"); 
 
 cout << "ЛР-04." << endl; 
 cout << "Для выхода из программы введите 0." << endl; 
 
 while (1) { 
  cout << "==================" << endl; 
 
  int a, num; 
  bool flag = true; 
 
  cout << "Введите натуральное число не больше 999999999(int):" << endl; 
  cin >> a; 
 
  num = a; 
  
 
  if (a == 0) 
  { 
   cout << "Выход из программы." << endl; 
   break; 
  } 
 
  if (a >= 1 && a <= 999999999) 
  { 
   while (num > 0) 
   { 
    int cif = num % 10; 
    num /= 10; 
    int lastnum = num; 
    while (lastnum > 0) 
    { 
     if (lastnum % 10 == cif) 
      flag = false; 
     lastnum /= 10; 
    } 
 
   } 
 
   if (flag) 
    cout << "В числе нет повторений." << endl; 
   else 
    cout << "В числе есть повторения." << endl; 
  } 
  else 
   cout << "Вы ввели не верное число." << endl; 
 
 } 
 return 0; 
}
