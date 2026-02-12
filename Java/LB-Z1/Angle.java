//package ru.guu.java;
import java.lang.Math;
import java.util.Scanner;

public class Angle
{
    private int degrees;
    private int minutes;

    private void normalize() //Приведение к диапозону от 0 до 360
    {
        degrees += minutes / 60;
        minutes = minutes % 60;

        if (minutes < 0)
        {
            minutes += 60;
            degrees--;
        }

        degrees %= 360;
        if (degrees < 0)
            degrees += 360;
    }

    public double toRadians() //Перевод в радианы
    {
        double totalDegs = degrees + minutes / 60.0;
        return totalDegs * 3.14 / 180.0;
    }

    public double getSin() //Синус
    {
        return Math.sin(toRadians());
    }

    public void increase(int deg, int min) //Увеличение на заданные числа
    {
        degrees += deg;
        minutes += min;
        normalize();
    }

    public void decrease(int deg, int min) //Уменьшение угла на заданные числа
    {
        degrees -= deg;
        minutes -= min;
        normalize();
    }

    public boolean CRovno(Angle other) //Для проверки на равность
    {
        return degrees == other.degrees && minutes == other.minutes;
    }

    public boolean CNeRovno(Angle other) //Для проверки на неравность
    {
        return degrees != other.degrees || minutes != other.minutes;
    }

    public boolean CMensh(Angle other) //Для проерки на знак больше
    {
        if (degrees != other.degrees)
            return degrees < other.degrees;
        return minutes < other.minutes;
    }

    public boolean CBolsh(Angle other) //Для проверки на знак меньше
    {
        if (degrees != other.degrees)
            return degrees > other.degrees;
        return minutes > other.minutes;
    }

    public void init(int deg, int min) //Функция присвоения
    {
        degrees = deg;
        minutes = min;
        normalize();
    }

    public void read() //Функция чтения данных
    {
        Scanner scan = new Scanner(System.in);
        System.out.print("Введите градусы: ");
        degrees = scan.nextInt();
        System.out.print("Введите минуты: ");
        minutes = scan.nextInt();
        normalize();
    }

    public String toString() //Функция преобразования в строку
    {
        return degrees + "° " + minutes + "'.";
    }

    public void display() //Функция вывода преобразованной строки
    {
        System.out.println(toString());
    }
}
