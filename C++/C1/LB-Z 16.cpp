#include <iostream>
#include <string>
using namespace std;

//Класс
class TMyClass
{
private:
    char* ukaz;
    int dinSize;
    double* dinMas;
public:
    TMyClass(char uk = 'A', int dS = 5, double dM = 5);
    TMyClass(const TMyClass& t);
    ~TMyClass();

    void input();
    void output();

    TMyClass& operator = (const TMyClass& t);
    TMyClass operator + (const TMyClass& t) const;  // Изменено: возвращает новый объект
    friend bool operator <= (const TMyClass& t, const TMyClass& t2);
    bool operator == (const TMyClass& t) const;
    friend TMyClass operator += (TMyClass& t, double num);
};

//Конструктор по умолчанию
TMyClass::TMyClass(char uk, int dS, double dM)
{
    ukaz = new char;
    *ukaz = uk;
    dinSize = dS;
    dinMas = new double[dinSize];
    for (int i = 0; i < dinSize; i++)
        dinMas[i] = dM;
}

//Конструктор копирования
TMyClass::TMyClass(const TMyClass& t)
{
    ukaz = new char;
    *ukaz = *t.ukaz;
    dinSize = t.dinSize;
    dinMas = new double[dinSize];
    for (int i = 0; i < dinSize; i++)
        dinMas[i] = t.dinMas[i];
}

//Деструктор
TMyClass::~TMyClass()
{
    delete ukaz;
    delete[] dinMas;
}

//Метод класса ввод
void TMyClass::input()
{
    cout << ">Ввод данных: " << endl;
    cout << "Введите указатель типа char: ";
    cin >> *ukaz;
    do
    {
        cout << "Введите количество элементов для дин.Массива (>0): ";
        cin >> dinSize;
    } while (dinSize <= 0);
    delete[] dinMas;
    dinMas = new double[dinSize];
    cout << ">Введите элементы дин.Массива: " << endl;
    for (int i = 0; i < dinSize; i++)
    {
        cout << "Элемент " << i + 1 << " : ";
        cin >> dinMas[i];
    }
}

//Метод класса вывод
void TMyClass::output()
{
    cout << ">Вывод данных: " << endl;
    cout << "Имя объекта: " << *ukaz << endl;
    cout << ">Вывод массива:" << endl;
    for (int i = 0; i < dinSize; i++)
        cout << "Элемент " << i+1 << " : " << dinMas[i] << endl;
}

//Перегурзка оператора присваивания
TMyClass& TMyClass::operator = (const TMyClass& t)
{
    if (this != &t)
    {
        delete[] dinMas;
        delete ukaz;
        dinSize = t.dinSize;
        ukaz = new char(*t.ukaz);
        dinMas = new double[dinSize];
        for (int i = 0; i < dinSize; i++)
            dinMas[i] = t.dinMas[i];
    }
    return *this;
}
//Перегрузка оператора + (теперь возвращает новый объект)
TMyClass TMyClass::operator + (const TMyClass& t) const
{
    TMyClass result; 
    result.dinSize = (this->dinSize > t.dinSize) ? this->dinSize : t.dinSize;
    result.dinMas = new double[result.dinSize];
    int minSize = (this->dinSize < t.dinSize) ? this->dinSize : t.dinSize;
    for (int i = 0; i < minSize; i++)
    {
        result.dinMas[i] = this->dinMas[i] + t.dinMas[i];
    }
    if (this->dinSize > t.dinSize)
    {
        for (int i = minSize; i < result.dinSize; i++)
            result.dinMas[i] = this->dinMas[i];
    }
    else
    {
        for (int i = minSize; i < result.dinSize; i++)
            result.dinMas[i] = t.dinMas[i];
    }
    return result;
}

//Перегрузка оператора <=
bool operator <= (const TMyClass& t, const TMyClass& t2)
{
    return t.dinSize <= t2.dinSize;
}

//Перегрузка оператора равно
bool TMyClass::operator == (const TMyClass& t) const
{
    if ((dinSize != t.dinSize) || (*ukaz != *t.ukaz))
        return false;
    for (int i = 0; i < dinSize; i++)
        if (dinMas[i] != t.dinMas[i])
            return false;
    return true;
}

//Перегрузка оператора +=
TMyClass operator += (TMyClass& t, double num)
{
    for (int i = 0; i < t.dinSize; i++)
        t.dinMas[i] += num;
    return t;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "ЛАБОРАТОРНАЯ РАБОТА 16: ПЕРЕГРУЗКА ОПЕРАЦИЙ." << endl;
    cout << "=============================================" << endl;

    TMyClass a;
    TMyClass b('B', 3, 1);
    TMyClass c('C', 2, 3);
    TMyClass x;

    cout << ">>Объект а: " << endl;
    a.output(); cout << endl;

    cout << ">>Объект b: " << endl;
    b.output(); cout << endl;

    cout << ">>Объект с:" << endl;
    c.output(); cout<< endl;

    cout << ">>Приравнивание b = a : " << endl;
    b = a;
    b.output(); cout << endl;

    cout << ">>Сравнение a == b: ";
    cout << (a == b ? "Равны" : "Не равны") << endl;

    cout << ">>Сравнение a == c: ";
    cout << (a == c ? "Равны" : "Не равны") << endl;

    cout << endl;

    cout << ">>Оператор a += 3.5: " << endl;
    a += 3.5;
    a.output(); cout << endl;

    cout << ">>Оператор a <= b: ";
    cout << (a <= b ? "Истина" : "Ложь") << endl;

    cout << ">>Оператор a <= c: ";
    cout << (a <= c ? "Истина" : "Ложь") << endl;
    cout << endl;

    cout << ">>Сложение массивов c = a + b: " << endl;
    x = c + b;
    x.output();
    
    /*TMyClass d;
 cout << ">>Введите объект d: " << endl;
 d.input(); cout << endl;
 cout << "Объект d: " << endl;
 d.output();cout << endl;
 cout << ">>Оператор d += 4.5: " << endl;
 d += 4.5;
 d.output(); cout << endl;
 cout << ">>Сравнение d == a: ";
 cout << (d == a ? "Равны" : "Не равны") << endl;
 cout << ">>Сравнение d == b: ";
 cout << (d == b ? "Равны" : "Не равны") << endl;
 cout << ">>Сравнение d == c: ";
 cout << (d == c ? "Равны" : "Не равны") << endl << endl;
 cout << ">>Оператор d <= a: ";
 cout << (d <= a ? "Истина" : "Ложь") << endl;
 cout << ">>Оператор d <= b: ";
 cout << (d <= b ? "Истина" : "Ложь") << endl;
 cout << ">>Оператор d <= c: ";
 cout << (d <= c ? "Истина" : "Ложь") << endl << endl;
 cout << ">>Сложение массивов d + c: " << endl;
 d + c;
 d.output();*/

    return 0;
}
