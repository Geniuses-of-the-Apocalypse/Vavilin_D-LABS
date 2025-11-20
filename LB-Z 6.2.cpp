#include <iostream>
using namespace std;

template<typename... Conditions>
bool anyTrue(Conditions&&... conditions) {
    return (conditions || ...);
}

int main() {
    setlocale(LC_ALL, "RUS");
    
    cout << ">>Вывод примеров: " << endl;
    bool result1 = anyTrue(false, false, true, false);
    cout << (result1==1 ? "Истина." : "Ложь") << endl;
    bool result2 = anyTrue(false, false, false);
    cout << (result2==1 ? "Истина." : "Ложь.") << endl;
    bool result3 = anyTrue(true); 
    cout << (result3==1 ? "Истина." : "Ложь.") << endl;
    
    return 0;
}
