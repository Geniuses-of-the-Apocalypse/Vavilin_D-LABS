//Каллорийность продукта - Структура
//Вариант 6
//============================
#include <iostream>

using namespace std;

struct Product
{
	int first;
	double second;

	double power()
	{
		return (first / 100.0) * (second * 1000.0);
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "КОЛОРИЙНОСТЬ ПРОДУКТА." << endl;
	cout << "========================" << endl;

	Product pack;

	cout << "Введите колорийность продукта (целое число): ";
	cin >> pack.first;

	cout << "Введите массу продукта (нецелое число): ";
	cin >> pack.second;

	cout << "=============================================" << endl;
	cout << ">>Общая колорийность продукта: " << pack.power() << " ккал." << endl;
	return 0;
}
