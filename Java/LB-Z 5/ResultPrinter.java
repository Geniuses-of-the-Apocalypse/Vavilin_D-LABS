package JAVA.GUU.RU.LAB5;

import java.util.List;

public class ResultPrinter
{
    public static void printHeader(String fileName)
    {
        System.out.println("\n" + "=".repeat(60));
        System.out.println(">>ПОДСЧЁТ ОПЕРАТОРОВ JAVA");
        System.out.println("-".repeat(60));
        System.out.println(">Название файла: " + fileName);
        System.out.println("=".repeat(60));
    }

    public static void printOperators(List<Operator> operators)
    {
        System.out.println("\n>>Найденные операторы:");
        System.out.println("-".repeat(60));
        System.out.printf("%-35s | %10s%n", "Тип оператора", "Количество");
        System.out.println("-".repeat(60));

        for (Operator op : operators)
        {
            if (op.getCount() > 0)
                System.out.printf("%-35s | %10d%n", op.getName(), op.getCount());
        }
    }

    public static void printSummary(int total, int typesCount)
    {
        System.out.println("-".repeat(60));
        System.out.printf("%-35s | %10d%n", "Всего операторов", total);
        System.out.printf("%-35s | %10d%n", "Типов операторов", typesCount);
        System.out.println("=".repeat(60));
    }

    public static void printError(String message)
    {
        System.err.println(">Ошибка: " + message);
    }
}
