package JAVA.GUU.RU.LAB5;

import java.util.*;
import java.util.regex.*;

public class OperatorCounter
{
    private List<Operator> operators;

    public OperatorCounter()
    {
        initializeOperators();
    }

    private void initializeOperators()
    {
        operators = new ArrayList<>();

        //Арифметические операторы
        operators.add(new Operator("Сложение", "\\+"));
        operators.add(new Operator("Вычитание", "-"));
        operators.add(new Operator("Умножение", "\\*"));
        operators.add(new Operator("Деление", "/"));
        operators.add(new Operator("Остаток", "%"));
        operators.add(new Operator("Инкремент", "\\+\\+"));
        operators.add(new Operator("Декремент", "--"));

        //Операторы присваивания
        operators.add(new Operator("Присваивание", "="));
        operators.add(new Operator("Сложение", "\\+="));
        operators.add(new Operator("Вычитание", "-="));
        operators.add(new Operator("Умножение", "\\*="));
        operators.add(new Operator("Деление", "/="));
        operators.add(new Operator("Остаток", "%="));

        //Операторы сравнения
        operators.add(new Operator("И", "&&"));
        operators.add(new Operator("ИЛИ", "\\|\\|"));
        operators.add(new Operator("НЕ", "!"));

        //Побитовые операторы
        operators.add(new Operator("Побитовое И", "&"));
        operators.add(new Operator("Побитовой ИЛИ", "\\|"));
        operators.add(new Operator("Побитовое XOR", "\\^"));
        operators.add(new Operator("Побитовое НЕ", "~"));
        operators.add(new Operator("Сдвиг влево", "<<"));
        operators.add(new Operator("Сдвиг вправо", ">>"));

        //Иные операторы
        operators.add(new Operator("Тернарный", "\\?"));
        operators.add(new Operator("Двоеточие", ":"));
        operators.add(new Operator("instanceof", "instanceof"));
        operators.add(new Operator("Лямбда", "->"));
        operators.add(new Operator("Точка", "\\."));
    }

    public void countOperators(String code)
    {
        String cleanCode = CodeCleaner.killCommentsNStrings(code);

        for (Operator op : operators)
        {
            int count = countMatches(cleanCode, op.getPattern());
            op.setCount(count);
        }
    }

    private int countMatches(String text, String pattern)
    {
        Pattern p = Pattern.compile(pattern);
        Matcher m = p.matcher(text);

        int count = 0;
        while (m.find())
        {
            count++;
        }
        return count;
    }

    public List<Operator> getOperators()
    {
        return operators;
    }

    public int getTotalCount()
    {
        int total = 0;
        for (Operator op : operators)
            total += op.getCount();
        return total;
    }

    public List<Operator> getNoneZeroOperators()
    {
        List<Operator> result = new ArrayList<>();
        for (Operator op : operators)
        {
            if (op.getCount() > 0)
                result.add(op);
        }
        return result;
    }
}
