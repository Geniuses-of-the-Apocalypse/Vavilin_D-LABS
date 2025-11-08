//LimitedStack - Шаблонный класс.
//Вариант: 6.
//================================
#include <iostream>
#include <cstring>

using namespace std;

template<typename T, size_t MaxSize>
class LimitedStack //Сам шаблонный класс
{
private:
    T elements[MaxSize];
    size_t currentSize;
    
public:
    LimitedStack();
    void push(const T& element);
    T& top();
    const T& top() const;
    void pop(); //Удаление верхушки стака
    bool empty() const;
    size_t size() const;
    size_t max_size() const;
    char* toString() const;
    void outputToStream(ostream& os) const;
    void readFromStream(istream& is);
    void clear();
};

//Методы и конструкторы
template<typename T, size_t MaxSize>
LimitedStack<T, MaxSize>::LimitedStack() : currentSize(0) {}

template<typename T, size_t MaxSize>
void LimitedStack<T, MaxSize>::push(const T& element)
{
    if (currentSize >= MaxSize)
        throw "Стак пуст.";
    elements[currentSize] = element;
    currentSize++;
}

template<typename T, size_t MaxSize>
T& LimitedStack<T, MaxSize>::top()
{
    if (currentSize == 0)
        throw "Стак пуст.";
    return elements[currentSize - 1];
}

template<typename T, size_t MaxSize>
const T& LimitedStack<T, MaxSize>::top() const
{
    if (currentSize == 0)
        throw "Стак пуст.";
    return elements[currentSize - 1];
}

template<typename T, size_t MaxSize>
void LimitedStack<T, MaxSize>::pop()
{
    if (currentSize == 0)
        throw "Стак пуст.";
    currentSize--;
}

template<typename T, size_t MaxSize>
bool LimitedStack<T, MaxSize>::empty() const
{
    return currentSize == 0;
}

template<typename T, size_t MaxSize>
size_t LimitedStack<T, MaxSize>::size() const
{
    return currentSize;
}

template<typename T, size_t MaxSize>
size_t LimitedStack<T, MaxSize>::max_size() const
{
    return MaxSize;
}

template<typename T, size_t MaxSize>
char* LimitedStack<T, MaxSize>::toString() const
{
    size_t bufferSize = 100;
    char* res = new char[bufferSize];
    strcpy(res, "Стак[");
    
    for (size_t i = 0; i < currentSize; ++i)
    {
        char elementStr[50];
        if (is_same<T, int>::value || is_same<T, double>::value)
            sprintf(elementStr, "%d", elements[i]);
        else if (is_same<T, char>::value)
            sprintf(elementStr, "%c", elements[i]);
        else
            sprintf(elementStr, "элемент");
        
        if (strlen(res) + strlen(elementStr) + 10 > bufferSize)
        {
            bufferSize *= 2;
            char* newRes = new char[bufferSize];
            strcpy(newRes, res);
            delete[] res;
            res = newRes;
        }
        
        strcat(res, elementStr);
        if (i < currentSize - 1)
            strcat(res, ", ");
    }
    strcat(res, "]");
    return res;
}

template<typename T, size_t MaxSize>
void LimitedStack<T, MaxSize>::outputToStream(ostream& os) const
{
    char* str = toString();
    os << str;
    delete[] str;
}

template<typename T, size_t MaxSize>
void LimitedStack<T, MaxSize>::readFromStream(istream& is)
{
    clear();
    T element;
    while (currentSize < MaxSize && is >> element)
        push(element);
}

template<typename T, size_t MaxSize>
void LimitedStack<T, MaxSize>::clear()
{
    currentSize = 0;
}

template<typename T, size_t MaxSize>
ostream& operator<<(ostream& os, const LimitedStack<T, MaxSize>& stack)
{
    stack.outputToStream(os);
    return os;
}

template<typename T, size_t MaxSize> 
istream& operator>>(istream& is, LimitedStack<T, MaxSize>& stack)
{
    stack.readFromStream(is);
    return is;
}

//Вывод
int main()
{
    setlocale(LC_ALL, "RUS");
    
    try{
        LimitedStack<int, 5> stack;
        
        cout << "Добавление элементов: " << endl;
        for (int i = 1; i <= 5; ++i)
        {
            stack.push(i);
            char* str = stack.toString();
            cout << "Вставка: " << i << ", Стек: " << str << endl;
            delete[] str;
        }
        
        cout << "Попытка вставить 6й элемент: " << endl;
        try {
            stack.push(6);
        }
        catch (const char* e) {
            cout << "Ошибка: " << e << endl;
        }
            
        cout << "Вывод верхнего элемента: " << stack.top() << endl;
        
        cout << "Извлечение элементов: " << endl;
        while (!stack.empty())
        {
            cout << "Верхушка: " << stack.top() << ", ";
            stack.pop();
            char* str = stack.toString();
            cout << "Стак после удаления верхушки элемента: " << str << endl;
            delete[] str;
        }
        
        cout << "Тестирование вывода элементов: " << endl;
        LimitedStack<int, 3> testStack;
        testStack.push(10);
        testStack.push(20);
        testStack.push(30);
        cout << "Тестовый стак: " << testStack << endl;
    } catch (const char* e) {
        cerr << "Исключение: " << e << endl;
    }
    return 0;
}
