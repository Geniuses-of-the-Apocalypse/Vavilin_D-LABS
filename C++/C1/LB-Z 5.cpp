#include <iostream> 
using namespace std; 
 
int main() 
{ 
 setlocale(LC_ALL, "RUS"); 
 cout << "ЛАБОРАТОРНАЯ РАБОТА 5" << endl; 
 cout << "======================" << endl; 
 
 int cnt = 0, n; 
 
 cout << "Введите количество трёхзначных чисел(int): " << endl; 
 cin >> n; 
 cout << "======================" << endl; 
 
 for (int k = 0; k < n; k++) 
 { 
  bool flag = false; 
  int num; 
 
  cout << "Введите трёхзначное число(int):" << endl; 
  cin >> num; 
 
  while (num < 100 || num > 999) 
  { 
   cout << "Введите корректное число (трёхзначное):" << endl; 
   cin >> num; 
  } 
 
  for (int i = 2; i < num; i++)  
  { 
   if (num % i != 0) 
    flag = true; 
   else { 
    flag = false; 
    break; 
   } 
  } 
  while (flag == true) 
  { 
   cnt++; 
   break; 
  } 
 } 
 cout << "======================" << endl; 
 cout << "Количество простых чисел: " << cnt << endl; 
 cout << "Выход из программы." << endl; 
}
