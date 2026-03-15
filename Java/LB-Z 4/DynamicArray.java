package JAVA.GUU.RU.LAB4;

import java.util.Iterator;
import java.util.NoSuchElementException;

//Класс для динамической работы с элементами
public class DynamicArray<T> implements Iterable<DataElement<T>> {
    private DataElement<T>[] elements;
    private int size;
    private static final int DEFAULT_CAPACITY = 10;
    private Comparator<T> comparator;

    //Конструкторы
    public DynamicArray(Comparator<T> comparator)
    {
        this.elements = (DataElement<T>[]) new DataElement[DEFAULT_CAPACITY];
        this.size = 0;
        this.comparator = comparator;
    }

    public DynamicArray(int initialCapacity, Comparator<T> comparator) {
        if (initialCapacity < 0)
            throw new IllegalArgumentException("Capacity cannot be negative");

        this.elements = (DataElement<T>[]) new DataElement[initialCapacity];
        this.size = 0;
        this.comparator = comparator;
    }

    //>Функции:

    //Добавление элемента
    public void add(T data) {
        if (size == elements.length)
            resize();
        elements[size++] = new DataElement<>(data);
    }

    //Добавление элемента по индексу
    public void add(int index, T data) {
        if (index < 0 || index > size)
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);

        if (size == elements.length)
            resize();

        for (int i = size; i > index; i--)
            elements[i] = elements[i - 1];

        elements[index] = new DataElement<>(data);
        size++;
    }

    //Получение элемента по индексу
    public DataElement<T> get(int index) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        return elements[index];
    }

    //Удаление элемента по индексу
    public DataElement<T> remove(int index) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);

        DataElement<T> removed = elements[index];

        for (int i = index; i < size - 1; i++)
            elements[i] = elements[i + 1];

        elements[size - 1] = null;
        size--;

        return removed;
    }

    //Удаление элемента по значению
    public boolean remove(T data)
    {
        for (int i = 0; i < size; i++)
        {
            if (comparator.compare(elements[i].getData(), data) == 0) {
                remove(i);
                return true;
            }
        }
        return false;
    }

    //Замена элемента
    public DataElement<T> set(int index, T data) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);

        DataElement<T> old = elements[index];
        elements[index] = new DataElement<>(data);
        return old;
    }

    //Проверка наличия элемента
    public boolean contains(T data)
    {
        return indexOf(data) != -1;
    }

    //Поиск индекса элемента
    public int indexOf(T data)
    {
        for (int i = 0; i < size; i++)
        {
            if (comparator.compare(elements[i].getData(), data) == 0)
                return i;
        }
        return -1;
    }

    //Получение размера
    public int size()
    {
        return size;
    }

    //Проверка на пустоту
    public boolean isEmpty()
    {
        return size == 0;
    }

    //Очистка массива
    public void clear()
    {
        elements = (DataElement<T>[]) new DataElement[DEFAULT_CAPACITY];
        size = 0;
    }

    //Изменение размера массива
    private void resize()
    {
        int newCapacity = elements.length * 2;
        DataElement<T>[] newArray = (DataElement<T>[]) new DataElement[newCapacity];
        System.arraycopy(elements, 0, newArray, 0, size);
        elements = newArray;
    }

    //Сортировка подсчётом (для целых чисел)
    public void countingSort()
    {
        if (size <= 1) return;

        if (!isIntegerType())
            throw new UnsupportedOperationException("Counting sort supports only integer types");

        int min = getIntValue(elements[0].getData());
        int max = getIntValue(elements[0].getData());

        for (int i = 1; i < size; i++)
        {
            int value = getIntValue(elements[i].getData());
            if (value < min)
                min = value;
            if (value > max)
                max = value;
        }

        int range = max - min + 1;
        int[] count = new int[range];

        for (int i = 0; i < size; i++)
        {
            int value = getIntValue(elements[i].getData());
            count[value - min]++;
        }

        for (int i = 1; i < range; i++)
        {
            count[i] += count[i - 1];
        }

        DataElement<T>[] output = (DataElement<T>[]) new DataElement[size];

        for (int i = size - 1; i >= 0; i--)
        {
            int value = getIntValue(elements[i].getData());
            int index = count[value - min] - 1;
            output[index] = elements[i];
            count[value - min]--;
        }

        System.arraycopy(output, 0, elements, 0, size);
    }

    //Проверка на целочисленность
    private boolean isIntegerType()
    {
        if (size == 0) return false;
        T data = elements[0].getData();
        return data instanceof Integer ||
                data instanceof Long ||
                data instanceof Short ||
                data instanceof Byte;
    }

    //Получение целочисленного значения
    private int getIntValue(T data)
    {
        if (data instanceof Integer)
            return (Integer) data;
        else if (data instanceof Long)
            return ((Long) data).intValue();
        else if (data instanceof Short)
            return ((Short) data).intValue();
        else if (data instanceof Byte)
            return ((Byte) data).intValue();
        else
            throw new IllegalArgumentException("Cannot convert to int: " + data.getClass());
    }

    //Сортировка пузырьком (для любых типов)
    public void bubbleSort()
    {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (comparator.compare(elements[j].getData(), elements[j + 1].getData()) > 0)
                    swap(j, j + 1);
            }
        }
    }

    //Быстрая сортировка (для любых типов)
    public void quickSort()
    {
        quickSort(0, size - 1);
    }

    private void quickSort(int low, int high)
    {
        if (low < high)
        {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    private int partition(int low, int high)
    {
        T pivot = elements[high].getData();
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (comparator.compare(elements[j].getData(), pivot) <= 0) {
                i++;
                swap(i, j);
            }
        }

        swap(i + 1, high);
        return i + 1;
    }

    private void swap(int i, int j)
    {
        DataElement<T> temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }

    //Бинарный поиск (нужен отсортированный массив)
    public int binarySearch(T target)
    {
        int left = 0;
        int right = size - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int comparison = comparator.compare(elements[mid].getData(), target);

            if (comparison == 0)
                return mid;
            else if (comparison < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    //Линейный поиск
    public int linearSearch(T target)
    {
        for (int i = 0; i < size; i++)
        {
            if (comparator.compare(elements[i].getData(), target) == 0)
                return i;
        }
        return -1;
    }

    //Итератор (for-each)
    @Override
    public Iterator<DataElement<T>> iterator()
    {
        return new Iterator<DataElement<T>>()
        {
            private int currentIndex = 0;

            @Override
            public boolean hasNext() {
                return currentIndex < size;
            }

            @Override
            public DataElement<T> next()
            {
                if (!hasNext())
                    throw new NoSuchElementException();
                return elements[currentIndex++];
            }
        };
    }

    //Метод toString
    @Override
    public String toString()
    {
        if (size == 0)
            return "[]";

        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < size - 1; i++)
            sb.append(elements[i]).append(", ");
        sb.append(elements[size - 1]).append("]");

        return sb.toString();
    }
}
