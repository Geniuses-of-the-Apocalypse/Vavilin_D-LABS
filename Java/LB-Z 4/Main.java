//Динамическая структура.
//Вариант: 6.
//===============================================

package JAVA.GUU.RU.LAB4;

public class Main {
    public static void main(String[] args) {
        System.out.println("ДИНАМИЧЕСКАЯ СТРУКТУРА.");
        System.out.println("========================");
        System.out.println("\n>>Работа с целыми числами.");
        DynamicArray<Integer> intArray = new DynamicArray<>(new IntegerComparator());

        //Задаёмэлементы
        intArray.add(5);
        intArray.add(2);
        intArray.add(8);
        intArray.add(1);
        intArray.add(9);
        intArray.add(3);
        intArray.add(7);

        System.out.println("Исходный массив: " + intArray);

        //Сортируем подсчётом
        intArray.countingSort();
        System.out.println("После сортировки подсчётом: " + intArray);

        //Поиск элемента
        int index = intArray.binarySearch(5);
        System.out.println("Индекс элемента 5: " + index);

        //Удаление элемента
        intArray.remove(2);
        System.out.println("После удаления элемента с индексом 2: " + intArray);

        System.out.println("\n>>Работа со строками.");
        DynamicArray<String> stringArray = new DynamicArray<>(new StringComparator());

        stringArray.add("banana");
        stringArray.add("apple");
        stringArray.add("cherry");
        stringArray.add("date");
        stringArray.add("elderberry");

        System.out.println("Исходный массив: " + stringArray);

        //Сортировка для строк
        stringArray.quickSort();
        System.out.println("После быстрой сортировки: " + stringArray);

        System.out.println("\n>>Работа с символами.");
        DynamicArray<Character> charArray = new DynamicArray<>(new CharComparator());

        charArray.add('z');
        charArray.add('a');
        charArray.add('m');
        charArray.add('b');
        charArray.add('c');

        System.out.println("Исходный массив: " + charArray);

        //Сортировка пузырьком
        charArray.bubbleSort();
        System.out.println("После сортировки пузырьком: " + charArray);

        System.out.println("\n>>Работа с дополнительными методами.");
        System.out.println("Размер массива: " + intArray.size());
        System.out.println("Пустой ли массив?: " + intArray.isEmpty());
        System.out.println("Элемент с индексом 0: " + intArray.get(0));

        intArray.set(0, 10);
        System.out.println("После замены первого элемента: " + intArray);

        System.out.println("Содержит ли массив 10? " + intArray.contains(10));
        System.out.println("Индекс элемента 8: " + intArray.indexOf(8));

        intArray.clear();
        System.out.println("После очистки: " + intArray);
    }
}
