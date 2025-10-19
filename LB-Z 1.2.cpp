#include <iostream>
#include <cmath>

using namespace std;

class Angle
{
private:
	int degrees;
	int minutes;
	void normalize();

public:
	Angle(int deg, int min);

	double toRadians() const;
	double sin() const;
	void increase(int deg, int min = 0);
	void decrease(int deg, int min = 0);
	void output() const;

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

Angle::Angle(int deg = 0, int min = 0) : degrees(deg), minutes(min)
{
	normalize();
}

void Angle::normalize() //К диапозону 0-360
{
	int totalMins = degrees * 60 + minutes;
	totalMins %= 21600;
	if (totalMins < 0)
		totalMins += 21600;
	degrees = totalMins / 60;
	minutes = totalMins % 60;
}

double Angle::toRadians() const
{
	double totalDegs = degrees + minutes / 60.0;
	return totalDegs * 3.14 / 180.0;
}

double Angle::sin() const
{
	return std::sin(toRadians());
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

int main()
{
	setlocale(LC_ALL, "RUS");

	Angle a1(45, 30);
	Angle a2(400, 15);

	int a;
	int b;

	cout << ">>Угол a1." << endl;
	cout << "Начальные значения: "; a1.output(); 
	cout << "Перевод в радианы: " << a1.toRadians() << " рад." << endl;
	cout << "Синус: " << a1.sin() << "." << endl << endl;

	cout << ">>Угол a2." << endl;
	cout << "Начальные значение: "; a2.output();
	cout << "Перевод в радианы: " << a2.toRadians() << " рад." << endl;
	cout << "Синус: " << a2.sin() << "." << endl << endl;

	cout << ">>Увеличение угла a1." << endl;
	cout << "Введите увеличение для градусов: ";
	cin >> a;
	cout << "Введите увеличение для минут: ";
	cin >> b;
	a1.increase(a, b);
	cout << "Угoл после увеличения: "; a1.output(); cout << endl;

	cout << ">>Уменьшение угла a1." << endl;
	cout << "Введите уменьшение для градусов: ";
	cin >> a;
	cout << "Введите уменьшение для минут: ";
	cin >> b;
	a1.decrease(a, b);
	cout << "Угол после уменьшения: "; a1.output(); cout << endl;

	cout << ">>Сравнение углов." << endl;
	cout << "a1 < a2: " << (a1 < a2) << endl;
	cout << "a1 > a2: " << (a1 > a2) << endl;
	cout << "a1 == a2: " << (a1 == a2) << endl;
	cout << "a1 != a2: " << (a1 != a2) << endl;

	return 0;
}
