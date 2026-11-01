//Триады и треугольники - Наследование классов.
//Вариант: 6.
//====================================================
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//Класс Триада
class Triad
{
protected:
	double a, b, c;

public:
	Triad() : a(0), b(0), c(0) {}
	Triad(double a, double b, double c) : a(a), b(b), c(c) {}

	void setA(double value) { a = value; }
	void setB(double value) { b = value; }
	void setC(double value) { c = value; }

	double getA() const { return a; }
	double getB() const { return b; }
	double getC() const { return c; }

	double sum() const
	{
		return a + b + c;
	}

	// Дружественные функции для перегрузки операторов ввода и вывода
	friend ostream& operator<<(ostream& os, const Triad& triad);
	friend istream& operator>>(istream& is, Triad& triad);
};

// Перегрузка оператора вывода для Triad
ostream& operator<<(ostream& os, const Triad& triad)
{
	os << "(" << triad.a << ", " << triad.b << ", " << triad.c << ")";
	return os;
}

// Перегрузка оператора ввода для Triad
istream& operator>>(istream& is, Triad& triad)
{
	is >> triad.a >> triad.b >> triad.c;
	return is;
}

//Класс Треугольник
class Triangle : public Triad
{
public:
	Triangle() : Triad() {}
	Triangle(double side1, double side2, double side3) : Triad(side1, side2, side3)
	{
		if (!isValidTriangle())
			cout << "Ошибка: Треугольник с такими сторонами не существует!" << endl;
	}

	bool isValidTriangle() const;
	void calculateAngles(double& angleA, double& angleB, double& angleC) const;
	double calculateArea() const;
	double calculatePerim() const;
	void displayTriangle() const;

	// Дружественные функции для перегрузки операторов ввода и вывода
	friend ostream& operator<<(ostream& os, const Triangle& triangle);
	friend istream& operator>>(istream& is, Triangle& triangle);
};

// Перегрузка оператора вывода для Triangle
ostream& operator<<(ostream& os, const Triangle& triangle)
{
	os << "Треугольник со сторонами: (" 
	   << triangle.a << ", " << triangle.b << ", " << triangle.c << ")";
	return os;
}

// Перегрузка оператора ввода для Triangle
istream& operator>>(istream& is, Triangle& triangle)
{
	is >> triangle.a >> triangle.b >> triangle.c;
	
	// Проверка существования треугольника после ввода
	if (!triangle.isValidTriangle())
	{
		cout << "Ошибка: Треугольник с такими сторонами не существует!" << endl;
	}
	
	return is;
}

//Реализация функций
bool Triangle::isValidTriangle() const
{
	return (a + b > c) && (a + c > b) && (b + c > a) && (a > 0) && (b > 0) && (c > 0);
}

void Triangle::calculateAngles(double& angleA, double& angleB, double& angleC) const
{
	if (!isValidTriangle())
	{
		angleA = angleB = angleC = 0;
		return;
	}

	angleA = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / 3.14;
	angleB = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / 3.14;
	angleC = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / 3.14;
}

double Triangle::calculateArea() const
{
	if (!isValidTriangle())
		return 0;

	double sperimeter = sum() / 2;
	return sqrt(sperimeter * (sperimeter - a) * (sperimeter - b) * (sperimeter - c));
}

double Triangle::calculatePerim() const
{
	return sum();
}

void Triangle::displayTriangle() const
{
	cout << *this << endl;  

	if (isValidTriangle())
	{
		double angleA, angleB, angleC;
		calculateAngles(angleA, angleB, angleC);
		
		cout << "Углы треугольника: " 
			 << angleA << "°, " 
			 << angleB << "°, " 
			 << angleC << "°" << endl;
		cout << "Периметр: " << calculatePerim() << endl;
		cout << "Площадь: " << calculateArea() << endl;
	}
	else
		cout << "Ошибка: Треугольник не существует!" << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "ТРИАДЫ И ТРЕУГОЛЬНИКИ." << endl;
	cout << "=========================" << endl;

	Triad triad(3, 4, 5);
	cout << "Тройка чисел: " << triad << endl;  
	cout << "Сумма чисел: " << triad.sum() << endl << endl;

	Triad triad2;
	cout << "Введите три числа для триады (через пробел): ";
	cin >> triad2;  // Используем >>
	cout << "Введенная триада: " << triad2 << endl << endl;

	cout << "Треугольник 1: " << endl;
	Triangle triangle(3, 4, 5);
	triangle.displayTriangle();
	cout << endl;

	cout << "Треугольник 2: " << endl;
	Triangle triangle2(5, 12, 13);
	cout << triangle2 << endl;  
	triangle2.displayTriangle();
	cout << endl;

	Triangle triangle3;
	cout << "Введите стороны треугольника (через пробел): ";
	cin >> triangle3; 
	cout << triangle3 << endl;
	triangle3.displayTriangle();
	cout << endl;

	cout << "Треугольник 4 (неправильный): " << endl;
	Triangle triangle4(1, 2, 5);
	triangle4.displayTriangle();
	cout << endl;

	// Изменение треугольника через сеттеры
	cout << "Изменяем треугольник 4 через сеттеры:" << endl;
	triangle4.setA(6);
	triangle4.setB(8);
	triangle4.setC(10);
	triangle4.displayTriangle();

	return 0;
}
