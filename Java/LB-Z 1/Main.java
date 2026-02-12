//Угол - Класс.
//Вариант: 6.
//=======================

//package ru.guu.java;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        System.out.println("ЛАБОРАТОРНАЯ РАБОТА 1: УГЛЫ.");
        System.out.println("==============================");
        Scanner input = new Scanner(System.in);

        Angle a1 = new Angle();
        Angle a2 = new Angle();
        Angle a3 = new Angle();
        a1.init(45, 30);
        a2.init(400, 15);

        int num;

        System.out.println(">>Угол a1.");
        System.out.print("Начальные значения угла: "); a1.display();
        System.out.println("Перевод значений в радианы: " + a1.toRadians() + " рад.");
        System.out.println("Синус угла: " + a1.getSin() + ".\n");

        System.out.println(">>Угол а2.");
        System.out.print("Начальные значения угла: "); a2.display();
        System.out.println("Перевод значений в радианы: " + a2.toRadians() + " рад.");
        System.out.println("Синус угла: " + a2.getSin() + ".\n");

        System.out.println(">>Увеличение угла а1.");
        System.out.print("Введите значение для увеличения градусов: ");
        num = input.nextInt();
        a1.increase(num, 0);
        System.out.print("Угол а1 после увеличения: "); a1.display();

        System.out.println(">>Уменьшение угла а1.");
        System.out.print("Введите значение для уменьшения градусов: ");
        num = input.nextInt();
        a1.decrease(num, 0);
        System.out.print("Угол а1 после уменьшения: "); a1.display();

        System.out.println(">>Сравнение углов.");
        System.out.println("a1 == a2: " + a1.CRovno(a2));
        System.out.println("a1 != a2: " + a1.CNeRovno(a2));
        System.out.println("a1 > a2: " + a1.CBolsh(a2));
        System.out.println("a1 < a2: " + a1.CMensh(a2) + "\n");

        System.out.println(">>Ввод угла а3.");
        a3.read();
        System.out.println(">>Вывод угла а3.");
        System.out.print("Значения угла: "); a3.display();
        System.out.println("Перевод значений в радианы: " + a3.toRadians() + " рад.");
        System.out.println("Синус угла: " + a3.getSin() + ".\n");
    }
}
