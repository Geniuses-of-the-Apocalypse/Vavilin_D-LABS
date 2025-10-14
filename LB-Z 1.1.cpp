#include <iostream>

using namespace std;

struct Brand
{
    double first;
    int second;
    
    double cost()
    {
        return first * second;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    cout << "ТОВАРЫ." << endl;
    cout << "===================" << endl;
    
    Brand item;
    
    double a;
    int b;
    
    cout << "Введите не целое число: ";
    cin >> a;
    
    cout << "Введите целое число: ";
    cin >> b;
    
    item.first = a;
    item.second = b;
    
    cout << "==============================================" << endl;
    cout << "Общая стоимость товара: " << item.cost() << " рублей." << endl;
    return 0;
}
