#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Angle
{
private:
	int degrees;
	int minuts;

	void normalize()
	{
		degrees += minuts / 60;
		minuts = minuts % 60;

		if (minuts < 0)
		{
			minuts += 60;
			degrees -= 1;
		}

		degrees = degrees % 360;
		if (degrees < 0)
			degrees += 360;
	}

public:
	Angle() : degrees(0), minuts(0) {}
	Angle(int deg, int min) : degrees(deg), minuts(min) {
		normalize();
	}

	Angle(int deg) : degrees(deg), minuts(0) {
		normalize();
	}

	Angle(const Angle& other) : degrees(other.degrees), minuts(other.minuts) {}

	double toRandians() const {
		double totalDegrees = degrees + minuts / 60.0;
		return totalDegrees * 3.14 / 180.0;
	}

	double getSin() const {
		return sin(toRandians());
	}

	void uvelich(int deg, int min = 0) {
		degrees += deg;
		minuts += min;
		normalize();
	}

	void umensh(int deg, int min = 0) {
		degrees -= deg;
		minuts -= min;
		normalize();
	}

	bool operator==(const Angle& other) const {
		return degrees == other.degrees && minuts == other.minuts;
	}

	bool operator!=(const Angle& other) const {
		return !(*this == other);
	}

	bool operator<(const Angle& other) const {
		if (degrees == other.degrees) {
			return minuts < other.minuts;
		}
		return degrees < other.degrees;
	}

	bool operator>(const Angle& other) const {
		return other < *this;
	}

	bool operator<=(const Angle& other) const {
		return !(*this > other);
	}

	bool operator>=(const Angle& other) const {
		return !(*this < other);
	}

	int getDegrees() const { return degrees; }
	int getMinuts() const { return minuts; }

	void display() const {
		cout << degrees << "° " << minuts << "'";
	}

	void input() {
		cout << "Введите градусы: ";
		cin >> degrees;
		cout << "Введите минуты: ";
		cin >> minuts;
		normalize();
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "=== Демонстрация работы класса Angle ===" << endl << endl;

	Angle angle1;
	Angle angle2(45, 30);
	Angle angle3(400);
	Angle angle4(-90, 75);
	Angle angle5(angle2);

	cout << ">>Созданные углы: " << endl;
	cout << "angle1 (конструктор по умолчанию): ";
	angle1.display(); cout << endl;
	cout << "angle2 (45° 30'): ";
	angle2.display(); cout << endl;
	cout << "angle3 (400°): ";
	angle3.display(); cout << endl;
	cout << "angle4 (-90° 75'): ";
	angle4.display(); cout << endl;
	cout << "angle4 (копия angle2): ";
	angle5.display(); cout << endl;

	cout << "\n>>Перевод в радианы:\n";
	cout << "angle2: " << angle2.toRandians() << " радиан\n";
	cout << "angle3: " << angle3.toRandians() << " радиан\n";

	cout << "\n>>Синусы углов:\n";
	cout << "sin(angle2): " << angle2.getSin() << endl;
	cout << "sin(angle4): " << angle4.getSin() << endl;

	cout << "\n>>Операции с углами:\n";
	Angle testAngle(30, 0);
	cout << ">Исходный угол: "; testAngle.display(); cout << endl;

	testAngle.uvelich(45, 30);
	cout << ">После увеличения на 45° 30': "; testAngle.display(); cout << endl;

	testAngle.umensh(60, 15);
	cout << ">После уменьшения на 60° 15': "; testAngle.display(); cout << endl;

	cout << "\n>>Сравнение углов:\n";
	Angle a1(30, 0);
	Angle a2(30, 30);
	Angle a3(30, 0);

	cout << "a1: "; a1.display(); cout << endl;
	cout << "a2: "; a2.display(); cout << endl;
	cout << "a3: "; a3.display(); cout << endl;

	cout << "a1 == a2: " << (a1 == a2 ? "true" : "false") << endl;
	cout << "a1 == a3: " << (a1 == a3 ? "true" : "false") << endl;
	cout << "a1 < a2: " << (a1 < a2 ? "true" : "false") << endl;
	cout << "a2 > a1: " << (a2 > a1 ? "true" : "false") << endl;

	cout << "\n>>Работа с большими углами:\n";
	Angle bigAngle(725, 75); 
	cout << ">Исходный: 725° 75'\n";
	cout << ">Нормализованный: "; bigAngle.display(); cout << endl;

	return 0;
}
