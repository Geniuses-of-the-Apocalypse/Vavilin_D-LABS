package JAVA.GUU.RU.LAB5;

//Класс - модель оператора для дальнейшнй работы
public class Operator
{
    //Поле
    private String name;
    private String pattern;
    private int count;

    //Конструктор
    public Operator(String name, String pattern)
    {
        this.name = name;
        this.pattern = pattern;
        this.count = 0;
    }

    //Гетеры и сетер
    public String getName() { return name; }
    public String getPattern() { return pattern; }
    public int getCount() { return count; }

    public void setCount(int count) { this.count = count; }

    //Инкрементирование и преобразование в строку
    public void incrementCount() { this.count++; }

    @Override
    public String toString()
    {
        return String.format("%s: %d", name, count);
    }
}
