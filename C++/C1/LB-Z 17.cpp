#include <iostream>
#include <string>
using namespace std;

const int M = 5;

//Класс
class TMyClass
{
private:
    char ch;
    long int* n;
    float statMas[M];
    double* dinMas;
    int dinSize;

public:
    TMyClass(char kch = 'R', long int kn = 12, float ksMas = 2.3, double kdMas = 25.2, int kdS = 5);
    TMyClass(const TMyClass& t);
    ~TMyClass();

    void input();
    void output();
    void fff(double d);

    friend void friendInput(TMyClass& obj);
};

//Конструктор по умолчанию
TMyClass::TMyClass(char kch, long int kn, float ksMas, double kdMas, int kdS)
{
    ch = kch;
    n = new long int;
    *n = kn;
    dinSize = kdS;

    for (int i = 0; i < M; i++)
        statMas[i] = ksMas;

    dinMas = new double[dinSize];
    for (int i = 0; i < dinSize; i++)
        dinMas[i] = kdMas;//22 * i;
}

//Конструктор копирования
TMyClass::TMyClass(const TMyClass& t)
{
    ch = t.ch;
    n = new long int;
    *n = *t.n;

    for (int i = 0; i < M; i++)
        statMas[i] = t.statMas[i];

    dinSize = t.dinSize;
    dinMas = new double[dinSize];
    for (int j = 0; j < dinSize; j++)
        dinMas[j] = t.dinMas[j];
}

//Деструктор
TMyClass::~TMyClass()
{
    delete n;
    delete[] dinMas;
}

//Функция ввода
void TMyClass::input()
{
    cout << ">Введите переменную типа char: " << endl;
    cin >> ch;
    cout << ">Введите указатель типа long int: " << endl;
    cin >> *n;

    do
    {
        cout << ">Введите количество элементов динамического массива ( >0 ): ";
        cin >> dinSize;
    } while (dinSize <= 0);

    delete[] dinMas;
    dinMas = new double[dinSize];

    cout << ">Введите элементы динамического массива:" << endl;
    for (int i = 0; i < dinSize; i++)
    {
        cout << "Элемент " << i + 1 << ": ";
        cin >> dinMas[i];
    }

    cout << ">Введите элементы статического массива: " << endl;
    for (int j = 0; j < M; j++)
    {
        cout << "Элемент " << j + 1 << ": ";
        cin >> statMas[j];
    }
}

//Дружественный класс
void friendInput(TMyClass& obj)
{
    cout << ">Введите переменную типа char: ";
    cin >> obj.ch;
    cout << ">Введите указатель типа long int: ";
    cin >> *obj.n;

    do
    {
        cout << ">Введите количество элементов динамического массива ( >0 ): ";
        cin >> obj.dinSize;
    } while (obj.dinSize <= 0);

    delete[] obj.dinMas;
    obj.dinMas = new double[obj.dinSize];

    cout << ">Введите эlементы динамического массива:" << endl;
    for (int i = 0; i < obj.dinSize; i++)
    {
        cout << "Элемент: " << i + 1 << " : ";
        cin >> obj.dinMas[i];
    }

    cout << ">Введите элементы статического массива: " << endl;
    for (int j = 0; j < M; j++)
    {
        cout << "Введите " << j + 1 << " элемент: ";
        cin >> obj.statMas[j];
    }
    cout << endl;
}

//Функция вывода
void TMyClass::output()
{
    cout << ">Переменная типа char: " << ch << endl;
    cout << ">Указтель типа long int: " << *n << endl;

    cout << ">Вывод статического массива: " << endl;
    for (int i = 0; i < M; i++)
        cout << "Элемент " << i + 1 << ": " << statMas[i] << '\n';

    cout << ">Вывод динамического массива:" << endl;
    for (int j = 0; j < dinSize; j++)
        cout << "Элемент " << j + 1 << ": " << dinMas[j] << '\n';
}

//Функция ффф
void TMyClass::fff(double d)
{
    for (int i = 0; i < dinSize; i++)
        dinMas[i] *= d;
}
//=====================================================================================================

//Дочерний класс TCHILD
class TChild : public TMyClass
{
private:
    int num;
    float* fl;
public:
    TChild(int knum = 89, float kfl = 4.2, char kch = 'R', long int kn = 12, float ksMas = 2.3, double kdMas = 25.2, int kdS = 5);
    TChild(const TChild& t2);
    ~TChild();

    void output();
};

//Конструктор по умолчанию для дочернего класса
TChild::TChild(int knum, float kfl, char kch, long int kn, float ksMas, double kdMas, int kdS) : TMyClass(kch, kn, ksMas, kdMas, kdS)
{
    num = knum;
    fl = new float;
    *fl = kfl;
}

//Конструктор копирования для дочернего класса
TChild::TChild(const TChild& t2) : TMyClass(t2)
{
    num = t2.num;
    fl = new float;
    *fl = *t2.fl;
}

//Деструктор для дочернего класса
TChild::~TChild()
{
    delete fl;
}

void TChild::output()
{
    TMyClass::output();
    cout << ">Переменная типа int: " << num << endl;
    cout << ">Указатель типа float: " << *fl << endl;
    cout << endl;
}

//==============================================================================

//Реализация
int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "ЛАБОРАТОРНАЯ РАБОТА 17: НАСЛЕДОВАНИЕ-1." << endl;
    cout << "========================================" << endl << endl;

    TMyClass a;
    cout << ">>Объект а:" << endl;
    a.output(); cout << endl;

    TMyClass b(a);
    cout << ">>Объект b:" << endl;
    b.output(); cout << endl;

    TMyClass* c = new TMyClass;
    cout << ">>Объект с:" << endl;
    c->output(); cout << endl;

    TChild da; 
    cout << ">>Собственный вывод дочернего объекта da:" << endl;
    da.output();
    cout << ">>Унаследованый вывод объекта dа:" << endl;
    da.TMyClass::output(); cout << endl;
    cout << ">>Проверка наследования дружественной функции:" << endl;
    friendInput(da);
    cout << ">>Собственный вывод дочернего объекта dа:" << endl;
    da.output();

    TChild db(da);
    cout << ">>Собственный вывод дочернего объекта db:" << endl;
    db.output(); 
    cout << ">>Унаследованый вывод дочернего объекта db:" << endl;
    db.TMyClass::output(); cout << endl;

    TChild* dc = new TChild;
    cout << ">>Собственный вывод дочернего объекта dc:" << endl;
    dc->output();
    cout << ">>Унаследованый вывод дочернего объекта dc:" << endl;
    dc->TMyClass::output();

    delete c;
    delete dc;

    return 0;
}
