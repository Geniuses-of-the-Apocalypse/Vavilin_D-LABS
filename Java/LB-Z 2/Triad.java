//package ru.guu.java
import java.lang.Math;
import java.util.Scanner;

public class Triad
{
    Scanner scan = new Scanner(System.in);

    protected double a, b, c;

    public Triad(double a, double b, double c) //Конструктор Триады
    {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public void setA(double value) {a = value;}
    public void setB(double value) {b = value;}
    public void setC(double value) {c = value;}

    public double getA() {return a;}
    public double getB() {return b;}
    public double getC() {return c;}

    public double sums()
    {
        return a + b  + c;
    }

    public void read()
    {
        System.out.print("Введите первую переменную: ");
        a = scan.nextDouble();
        System.out.print("Введите вторую переменную: ");
        b = scan.nextDouble();
        System.out.print("Введите третью переменную: ");
        c = scan.nextDouble();
    }

    public String toString()
    {
        return "(" + a + ", " + b + ", " + c + ")";
    }

    public void display()
    {
        System.out.println(toString());
    }
}
