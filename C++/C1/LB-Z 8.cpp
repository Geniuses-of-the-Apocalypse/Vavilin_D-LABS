#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
 setlocale(LC_ALL, "RUS");

 cout << "ЛАБОРАТОРНАЯ РАБОТА 8: МАССИВЫ-2." << endl;
 cout << "===============================" << endl;

 int i, j;
 int m = 0, n = 0;

 do
 {
  cout << "Введите количество строк и столбцов:" << endl;
  cin >> n >> m;
 } while (m < 4 || n < 4 || m == n);
 cout << "===============================" << endl;

 int** arr = new int*[n]; //Создание двумерного массива
 for (i = 0; i < n; i++)
  arr[i] = new int[m];

 //Выделение памяти для остальных массивов
 int** arr90Right = new int* [m];
 for (i = 0; i < m; ++i)
  arr90Right[i] = new int[n];

 int** arr90Left = new int* [m];
 for (i = 0; i < m; ++i)
  arr90Left[i] = new int[n];

 int** arr180 = new int* [n];
 for (i = 0; i < n; ++i)
  arr180[i] = new int[m];

 for (i = 0; i < n; i++) //Ввод массива
 {
  cout << "Строка " << i + 1 << " :" << endl;
  for (j = 0; j < m; j++)
  {
   cout << "Введите число: ";
   cin >> arr[i][j];
  }
  cout << endl;
 }
 cout << "===============================" << endl;

 cout << "Вывод исходного массива:" << endl;
 for (i = 0; i < n; i++) //Вывод двумерного массива
 {
  for (j = 0; j < m; j++)
   cout << setw(10) << arr[i][j];
  cout << endl;
 }

 for (i = 0; i < n; ++i) //Поворот на 90 по часовой
  for (j = 0; j < m; ++j)
   arr90Right[j][n - 1 - i] = arr[i][j];

 cout << "Вывод массива повёрнутого на 90 градусов по часовой:" << endl;
 for (i = 0; i < m; ++i)
 {
  for (j = 0; j < n; ++j)
   cout << setw(10) << arr90Right[i][j];
  cout << endl;
 }



 for (i = 0; i < n; ++i) //Поворот на 90 против часовой
  for (j = 0; j < m; ++j)
   arr90Left[m - 1 - j][i] = arr[i][j];

 cout << "Вывод массива повёрнутого на 90 градусов против часовой:" << endl;
 for (i = 0; i < m; ++i)
 {
  for (j = 0; j < n; ++j)
   cout << setw(10) << arr90Left[i][j];
  cout << endl;
 }


 for (i = 0; i < n; ++i) //Поворот массива на 180
  for (j = 0; j < m; ++j)
   arr180[n - 1 - i][m - 1 - j] = arr[i][j];

 cout << "Вывод массива повёрнутого на 180 градусов:" << endl;
 for (i = 0; i < n; ++i)
 {
  for (j = 0; j < m; ++j)
   cout << setw(10) << arr180[i][j];
  cout << endl;
 }

 //Освобождение памяти
 for (i = 0; i < n; ++i)
 {
  delete[] arr[i];
  delete[] arr180[i];
 }
 for (i = 0; i < m; ++i)
 {
  delete[] arr90Right[i];
  delete[] arr90Left[i];
 }
 delete[] arr;
 delete[] arr90Right;
 delete[] arr90Left;
 delete[] arr180;

 return 0;
}
