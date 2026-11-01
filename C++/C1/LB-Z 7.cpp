#include <iostream>
using namespace std;

int main()
{
 setlocale(LC_ALL, "RUS");

 cout << "Лабораторная работа 7: МАССИВЫ-1." << endl;
 cout << "ЧАСТЬ 2." << endl;
 cout << "===============================" << endl;

 const int I = 5, J = 7; //I Строки, J Столбцы
 int mas[I][J];
 int cnt = 0, stolb = 0;
 float arifm = 0, s = 0, max = 0, max_i = 0, max_j = 0;

 cout << "Введите числа в массив:" << endl; //Ввод двумерного массива
 for (int a = 0; a < I; a++)
 {
  cout << "Введите " << a + 1 << " строку." << endl;
  for (int b = 0; b < J; b++)
  {
   cout << "Введите целое число: ";
   cin >> mas[a][b];
  }
 }
 cout << endl;

 while (stolb <= 0 || stolb > 7)
 {
  cout << "Введите номер столбца для пункта 3(от 1 до 7): " << endl;
  cin >> stolb;
 }

 cout << "===============================" << endl;
 cout << "1) Вывод массива:" << endl;
 for (int i = 0; i < I; i++) // Вывод двумерного масства
 {
  for (int j = 0; j < J; j++)
   cout << mas[i][j] << "\t";
  cout << endl;
 }
 cout << endl;

 for (int i = 0; i < I; i++) //Нахождение количества нужных элементов
  for (int j = 0; j < J; j++)
  {
   if (mas[i][j] % 7 == 0 && mas[i][j] < 60 && mas[i][j] != 0)
    cnt++;
  }

 cout << "2) Количество элементов кратных семи: " << cnt << endl;
 cout << endl;

 for (int strok = 0; strok < I; strok++) //Среднее арифметическое
  s += mas[strok][stolb - 1];
 arifm = s / 5;

 cout << "3) Среднее арифметическое столбца " << stolb << ": " << arifm << endl;
 cout << endl;

 cout << "4) Вывод максимов строк массива:" << endl;
 for (int i = 0; i < I; i++)
 {
  max = 0;
  max_i = 0;
  max_j = 0;
  for (int j = 0; j < J; j++)
  {
   if (max < mas[i][j])
   {
    max = mas[i][j];
    max_i = i + 1;
    max_j = j + 1;
   }
  }
  cout << "Максимальное значение строки " << i+1 << ": " << max << "; Его координаты : " << max_i << " строчка и " << max_j << " столбец." << endl;
 }
 return 0;
}
