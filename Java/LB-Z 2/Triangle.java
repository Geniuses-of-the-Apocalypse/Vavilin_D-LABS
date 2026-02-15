//package ru.guu.java
import java.lang.Math;
import java.util.Scanner;

public class Triangle extends Triad
{
    Scanner scan = new Scanner(System.in);

    public Triangle(double a, double b, double c) //Конструктор Треугольника
    {
        super(a, b, c); //Вызов конструктор Родителя
    }

    public boolean isValidTriangle()
    {
        return (a + b > c) && (a + c > b) && (b + c > a) && (a > 0) && (b > 0) && (c > 0);
    }

    public void calculateAngles(double angleA, double angleB, double angleC)
    {
        if (!isValidTriangle())
        {
            a = b = c = 0;
            return;
        }

        angleA = Math.acos((b * b + c * c - a * a) / (2 * b * c)) * 180/3.14;
        angleB = Math.acos((a * a + c * c - b * b) / (2 * a * c)) * 180/3.14;
        angleC = Math.acos((a * a + b * b - c * c) / (2 * a * b)) * 180/3.14;
    }

    public double calculateArea()
    {
        if (!isValidTriangle())
            return 0;
        double sperimetr = sums()/2;
        return Math.sqrt(sperimetr * (sperimetr - a) * (sperimetr - b) * (sperimetr - c));
    }

    public double calculatePerim()
    {
        return sums();
    }

    public void readT()
    {
        System.out.print("Введите первую сторону: ");
        a = scan.nextDouble();
        System.out.print("Введите вторую сторону: ");
        b = scan.nextDouble();
        System.out.print("Введите третью сторону: ");
        c = scan.nextDouble();
    }

    public void displayT()
    {
        if (isValidTriangle())
        {
            calculateAngles(a, b, c);

            System.out.println("Углы треугольника: " + a + "°, " +
                    b +"°, " + c + "°.");
            System.out.println("Периметр: " + calculatePerim());
            System.out.println("Площадь: " + calculateArea());
        }
        else
            System.out.println("Ошибка: Треугольник не существует!");
    }
}
