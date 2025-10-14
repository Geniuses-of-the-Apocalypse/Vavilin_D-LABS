#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Triad {
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

    double sum() const {
        return a + b + c;
    }

    void display() const {
        cout << "(" << a << ", " << b << ", " << c << ")";
    }
};

class Triangle : public Triad {
public:
    Triangle() : Triad() {}
    Triangle(double side1, double side2, double side3) : Triad(side1, side2, side3) {
        if (!isValidTriangle()) {
            cout << "Предупреждение: Треугольник с такими сторонами не существует!" << endl;
        }
    }

    bool isValidTriangle() const {
        return (a + b > c) && (a + c > b) && (b + c > a) &&
            (a > 0) && (b > 0) && (c > 0);
    }

    void calculateAngles(double& angleA, double& angleB, double& angleC) const {
        if (!isValidTriangle()) {
            angleA = angleB = angleC = 0;
            return;
        }

        angleA = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / 3.14;
        angleB = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / 3.14;
        angleC = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / 3.14;
    }

    double calculateArea() const {
        if (!isValidTriangle()) {
            return 0;
        }

        double semiperimeter = sum() / 2;
        return sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));
    }

    double calculatePerimeter() const {
        return sum();
    }

    void displayTriangle() const {
        cout << "Треугольник со сторонами: ";
        display();
        cout << endl;

        if (isValidTriangle()) {
            double angleA, angleB, angleC;
            calculateAngles(angleA, angleB, angleC);

            cout << "Площадь: " << calculateArea() << endl;
            cout << "Периметр: " << calculatePerimeter() << endl;
            cout << "Углы: A=" << angleA << "°, B=" << angleB << "°, C=" << angleC << "°" << endl;
        }
        else {
            cout << "Треугольник не существует!" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "RUS");

    Triad triad(3, 4, 5);
    cout << "Тройка чисел: ";
    triad.display();
    cout << "\nСумма чисел: " << triad.sum() << endl << endl;

    Triangle triangle1(3, 4, 5);
    cout << "Треугольник 1:" << endl;
    triangle1.displayTriangle();
    cout << endl;

    Triangle triangle2(5, 12, 13);
    cout << "Треугольник 2:" << endl;
    triangle2.displayTriangle();
    cout << endl;

    Triangle triangle3(1, 2, 5);
    cout << "Треугольник 3:" << endl;
    triangle3.displayTriangle();
    cout << endl;

    Triangle triangle4;
    triangle4.setA(6);
    triangle4.setB(8);
    triangle4.setC(10);

    cout << "Треугольник 4 (после изменения сторон):" << endl;
    triangle4.displayTriangle();

    return 0;
}
