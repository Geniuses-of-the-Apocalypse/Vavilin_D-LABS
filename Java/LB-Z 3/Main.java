package JAVA.GUU.RU.LAB3;

public class Main
{
    public static void main(String[] args)
    {
        System.out.println("HEX и BitString - ИНТЕРФЕЙСЫ.");
        System.out.println("=======================================");

        System.out.println(">>Демонстрация работы с Hex.");

        //Шестнадцатеричные числа
        Hex hex1 = new Hex("A5");
        Hex hex2 = new Hex("3F");
        Hex hex3 = new Hex("123");

        System.out.print("hex1 = ");
        hex1.display();
        System.out.print("hex2 = ");
        hex2.display();
        System.out.print("hex3 = ");
        hex3.display();
        
        System.out.println("\n>Сложение hex1 + hex2:");
        Hex hexSum1 = (Hex) hex1.add(hex2);
        hexSum1.display();

        System.out.println("\n>Сложение hex1 + hex3:");
        Hex hexSum2 = (Hex) hex1.add(hex3);
        hexSum2.display();

        System.out.println("\n>Сложение hex2 + hex3:");
        Hex hexSum3 = (Hex) hex2.add(hex3);
        hexSum3.display();

        System.out.println("\n>>Демонстрация работы с BitString.");

        //Битовая строка
        BitString bits1 = new BitString("1010");
        BitString bits2 = new BitString("1100");
        BitString bits3 = new BitString("1111");

        System.out.print("bits1 = ");
        bits1.display();
        System.out.print("bits2 = ");
        bits2.display();
        System.out.print("bits3 = ");
        bits3.display();

        //Сложение битовыз строк
        System.out.println("\n>Сложение bits1 + bits2:");
        BitString bitsSum1 = (BitString) bits1.add(bits2);
        bitsSum1.display();

        System.out.println("\n>Сложение bits1 + bits3:");
        BitString bitsSum2 = (BitString) bits1.add(bits3);
        bitsSum2.display();

        System.out.println("\n>Сложение bits2 + bits3:");
        BitString bitsSum3 = (BitString) bits2.add(bits3);
        bitsSum3.display();

        System.out.println("\n>>Полиморфизм.");
        
        Array[] arrays = new Array[4];
        arrays[0] = new Hex("FF");
        arrays[1] = new BitString("101010");
        arrays[2] = new Hex("ABC");
        arrays[3] = new BitString("111000");

        System.out.println(">Исходные массивы:");
        for (int i = 0; i < arrays.length; i++) {
            System.out.print("array[" + i + "] = ");
            arrays[i].display();
        }
        
        System.out.println("\n>Сложение через интерфейс:");

        //Сложение двух классов Hex
        Array result1 = arrays[0].add(arrays[2]);
        System.out.print("Hex(FF) + Hex(ABC) = ");
        result1.display();

        //Сложение двух классов BitString
        Array result2 = arrays[1].add(arrays[3]);
        System.out.print("BitString(101010) + BitString(111000) = ");
        result2.display();

        //Вывод при ошибке
        System.out.println("\n>>Демонстрация обработки ошибки.");
        try {
            System.out.println(">Попытка сложить Hex и BitString:");
            arrays[0].add(arrays[1]);
        } catch (IllegalArgumentException e) {
            System.out.println("Ошибка: " + e.getMessage());
        }
    }
}
