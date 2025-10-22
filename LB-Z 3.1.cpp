#include <iostream>
#include <cmath>
#include <string>

using namespace std;

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

	void display() const
	{
		cout << "(" << a << ", " << b << ", " << c << ").";
	}
};

class Triangle : public Triad
{
public:
	Triangle() : Triad() {}
	Triangle(double side1, double side2, double side3) : Triad(side1, side2, side3)
	{
		if (!isValidTriangle())
			cout << "Ошибка: Треугольник с такими сторонами не существует!" << endl;
	}

	bool isValidTriangle() const
	{
		return (a + b > c) && (a + c > b) && (b + c > a) && (a > 0) && (b > 0) && (c > 0);
	}

	void calculateAngles(double& angleA, double& angleB, double& angleC) const
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

	double calculateArea() const
	{
		if (!isValidTriangle())
			return 0;

		double sperimeter = sum() / 2;
		return sqrt(sperimeter * (sperimeter - a) * (sperimeter - b) * (sperimeter - c));
	}

	double calculatePerim() const
	{
		return sum();
	}

	void displayTriangle() const
	{
		cout << "Треугольник со сторонами: ";
		display(); cout << endl;

		if (isValidTriangle())
		{
			double angleA, angleB, angleC;
			calculateAngles(angleA, angleB, angleC);
			
		}
		else
			cout << "Ошибка: Треугольник не существует!" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");

	Triad triad(3, 4, 5);
	cout << "Тройка чисел: ";
	triad.display();
	cout << endl << "Сумма чисел: " << triad.sum() << endl << endl;

	cout << "Треугольник 1: " << endl;
	Triangle triangle(3, 4, 5);
	triangle.displayTriangle();
	cout << endl;

	cout << "Треугольник 2: " << endl;
	Triangle triangle2(5, 12, 13);
	triangle2.displayTriangle();
	cout << endl;

	cout << "Треугольник 3: " << endl;
	Triangle triangle3(1, 2, 5);
	triangle.displayTriangle();
	cout << endl;

	cout << "Треугольник 4: " << endl;
	Triangle triangle4;
	triangle4.displayTriangle();
	cout << endl;

	cout << "Треугольник 4 (Задаём стороны через сетеры):" << endl;
	triangle4.setA(6);
	triangle4.setB(8);
	triangle4.setC(10);
	triangle4.displayTriangle();

	return 0;
}
