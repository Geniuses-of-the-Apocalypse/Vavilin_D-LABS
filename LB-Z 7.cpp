//Constexpr лямбда для проверки палиндрома - Шаблоны C++ 11/14.
//Вариант: 6.
//==============================================================
#include <iostream>

using namespace std;

template<typename T>
constexpr auto isPalindrome = [](T n) constexpr {
    if (n < 0) return false;
    
    T original = n;
    T reversed = 0;
    
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    return original == reversed;
};

int main() {
    setlocale(LC_ALL, "RUS");
    
    //Тест во время компиляции
    constexpr auto result1 = isPalindrome<int>(121);
    constexpr auto result2 = isPalindrome<int>(123);
    cout << "121: " << result1 << endl;
    cout << "123: " << result2 << endl;
    cout << "12321: " << isPalindrome<int>(12321) << endl;
    cout << "1221: " << isPalindrome<int>(1221) << endl;
    cout << "5: " << isPalindrome<int>(5) << endl;
    cout << "0: " << isPalindrome<int>(0) << endl;
    cout << "-121: " << isPalindrome<int>(-121) << endl;
    
    //Статические проверки
    static_assert(isPalindrome<int>(121) == true, "121 - Полиндром.");
    static_assert(isPalindrome<int>(123) == false, "123 - Не полиндром.");
    
    return 0;
}
