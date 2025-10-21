//Угол - Структура/Класс
//Вариант 6
//=======================
#include <iostream>
#include <cmath>

using namespace std;

//==========КЛАСС===========
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
	void display() const;

	bool CRovno(const Angle& other) const;
	bool CNeRovno(const Angle& other) const;
	bool CMensh(const Angle& other) const;
	bool CBolsh(const Angle& other) const;
};

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

//========СТРУКТУРА=========
struct SAngle
{
	int degrees;
	int minutes;

	void Snormalize()
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

	double SToRadians() const
	{
		double totalDegs = degrees + minutes / 60.0;
		return totalDegs * 3.14 / 180.0;
	}

	double SGetSin() const
	{
		return sin(SToRadians());
	}

	void SIncrease(int deg, int min)
	{
		degrees += deg;
		minutes += min;
		Snormalize();
	}

	void SDecrease(int deg, int min)
	{
		degrees -= deg;
		minutes -= min;
		Snormalize();
	}

	void SDisplay() const
	{
		cout << degrees << "° " << minutes << "'." << endl;
	}

	bool bigger(int deg, int min)
	{
		return deg > min;
	}

	bool litter(int deg, int min)
	{
		return deg < min;
	}

	bool rovno(int deg, int min)
	{
		return (deg == min);
	}

	bool nerovno(int deg, int min)
	{
		return (deg != min);
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "===РЕАЛИЗАЦИЯ ЧЕРЕЗ КЛАСС===" << endl << endl;

	Angle a1(45, 30);
	Angle a2(400, 15);

	int a;

	cout << ">>Угол a1." << endl;
	cout << "Начальные значения: "; a1.display(); 
	cout << "Перевод в радианы: " << a1.toRadians() << " рад." << endl;
	cout << "Синус: " << a1.getSin() << "." << endl << endl;

	cout << ">>Угол a2." << endl;
	cout << "Начальные значение: "; a2.display();
	cout << "Перевод в радианы: " << a2.toRadians() << " рад." << endl;
	cout << "Синус: " << a2.getSin() << "." << endl << endl;

	cout << ">>Увеличение угла a1." << endl;
	cout << "Введите увеличение для градусов: ";
	cin >> a;
	a1.increase(a, 0);
	cout << "Угoл после увеличения: "; a1.display(); cout << endl;

	cout << ">>Уменьшение угла a1." << endl;
	cout << "Введите уменьшение для градусов: ";
	cin >> a;
	a1.decrease(a, 0);
	cout << "Угол после уменьшения: "; a1.display(); cout << endl;

	cout << ">>Сравнение углов." << endl;
	cout << "a1 == a2: " << (a1.CRovno(a2)) << endl;
	cout << "a1 != a2: " << (a1.CNeRovno(a2)) << endl;
	cout << "a1 > a2: " << (a1.CBolsh(a2)) << endl;
	cout << "a1 < a2: " << (a1.CMensh(a2)) << endl << endl;

	cout << "===РЕАЛИЗАЦИЯ ЧЕРЕЗ СТРУКТУРУ===" << endl << endl;

	SAngle b1;
	b1.degrees = 45;
	b1.minutes = 30;
	b1.Snormalize();

	SAngle b2;
	b2.degrees = 400;
	b2.minutes = 15;
	b2.Snormalize();

	cout << ">>Угол b1." << endl;
	cout << "Начальные значения: "; b1.SDisplay();
	cout << "Перевод в радианы: " << b1.SToRadians() << " рад." << endl;
	cout << "Синус: " << b1.SGetSin() << "." << endl << endl;

	cout << ">>Угол b2." << endl;
	cout << "Начальные значения: "; b2.SDisplay();
	cout << "Перевод в радианы: " << b2.SToRadians() << " рад." << endl;
	cout << "Синус: " << b2.SGetSin() << "." << endl << endl;

	cout << ">>Увеличение угла b1." << endl;
	cout << "Введите увеличение для градусов: ";
	cin >> a;
	b1.SIncrease(a, 0);
	cout << "Угол после увеличения: "; b1.SDisplay(); cout << endl << endl;

	cout << ">>Уменьшение угла b2." << endl;
	cout << "Введите уменьшение для градусов: ";
	cin >> a;
	b2.SDecrease(a, 0);
	cout << "Угол после уменьшение: "; b2.SDisplay(); cout << endl << endl;

	cout << ">>Сравнение углов." << endl;
	cout << "b1 < b2: " << b2.bigger(b2.degrees, b2.minutes) << endl;
	cout << "b1 > b2: " << b2.litter(b2.degrees, b2.minutes) << endl;
	cout << "b1 == b2: " << b2.rovno(b2.degrees, b2.minutes) << endl;
	cout << "b1 != b2: " << b2.nerovno(b2.degrees, b2.minutes) << endl << endl;

	return 0;
}
