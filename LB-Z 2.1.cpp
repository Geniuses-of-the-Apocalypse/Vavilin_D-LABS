//Угол (6)
//====================
#include <iostream>
#include <cmath>

using namespace std;

//Класс
class Angle
{
private:
	int degrees;
	int minutes;
	void normalize();

public:
	Angle(int deg = 0, int min = 0);
	Angle(const Angle& other);
	//~Angle();

	double toRadians() const;
	double getSin() const;
	void increase(int deg, int min);
	void decrease(int deg, int min);
	void display() const;
	void input();

	bool CRovno(const Angle& other) const;
	bool CNeRovno(const Angle& other) const;
	bool CMensh(const Angle& other) const;
	bool CBolsh(const Angle& other) const;

	int getDegs() const { return degrees; }
	int getMins() const { return minutes; }
};

//Методы и конструкторы
Angle::Angle(int deg, int min)
{
	degrees = deg;
	minutes = min;
	normalize();
}

Angle::Angle(const Angle& other)
{
	degrees = other.degrees;
	minutes = other.minutes;
}

void Angle::normalize()
{
	degrees += minutes / 60;
	minutes = minutes % 60;

	if (minutes < 0)
	{
		minutes += 60;
		degrees -= 1;
	}

	degrees = degrees % 360;
	if (degrees < 0)
		degrees += 360;
}

double Angle::toRadians() const
{
	double totalDegs = degrees + minutes / 60.0;
	return totalDegs * 3.14 / 180.0;
}

double Angle::getSin() const
{
	return sin(toRadians());
}

void Angle::increase(int deg, int min)
{
	degrees += deg;
	minutes += min;
	normalize();
}

void Angle::decrease(int deg, int min)
{
	degrees -= deg;
	minutes -= min;
	normalize();
}

bool Angle::CRovno(const Angle& other) const
{
	return degrees == other.degrees && minutes == other.minutes;
}

bool Angle::CNeRovno(const Angle& other) const
{
	return degrees != other.degrees || minutes != other.minutes;
}

bool Angle::CMensh(const Angle& other) const
{
	if (degrees != other.degrees)
		return degrees < other.degrees;
	return minutes < other.minutes;
}

bool Angle::CBolsh(const Angle& other) const
{
	if (degrees != other.degrees)
		return degrees > other.degrees;
	return minutes > other.minutes;
}

void Angle::display() const
{
	cout << degrees << "° " << minutes << "'." << endl;
}

void Angle::input()
{
	cout << "Введите градусы: ";
	cin >> degrees;
	cout << "Введите минуты: ";
	cin >> minutes;
	normalize();
}

//Вывод результатов
int  main()
{
	setlocale(LC_ALL, "RUS");

	cout << ">>Класс Angle." << endl;
	cout << "================" << endl;

	Angle a1;
	Angle a2(45, 30);
	Angle a3(400);
	Angle a4(-90, 75);
	Angle a5(a2);

	int size;

	cout << ">Вывод созданных углов." << endl;
	cout << "Угол a1(конструктор по умолчанию): ";
	a1.display(); 
	cout << "Угол a2 (Заданный на 45 и 30): ";
	a2.display();
	cout << "Угол a3 (Задано 400): ";
	a3.display();
	cout << "Угол a4(Заданный на -90 и 75): ";
	a4.display(); 
	cout << "Угол a5(Копия a2): ";
	a5.display(); cout << endl;

	cout << ">Перевод в радианы." << endl;
	cout << "Угол a1: " << a1.toRadians() << " рад." << endl;
	cout << "Угол a2: " << a2.toRadians() << " рад." << endl;
	cout << "Угол a3: " << a3.toRadians() << " рад." << endl;
	cout << "Угол a4: " << a4.toRadians() << " рад." << endl;
	cout << "Угол a5: " << a5.toRadians() << " рад." << endl << endl;

	cout << ">Синусы углов." << endl;
	cout << "Угол a2: " << a2.getSin() << endl;
	cout << "Угол a4: " << a4.getSin() << endl << endl;

	cout << ">Увеличение угла." << endl;
	cout << "Введите величину для увеличения: ";
	cin >> size;
	cout << "Вывод увеличенного угла a2: ";
	a2.increase(size, 0); a2.display(); cout << endl;

	cout << ">Уменьшение угла." << endl;
	cout << "Введите величину для уменьшения: ";
	cin >> size;
	cout << "Вывод уменьшеного угла а2: ";
	a2.decrease(size, 0); a2.display(); cout << endl;

	cout << ">>Сравнение углов." << endl;
	cout << "a1 == a2: " << (a1.CRovno(a2)) << endl;
	cout << "a1 != a2: " << (a1.CNeRovno(a2)) << endl;
	cout << "a1 > a2: " << (a1.CBolsh(a2)) << endl;
	cout << "a1 < a2: " << (a1.CMensh(a2)) << endl << endl;

	cout << ">Ввод угла." << endl;
	a1.input(); cout << endl;
	cout << "Вывод введённого угла: "; a1.display();
	cout << "Перевод в радианы: " << a1.toRadians() << " рад." << endl;
	cout << "Синус угла: " << a1.getSin() << endl;

	return 0;
}
