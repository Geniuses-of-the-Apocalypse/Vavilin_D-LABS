/*
=== Немного Теории ===
Интерфейс -  определяет набор требований к классу, а класс применяет эти требования.
instanceof - проверяет объект на пренадлежность к классу.
IllegalArgumentException - выводит сообщение при недопусимом аргументе.
Override - переопределяет метод.
====================
*/

package JAVA.GUU.RU.LAB3;

import java.util.Scanner;
import java.lang.Math;

interface Array
{
   Array add(Array other);
   void display();
}

class Hex implements Array //Класс для 16-ричных чисел
{
    private static final int size = 100; //типо константа
    private short[] numbers;

    public Hex()
    {
        numbers = new short[size];
    } //конструктор по умолчанию

    public Hex(String hexStr) //Строковый конрструктор
    {
        this();

        String cleanHex = "";
        for (int i = 0; i < hexStr.length(); i++)
        {
            char c = hexStr.charAt(i);
            if (c != '0' || (i > 0 && hexStr.charAt(i-1) == 'x'))
            {
                if (c != 'x' && c != 'X')
                    cleanHex += c;
            }
        }
        cleanHex = cleanHex.toUpperCase();

        for (int i = 0; i < cleanHex.length() && i < size; i++)
        {
            char c = cleanHex.charAt(cleanHex.length() - 1 - i);
            if (c >= '0' && c <= '9')
                numbers[i] = (short)(c - '0');
            else if (c >= 'A' && c <= 'F')
                numbers[i] = (short)(c - 'A' + 10);
        }
    }

    @Override
    public Array add(Array other) //Сложение массивов
    {
        if (!(other instanceof Hex))
            throw new IllegalArgumentException("Неверный тип для сложения");

        Hex otherHex = (Hex) other;
        Hex result = new Hex();

        int carry = 0;
        for (int i = 0; i < size; i++)
        {
            int sum = this.numbers[i] + otherHex.numbers[i] + carry;
            result.numbers[i] = (short)(sum % 16);
            carry = sum / 16;
        }
        return result;
    }

    @Override
    public void display() //Вывод
    {
        String result = "";
        boolean mainZero = true;

        for (int i = size - 1; i >= 0; i--)
        {
            if (numbers[i] != 0)
                mainZero = false;
            if (!mainZero)
            {
                if (numbers[i] < 10)
                    result += (char)(numbers[i] + '0');
                else
                    result += (char)(numbers[i] - 10 + 'A');
            }
        }

        if (mainZero)
            result = "0";

        System.out.println("Hex. 0x" + result);
    }
}
