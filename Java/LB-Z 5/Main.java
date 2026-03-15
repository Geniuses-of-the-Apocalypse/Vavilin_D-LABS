//Регулярные выражения.
//Вариант: 6.
//===============================================

package JAVA.GUU.RU.LAB5;

import java.io.IOException;
import java.util.List;
import java.nio.file.*;

public class Main
{
    public static void main(String[] args) {
        System.out.println("Регулярные выражения.");

        //Путь к файлу
        String filePath;

        if (args.length > 0)
            filePath = args[0];
        else
        {
            filePath = "D:\\РАБОЧИЙ СТОЛ\\Main Folder\\Programming\\Java\\LABS\\src\\JAVA\\GUU\\RU\\LAB4\\DynamicArray.java";
        }

        try
        {
            //Проверка на существование
            Path path = Paths.get(filePath);
            if (!Files.exists(Paths.get(filePath)))
            {
                System.out.println("Файл не найден: " + Paths.get(filePath).toAbsolutePath());
                System.out.println("Создайте файл или измените путь в коде.");
                return;
            }

            //Чтение
            String code = new String(Files.readAllBytes(Paths.get(filePath)));
            String fileName = path.getFileName().toString();

            //Подсчёт
            OperatorCounter counter = new OperatorCounter();
            counter.countOperators(code);

            //Вывод резльтатов
            ResultPrinter.printHeader(fileName);
            ResultPrinter.printOperators(counter.getNoneZeroOperators());
            ResultPrinter.printSummary(counter.getTotalCount(), counter.getNoneZeroOperators().size());
        }
        catch (IOException e) {
            System.err.println("Ошибка чтения файла: " + e.getMessage());
        }
    }
}
