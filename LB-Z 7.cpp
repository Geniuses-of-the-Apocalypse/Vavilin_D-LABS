//Constexpr лямбда для проверки палиндрома - Шаблоны C++ 11/14.
//Вариант: 6.
//==============================================================
#include <iostream>
#include <cstring>

using namespace std;

constexpr bool isStringPalindrome(const char* str, size_t len) {
    if (len == 0) return true;
    
    size_t left = 0;
    size_t right = len - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Шаблонная лямбда
template<typename T>
constexpr auto isPalindrome = [](T n) constexpr {
    // Для целых чисел
    if (std::is_integral<T>::value) {
        if (n < 0) return false;
        
        T original = n;
        T reversed = 0;
        T temp = n;
        
        while (temp > 0) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }
        
        return original == reversed;
    }
    return false; 
};

template<>
constexpr auto isPalindrome<const char*> = [](const char* str) constexpr {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return isStringPalindrome(str, len);
};

template<>
constexpr auto isPalindrome<char> = [](char ch) constexpr {
    return true; 
};

int main() {
    setlocale(LC_ALL, "RUS");
    
    cout << "=== Тестирование числовых палиндромов ===\n";
    constexpr auto result1 = isPalindrome<int>(121);
    constexpr auto result2 = isPalindrome<int>(123);
    cout << "121: " << boolalpha << result1 << endl;
    cout << "123: " << boolalpha << result2 << endl;
    cout << "12321: " << isPalindrome<int>(12321) << endl;
    cout << "1221: " << isPalindrome<int>(1221) << endl;
    cout << "5: " << isPalindrome<int>(5) << endl;
    cout << "0: " << isPalindrome<int>(0) << endl;
    cout << "-121: " << isPalindrome<int>(-121) << endl;
    
    cout << "\n=== Тестирование строковых палиндромов ===\n";
    constexpr auto str1 = isPalindrome<const char*>("racecar");
    constexpr auto str2 = isPalindrome<const char*>("hello");
    cout << "\"racecar\": " << str1 << endl;
    cout << "\"hello\": " << str2 << endl;
    cout << "\"a\": " << isPalindrome<const char*>("a") << endl;
    cout << "\"madam\": " << isPalindrome<const char*>("madam") << endl;
    cout << "\"\": " << isPalindrome<const char*>("") << endl;
    cout << "\"level\": " << isPalindrome<const char*>("level") << endl;
    cout << "\"12321\": " << isPalindrome<const char*>("12321") << endl;
    
    cout << "\n=== Тестирование символов ===\n";
    constexpr char ch = 'A';
    cout << "'A': " << isPalindrome<char>(ch) << endl;
    
    cout << "\n=== Статические проверки ===\n";
    static_assert(isPalindrome<int>(121) == true, "121 - Палиндром");
    static_assert(isPalindrome<int>(123) == false, "123 - Не палиндром");
    static_assert(isPalindrome<const char*>("racecar") == true, "racecar - Палиндром");
    static_assert(isPalindrome<const char*>("hello") == false, "hello - Не палиндром");
    static_assert(isPalindrome<const char*>("a") == true, "a - Палиндром");
    static_assert(isPalindrome<const char*>("madam") == true, "madam - Палиндром");
    static_assert(isPalindrome<const char*>("") == true, "Пустая строка - Палиндром");
    static_assert(isPalindrome<char>('X') == true, "X - Палиндром (одиночный символ)");
    
    // Дополнительные проверки
    static_assert(isPalindrome<int>(12321) == true, "12321 - Палиндром");
    static_assert(isPalindrome<int>(-121) == false, "-121 - Не палиндром");
    
    cout << "Все статические проверки пройдены успешно!\n";
    
    cout << "\n=== Динамические проверки ===\n";
    char input1[] = "шалаш";
    char input2[] = "привет";
    
    cout << "\"шалаш\": " << isPalindrome<const char*>(input1) << endl;
    cout << "\"привет\": " << isPalindrome<const char*>(input2) << endl;
    
    cout << "\n=== Проверка палиндромов из пользовательского ввода ===\n";
    cout << "Введите число или строку (q для выхода):\n";
    
    string userInput;
    while (true) {
        cout << "> ";
        getline(cin, userInput);
        
        if (userInput == "q") break;
        
        // Проверяем, является ли ввод числом
        bool isNumber = true;
        for (char c : userInput) {
            if (!isdigit(c) && c != '-') {
                isNumber = false;
                break;
            }
        }
        
        if (isNumber && !userInput.empty()) {
            int num = stoi(userInput);
            cout << userInput << ": " << (isPalindrome<int>(num) ? "Палиндром" : "Не палиндром") << endl;
        } else {
            cout << userInput << ": " << (isPalindrome<const char*>(userInput.c_str()) ? "Палиндром" : "Не палиндром") << endl;
        }
    }
    
    return 0;
}
