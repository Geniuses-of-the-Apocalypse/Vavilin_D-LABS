//Угол (6)
//=======================
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
	Angle(int deg, int min);

	double toRadians() const;
	double getSin() const;
	void increase(int deg, int min = 0);
	void decrease(int deg, int min = 0);
	void output() const;

	//Перегрущки
	bool operator == (const Angle& other) const
	{
		return degrees == other.degrees && minutes == other.minutes;
	}

	bool operator != (const Angle& other) const
	{
		return !(*this == other);
	}

	bool operator < (const Angle& other) const
	{
		if (degrees != other.degrees)
			return degrees < other.degrees;
		return minutes < other.minutes;
	}

	bool operator > (const Angle& other) const
	{
		return other < *this;
	}
};

//Реализация конструктора и методов
Angle::Angle(int deg, int min)
{
	degrees = deg;
	minutes = min;
	normalize();
}

void Angle::normalize() //К диапозону 0-360
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

void Angle::output() const
{
	cout << degrees << "° " << minutes << "'." << endl;
}

//Вывод значений
int main()
{
	setlocale(LC_ALL, "RUS");

	Angle a1(45, 30);
	Angle a2(400, 15);

	int a;
	
	cout << ">>Угол a1." << endl;
	cout << "Начальные значения: "; a1.output(); 
	cout << "Перевод в радианы: " << a1.toRadians() << " рад." << endl;
	cout << "Синус: " << a1.getSin() << "." << endl << endl;

	cout << ">>Угол a2." << endl;
	cout << "Начальные значение: "; a2.output();
	cout << "Перевод в радианы: " << a2.toRadians() << " рад." << endl;
	cout << "Синус: " << a2.getSin() << "." << endl << endl;

	cout << ">>Увеличение угла a1." << endl;
	cout << "Введите увеличение для градусов: ";
	cin >> a;
	a1.increase(a, 0);
	cout << "Угoл после увеличения: "; a1.output(); cout << endl;

	cout << ">>Уменьшение угла a1." << endl;
	cout << "Введите уменьшение для градусов: ";
	cin >> a;
	a1.decrease(a, 0);
	cout << "Угол после уменьшения: "; a1.output(); cout << endl;

	cout << ">>Сравнение углов." << endl;
	cout << "a1 < a2: " << (a1 < a2) << endl;
	cout << "a1 > a2: " << (a1 > a2) << endl;
	cout << "a1 == a2: " << (a1 == a2) << endl;
	cout << "a1 != a2: " << (a1 != a2) << endl;

	return 0;
}
