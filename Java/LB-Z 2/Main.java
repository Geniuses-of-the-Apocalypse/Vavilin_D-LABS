//package ru.guu.java
import java.util.Scanner;
import java.lang.Math;

public class Main
{
    public static void main(String[] args)
    {
        System.out.println("ТРИАДЫ И ТРЕУГОЛЬНИКИ.");
        System.out.println("=======================");
        //Scanner input = new Scanner(System.in);

        Triad triad = new Triad(3, 4, 5);
        System.out.println(">>Триада 1.");
        System.out.print("Вывод: "); triad.display();
        System.out.println("Сумма чисел: " + triad.sums() + "\n");

        Triad triad2 = new Triad(0, 0, 0);
        System.out.println(">>Триада 2.");
        System.out.println(">Введите три числа для триады.");
        triad2.read();
        System.out.print("Вывод: "); triad2.display();
        System.out.println();

        System.out.println(">>Треугольник 1.");
        Triangle triangle = new Triangle(5, 12, 13);
        triangle.displayT();
        System.out.println();

        System.out.println(">>Треугольник 2.");
        Triangle triangle2 = new Triangle(0, 0, 0);
        System.out.println(">Введите стороны треугольника.");
        triangle2.readT();
        System.out.println(">Вывод. ");
        triangle2.displayT();
        System.out.println();

        System.out.println(">>Треугольник 3 (Неправильный).");
        Triangle triangle3 = new Triangle(1, 2, 5);
        triangle3.displayT();
        System.out.println();

        System.out.println(">>Изменение треугольника 3 через сеттеры.");
        triangle3.setA(6);
        triangle3.setB(8);
        triangle3.setC(10);
        triangle3.displayT();
    }
}
