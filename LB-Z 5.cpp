#include <iostream>
using namespace std;

// Основная шаблонная функция быстрой сортировки
template<typename T>
void sortQuick(T arr[], int low, int high) {
    if (low < high) {
        // Выбираем опорный элемент (последний элемент)
        T pivot = arr[high];
        
        // Индекс меньшего элемента
        int i = low - 1;
        
        for (int j = low; j <= high - 1; j++) {
            // Если текущий элемент меньше или равен опорному
            if (arr[j] <= pivot) {
                i++; // увеличиваем индекс меньшего элемента
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        
        // Рекурсивно сортируем элементы до и после разделения
        sortQuick(arr, low, pi - 1);
        sortQuick(arr, pi + 1, high);
    }
}

// Перегруженная версия для удобства (принимает только массив и его размер)
template<typename T>
void sortQuick(T arr[], int size) {
    if (size > 1) {
        sortQuick(arr, 0, size - 1);
    }
}

// Пример использования
int main() {
    // Тестирование с целыми числами
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(intArr) / sizeof(intArr[0]);
    
    cout << "Исходный массив целых чисел: ";
    for (int i = 0; i < n1; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;
    
    sortQuick(intArr, n1);
    
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n1; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;
    
    // Тестирование с числами с плавающей точкой
    double doubleArr[] = {64.5, 34.2, 25.1, 12.7, 22.3, 11.9, 90.8};
    int n2 = sizeof(doubleArr) / sizeof(doubleArr[0]);
    
    cout << "\nИсходный массив дробных чисел: ";
    for (int i = 0; i < n2; i++) {
        cout << doubleArr[i] << " ";
    }
    cout << endl;
    
    sortQuick(doubleArr, n2);
    
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n2; i++) {
        cout << doubleArr[i] << " ";
    }
    cout << endl;
    
    // Тестирование со строками
    string strArr[] = {"banana", "apple", "cherry", "date", "elderberry"};
    int n3 = sizeof(strArr) / sizeof(strArr[0]);
    
    cout << "\nИсходный массив строк: ";
    for (int i = 0; i < n3; i++) {
        cout << strArr[i] << " ";
    }
    cout << endl;
    
    sortQuick(strArr, n3);
    
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n3; i++) {
        cout << strArr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
