//Угол (6)
//========================
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

	double toRadians() const;
	double getSin() const;
	void increase(int deg, int min);
	void decrease(int deg, int min);
	void display() const;

	//Перегрузки
	Angle operator + (const Angle& other) const
	{
		return Angle(degrees + other.degrees, minutes + other.minutes);
	}
	
	Angle operator - (const Angle& other) const
	{
		return Angle(degrees + other.degrees, minutes + other.minutes);
	}

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

	friend ostream& operator << (ostream& os, const Angle& angle)
	{
		os << angle.degrees << "° " << angle.minutes << "'.";
		return os;
	}

	friend istream& operator >> (istream& is, Angle& angle)
	{
		is >> angle.degrees >> angle.minutes;
		angle.normalize();
		return is;
	}
};

//Методы и тд.
Angle::Angle(int deg, int min)
{
	degrees = deg;
	minutes = min;
	normalize();
}

void Angle::normalize()
{
	degrees += minutes / 60;
	minutes %= 60;

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
	return totalDegs * 3.14 / 189.0;
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

void Angle::display() const
{
	cout << degrees << "° " << minutes << "'." << endl;
}

//Вывод всего
int main()
{
	setlocale(LC_ALL, "RUS");

	Angle a1(45, 30);
	Angle a2(400, 15);
	Angle a3(-90, 45);

	cout << ">Вывод углов." << endl;
	cout << "Угол a1 (45 и 30): " << a1 << endl;
	cout << "Угол a2 (400 и 15): " << a2 << endl;
	cout << "Угол a3 (-90 и 45): " << a3 << endl << endl;

	cout << ">Перевод в радианы." << endl;
	cout << "Угол а1: " << a1.toRadians() << endl;
	cout << "Угол а2: " << a2.toRadians() << endl;
	cout << "Угол а3: " << a3.toRadians() << endl << endl;

	cout << ">Синусы углов." << endl;
	cout << "Угол а1: " << a1.getSin() << endl;
	cout << "Угол а2: " << a2.getSin() << endl;
	cout << "Угол a3: " << a3.getSin() << endl << endl;

	Angle sums = a1 + a2;
	Angle difs = a1 - a2;

	cout << ">Сумма углов a1 и a2: " << sums << endl;
	cout << ">Разность углов a1 и a2: " << difs << endl << endl;

	cout << ">Увеличение угла на 30 и 15." << endl;
	a1.increase(30, 15);
	cout << "Угол после увеличения: " << a1 << endl << endl;

	cout << ">Уменьшение угла на 15 и 30." << endl;
	a1.decrease(15, 30);
	cout << "Угол после уменьшения: " << a1 << endl << endl;

	cout << ">Сравнение углов." << endl;
	cout << "Угол a1 == a2: " << (a1 == a2 ? "Правда" : "Ложь") << endl;
	cout << "Угол a1 != a2: " << (a1 != a2 ? "Правда" : "Ложь") << endl;
	cout << "Угол a1 > a2: " << (a1 > a2 ? "Правда" : "Ложь") << endl;
	cout << "Угол a1 < a2: " << (a1 < a2 ? "Правда" : "Ложь") << endl;

	return 0;
}
