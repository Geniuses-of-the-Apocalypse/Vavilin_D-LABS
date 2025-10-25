#include <iostream>
using namespace std;

//Шаблон быстрой сортировки
template<typename T>
void sortQuick(T arr[], int size) {
    if (size <= 1) return;
    T pivot = arr[size - 1]; //Элемент для опоры
    int i = -1; //Самый мелкий индекс
    for (int j = 0; j < size - 1; j++) { //Проверка текущего элемента
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[size - 1]); //Ставим опору на нужное место
    int pivotIndex = i + 1;
    sortQuick(arr, pivotIndex); //Сортируем левую и правую части
    sortQuick(arr + pivotIndex + 1, size - pivotIndex - 1); 
}

int main() {
    setlocale(LC_ALL, "RUS");
    
    cout << "ШАБЛОН БЫСТРОЙ СОРТИРОВКИ." << endl;
    cout << "=============================" << endl;
    
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(intArr) / sizeof(intArr[0]); //Размер массива
    
    cout << "Исходный массив целых чисел: ";
    for (int i = 0; i < n1; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;
    
    sortQuick(intArr, n1);
    
    cout << ">Отсортированный массив: ";
    for (int i = 0; i < n1; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl << endl;
    
    double doubleArr[] = {64.5, 34.2, 25.1, 12.7, 22.3, 11.9, 90.8};
    int n2 = sizeof(doubleArr) / sizeof(doubleArr[0]);
    
    cout << "Исходный массив дробных чисел: ";
    for (int i = 0; i < n2; i++) {
        cout << doubleArr[i] << " ";
    }
    cout << endl;
    
    sortQuick(doubleArr, n2);
    
    cout << ">Отсортированный массив: ";
    for (int i = 0; i < n2; i++) {
        cout << doubleArr[i] << " ";
    }
    cout << endl << endl;
    
    string strArr[] = {"banana", "apple", "cherry", "watermelon", "chocolate"};
    int n3 = sizeof(strArr) / sizeof(strArr[0]);
    
    cout << "Исходный массив строк: ";
    for (int i = 0; i < n3; i++) {
        cout << strArr[i] << " ";
    }
    cout << endl;
    
    sortQuick(strArr, n3);
    
    cout << ">Отсортированный массив: ";
    for (int i = 0; i < n3; i++) {
        cout << strArr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
