package JAVA.GUU.RU.LAB3;

public class BitString implements Array //Класс для битовых строк
{
    private static final int size = 100;
    private byte[] bits;

    public BitString()
    {
        bits = new byte[size];
    } //Конструктор по умолчанию

    public BitString(String bitStr) //Строковый конструктор
    {
        this();

        for (int i = 0; i < bitStr.length() && i < size; i++)
        {
            char c = bitStr.charAt(bitStr.length() - 1 - i);
            bits[i] = (byte) (c == '1' ? 1 : 0);
        }
    }

    @Override
    public Array add(Array other) //Для сложения массива
    {
        if (!(other instanceof BitString))
        {
            throw new IllegalArgumentException("Неверный тип для сложения");
        }

        BitString otherBits = (BitString) other;
        BitString result = new BitString();

        int carry = 0;
        for (int i = 0; i < size; i++)
        {
            int sum = this.bits[i] + otherBits.bits[i] + carry;
            result.bits[i] = (byte)(sum % 2);
            carry = sum / 2;
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
            if (bits[i] != 0)
                mainZero = false;
            if (!mainZero)
                result += bits[i];
        }

        if (mainZero)
            result = "0";

        System.out.println("BitString: " + result);
    }
}
