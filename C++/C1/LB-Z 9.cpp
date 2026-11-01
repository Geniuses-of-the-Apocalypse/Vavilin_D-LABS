#include <iostream>
using namespace std;

float Input(float d1, float d2)
{
 float num;

 do
 {
  cout << "Введите вещественное число в диапозоне от " << d1 << " до " << d2 << " : " << endl;
  cin >> num;
 } while (d1 > num || num > d2);

 return num;
}

float FindMin(float a, float b, float c)
{
 float min = a;

 if (min > b)
  min = b;
 if (min > c)
  min = c;

 return min;
}

float NewNums(float num)
{
 float NewNum;
 NewNum = int(num) % 10;
 return NewNum;
}

//float TheFmod(float num, int den)
//{
// int int_part = static_cast<int>(num); 
// float fract_part = num - int_part; 
// float result = fract_part * den;
//
// return result;
//}

void Output(float a, float b, float c, float min)
{
 cout << "Полученные значения: " << a << " " << b << " " << c << endl;
 cout << "Минимальное значение: " << min << endl;
 cout << endl;
}

int main()
{
 setlocale(LC_ALL, "RUS");

 cout << "ЛАБОРАТОРНАЯ РАБОТА 9: ФУНКЦИИ." << endl;
 cout << "==================================" << endl;

 float d1 = 0, d2 = 0;
 while (d1 == d2 || d1 > d2 || d2 - d1 < 1)
 {
  cout << "Введите диапозон вещественных чисел:" << endl;
  cin >> d1 >> d2;
 }

 cout << "==================================" << endl;

 float a = Input(d1, d2);
 float b = Input(d1, d2);
 float c = Input(d1, d2);

 cout << "==================================" << endl;
 cout << "1)" << endl;

 Output(a, b, c, FindMin(a, b, c));

 cout << "==================================" << endl;
 cout << "2)" << endl;

 a = NewNums(a);
 b = NewNums(b);
 c = NewNums(c);

 Output(a, b, c, FindMin(a, b, c));
}
