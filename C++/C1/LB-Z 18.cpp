#include<iostream>
#include<string>
using namespace std;

//Виртуальныйи класс УКРАШЕНИЕ
class Jewelir
{
protected:
    string material;
    double price;
    double weight;

public:
    Jewelir(string m = "gold", double p = 500, double w = 20);
    virtual ~Jewelir() {}
    virtual void input();
    virtual void output() const;
    virtual void special() =0;
};

Jewelir::Jewelir(string m, double p, double w)
{
    material = m;
    price = p;
    weight = w;
}

void Jewelir::input()
{
    cout << ">Введите материал изделия: ";
    cin.ignore();
    getline(cin, material);
    cout << ">Введите цену изделия: ";
    cin >> price;
    cout << ">Введите вес изделия: ";
    cin >> weight;
}

void Jewelir::output() const
{
    cout << "Материал: " << material << endl;
    cout << "Цена: " << price << endl;
    cout << "Вес: " << weight << endl; 
}
/*
void Jewelir::special() const
{
    cout << "Обработка изделия: ";
} */

//Класс ЦЕПОЧКА
class Chain : public Jewelir
{
private:
    double len;
public:
    Chain(string m = "Gold", double p = 300, double w = 12, double l = 14);
    void input();
    void output() const;
    void special() const;
};

Chain::Chain(string m, double p, double w, double l) : Jewelir(m, p, w)
{
    len = l;
}

void Chain::input()
{
    cout << ">>Цепочка:" << endl;
    Jewelir::input();
    cout << ">Введите длину изделия: ";
    cin >> len; cout << endl;
    cin.ignore();
}

void Chain::output() const
{
    cout << ">>Цепочка: " << endl;
    Jewelir::output();
    cout << "Длинна: " << len << endl;
}

void Chain::special() const
{
    Jewelir::special();
    cout << "проверка длинны." << endl;
    if (len > 50)
        cout << "Это длинная цепочка. Она будет стоить дороже: " << price+50 << endl;
    else
        cout << "Это цепочка стандартной длинны." << endl;
}

//Класс КОЛЬЦО
class Ring : public Jewelir
{
protected:
    double size;
public:
    Ring(string m = "Gold", double p = 100, double w = 14, double s = 16);
    void input();
    void output() const;
    void special() const;
};

Ring::Ring(string m, double p, double w, double s) : Jewelir(m, w, p)
{
    size = s;
}

void Ring::input()
{
    cout << ">>Кольцо:" << endl;
    Jewelir::input();
    cout << ">Введите размер изделия: ";
    cin >> size; cout << endl;
}

void Ring::output() const
{
    cout << ">>Кольцо: " << endl;
    Jewelir::output();
    cout << "Размер: " << size << endl;
}

void Ring::special() const
{
    Jewelir::special();
    cout << "проверка размера кольца." << endl;
    if (size < 15)
        cout << "Кольцо маленького размера, вероятно женское." << endl;
    else
        cout << "Кольцо большого размера, вероятно мужское." << endl;
}
//Класс КОЛЬЦО С КАМНЕМ (наследник класса Кольцо)
class StoneRing : public Ring
{
private:
    string type;
public:
    StoneRing(string m = "gold", double p = 200, double w = 20, double s = 17, string t = "circle");
    void input();
    void output() const;
    void special() const;
};

StoneRing::StoneRing(string m, double p, double w, double s, string t) : Ring(m, p, w, s)
{
    type = t;
}

void StoneRing::input()
{
    cout << ">>Кольцо с камнем:" << endl;
    Jewelir::input();
    cout << ">Введите размер изделия: ";
    cin >> size;
    cout << ">Введите материал камня: ";
    cin.ignore();
    getline(cin, type); cout << endl;
}

void StoneRing::output() const
{
    cout << ">>Кольцо с камнем: " << endl;
    Jewelir::output();
    cout << "Материал камня: " << type << endl;
}

void StoneRing::special() const
{
    Jewelir::special();
    cout << "проверка веса." << endl;
    if (weight < 20)
        cout << "Камень стандартного веса." << endl;
    else
        cout << "Камень тяжелый, значит изделие более качественное." << endl;
}

void showMenu()
{
    cout << ">>МЕНЮ" << endl;
    cout << "==============================" << endl;
    cout << "Добро пожаловать в магазин украшений!" << endl;
    cout << "1. Заказать цепочку." << endl;
    cout << "2. Заказать кольцо." << endl;
    cout << "3. Заказать кольцо с камнем." << endl;
    cout << "4. Выход." << endl;
    cout << "==============================" << endl;
    cout << "Выберите опцию: ";
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "ЛАБОРАТОРНАЯ РАБОТА 18." << endl;
    cout << "=========================" << endl;

    Jewelir* zakaz = nullptr;
    int num;

    do
    {
        showMenu();
        cin >> num;
        if (num == 4)
            break;
        cout << "==============================" << endl;
        cout << endl;
        switch (num)
        {
        case 1:
            zakaz = new Chain();
            break;
        case 2:
            zakaz = new Ring();
            break;
        case 3:
            zakaz = new StoneRing();
            break;
        default:
            cout << "Опция выбрана не верно. Повторите попытку." << endl << endl;
            continue;
        }

        zakaz->input(); cout << endl;
        zakaz->output(); cout << endl;
        zakaz->special(); cout << endl;

        delete zakaz;
    } while (true);
    cout << "Выход из программы." << endl;
    return 0;
}
