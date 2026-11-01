#include <iostream>
#include <iomanip>
using namespace std;

const int X = 9; //Кол-во элементов массива

void input(int mas[], int num)
{
    cout << "> Введите массив " << num << ":" << endl;
    for (int i = 0; i < X; i++)
    {
        cout << "Введите " << i + 1 << " число в массив: ";
        cin >> mas[i];
    }
    cout << endl;
}

void output(int mas[], int num)
{
    cout << "> Вывод массива " << num << ":" << endl;
    for (int i = 0; i < X; i++)
    {
        cout << setw(5) << mas[i];
    }
    cout << endl;
}

void SuperBubbleSort(int mas[])
{
    //Сортировка пузырьком
    for (int i = 0; i < X - 1; i++)
    {
        for (int j = 0; j < X - i - 1; j++)
        {
            if (mas[j] > mas[j + 1])
            {
                int t = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = t;
            }
        }
    }

    int res[X]; //Массив для сортировки
    int left = 0; //Указатель начала
    int right = X - 1;  //Указатель конца
    int index = 0; //Индекс результата 

    //Перебираем все элементы
    while (left <= right)
    {
        res[index++] = mas[left++];
        if (left <= right)
            res[index++] = mas[right--];
    }

    //Копируем результат обратно в массив
    for (int i = 0; i < X; i++)
        mas[i] = res[i];
}


int main() {
    setlocale(LC_ALL, "RUS");

    cout << "ЛАБОРАТОРНАЯ РАБОТА 10: ФУНКЦИИ + МАССИВЫ." << endl;
    cout << "===========================================" << endl;

    int mas1[X];
    int mas2[X];
    int mas3[X];

    input(mas1, 1);
    input(mas2, 2);
    input(mas3, 3);

    output(mas1, 1);
    output(mas2, 2);
    output(mas3, 3);

    cout << "===============================" << endl;

    SuperBubbleSort(mas1);
    SuperBubbleSort(mas2);
    SuperBubbleSort(mas3);

    output(mas1, 1);
    output(mas2, 2);
    output(mas3, 3);

    return 0;
}
