#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Sn=(a0-anr)/(1-r) Формула прогрессии.

class GeometricProgressionError {};

class GeometricProgressionErrorWithParams {
public:
    double a0;
    double an;
    double r;
    string message;
    
    GeometricProgressionErrorWithParams(double a0_val, double an_val, double r_val, const string& msg)
        : a0(a0_val), an(an_val), r(r_val), message(msg) {}
};

class GeometricProgressionStdError : public exception {
public:
    double a0;
    double an;
    double r;
    string error_msg;
    
    GeometricProgressionStdError(double a0_val, double an_val, double r_val, const string& msg)
        : a0(a0_val), an(an_val), r(r_val), error_msg(msg) {}
    
    const char* what() const noexcept override {
        return error_msg.c_str();
    }
};

double geometricProgressionSum1(double a0, double an, double r) {
    if (r == 1.0) {
        throw "Знаменатель прогрессии не может быть равен 1";
    }
    
    if (isnan(a0) || isnan(an) || isnan(r)) {
        throw "Параметры не могут быть NaN";
    }
    
    if (isinf(a0) || isinf(an) || isinf(r)) {
        throw "Параметры не могут быть бесконечными";
    }
    
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15) {
        throw "Деление на очень маленькое число";
    }
    
    return (a0 - an * r) / denominator;
}

double geometricProgressionSum2(double a0, double an, double r) noexcept {
    if (r == 1.0) {
        return NAN;
    }
    
    if (isnan(a0) || isnan(an) || isnan(r)) {
        return NAN;
    }
    
    if (isinf(a0) || isinf(an) || isinf(r)) {
        return NAN;
    }
    
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15) {
        return NAN;
    }
    
    return (a0 - an * r) / denominator;
}

double geometricProgressionSum3(double a0, double an, double r) {
    if (r == 1.0) {
        throw string("Знаменатель прогрессии не может быть равен 1");
    }
    
    if (isnan(a0) || isnan(an) || isnan(r)) {
        throw string("Параметры не могут быть NaN");
    }
    
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15) {
        throw string("Деление на очень маленькое число");
    }
    
    return (a0 - an * r) / denominator;
}

double geometricProgressionSum4_1(double a0, double an, double r) {
    if (r == 1.0) {
        throw GeometricProgressionError();
    }
    
    if (isnan(a0) || isnan(an) || isnan(r)) {
        throw GeometricProgressionError();
    }
    
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15) {
        throw GeometricProgressionError();
    }
    
    return (a0 - an * r) / denominator;
}

double geometricProgressionSum4_2(double a0, double an, double r) {
    if (r == 1.0) {
        throw GeometricProgressionErrorWithParams(a0, an, r, "Знаменатель прогрессии не может быть равен 1");
    }
    
    if (isnan(a0) || isnan(an) || isnan(r)) {
        throw GeometricProgressionErrorWithParams(a0, an, r, "Параметры не могут быть NaN");
    }
    
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15) {
        throw GeometricProgressionErrorWithParams(a0, an, r, "Деление на очень маленькое число");
    }
    
    return (a0 - an * r) / denominator;
}

double geometricProgressionSum4_3(double a0, double an, double r) {
    if (r == 1.0) {
        throw GeometricProgressionStdError(a0, an, r, "Знаменатель прогрессии не может быть равен 1");
    }
    
    if (isnan(a0) || isnan(an) || isnan(r)) {
        throw GeometricProgressionStdError(a0, an, r, "Параметры не могут быть NaN");
    }
    
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15) {
        throw GeometricProgressionStdError(a0, an, r, "Деление на очень маленькое число");
    }
    
    return (a0 - an * r) / denominator;
}

int main() {
    struct TestCase {
        double a0;
        double an;
        double r;
        string description;
    };
    
    TestCase testCases[] = {
        {1.0, 8.0, 0.5, "Нормальный случай"},
        {2.0, 32.0, 2.0, "Нормальный случай с r=2"},
        {1.0, 1.0, 1.0, "r = 1 (ошибка)"},
        {1.0, 2.0, 1.0 + 1e-16, "r почти 1 (ошибка деления)"},
        {NAN, 2.0, 0.5, "a0 = NaN (ошибка)"},
        {1.0, 2.0, INFINITY, "r = INF (ошибка)"}
    };
    
    for (int variant = 1; variant <= 4; ++variant) {
        cout << "\n=== Тестирование варианта " << variant << " ===" << endl;
        
        for (const auto& test : testCases) {
            cout << "\nТест: " << test.description << " (a0=" << test.a0 
                      << ", an=" << test.an << ", r=" << test.r << ")" << endl;
            
            try {
                double result;
                
                switch (variant) {
                    case 1:
                        result = geometricProgressionSum1(test.a0, test.an, test.r);
                        cout << "Результат: " << result << endl;
                        break;
                    case 2:
                        result = geometricProgressionSum2(test.a0, test.an, test.r);
                        if (isnan(result)) {
                            cout << "Ошибка: возвращено NaN (noexcept функция)" << endl;
                        } else {
                            cout << "Результат: " << result << endl;
                        }
                        break;
                    case 3:
                        result = geometricProgressionSum3(test.a0, test.an, test.r);
                        cout << "Результат: " << result << endl;
                        break;
                    case 4:
                        // Тестируем подварианты с собственными исключениями
                        cout << "  Подвариант 4.1: ";
                        try {
                            result = geometricProgressionSum4_1(test.a0, test.an, test.r);
                            cout << "Результат: " << result;
                        } catch (const GeometricProgressionError&) {
                            cout << "Поймано GeometricProgressionError";
                        }
                        
                        cout << "\n  Подвариант 4.2: ";
                        try {
                            result = geometricProgressionSum4_2(test.a0, test.an, test.r);
                            cout << "Результат: " << result;
                        } catch (const GeometricProgressionErrorWithParams& e) {
                            cout << "Поймано GeometricProgressionErrorWithParams: " 
                                      << e.message << " (a0=" << e.a0 << ", an=" << e.an << ", r=" << e.r << ")";
                        }
                        
                        cout << "\n  Подвариант 4.3: ";
                        try {
                            result = geometricProgressionSum4_3(test.a0, test.an, test.r);
                            cout << "Результат: " << result;
                        } catch (const GeometricProgressionStdError& e) {
                            cout << "Поймано GeometricProgressionStdError: " << e.what() 
                                      << " (a0=" << e.a0 << ", an=" << e.an << ", r=" << e.r << ")";
                        }
                        break;
                }
                
            } catch (const char* e) {
                cout << "Поймано исключение типа const char*: " << e << endl;
            } catch (const string& e) {
                cout << "Поймано исключение типа string: " << e << endl;
            } catch (const GeometricProgressionError&) {
                cout << "Поймано GeometricProgressionError" << endl;
            } catch (const GeometricProgressionErrorWithParams& e) {
                cout << "Поймано GeometricProgressionErrorWithParams: " << e.message 
                          << " (a0=" << e.a0 << ", an=" << e.an << ", r=" << e.r << ")" << endl;
            } catch (const GeometricProgressionStdError& e) {
                cout << "Поймано GeometricProgressionStdError: " << e.what() 
                          << " (a0=" << e.a0 << ", an=" << e.an << ", r=" << e.r << ")" << endl;
            } catch (const exception& e) {
                cout << "Поймано exception: " << e.what() << endl;
            } catch (...) {
                cout << "Поймано неизвестное исключение" << endl;
            }
        }
    }
    
    cout << "\n\n=== Демонстрация корректных вычислений ===" << endl;
    
    try {
        double a0 = 1.0, an = 8.0, r = 0.5;
        double expected = (a0 - an * r) / (1 - r);
        
        double result1 = geometricProgressionSum1(a0, an, r);
        double result2 = geometricProgressionSum2(a0, an, r);
        double result3 = geometricProgressionSum3(a0, an, r);
        double result4_1 = geometricProgressionSum4_1(a0, an, r);
        double result4_2 = geometricProgressionSum4_2(a0, an, r);
        double result4_3 = geometricProgressionSum4_3(a0, an, r);
        
        cout << "Геометрическая прогрессия: a0=" << a0 << ", an=" << an << ", r=" << r << endl;
        cout << "Формула: Sn = (a0 - an*r)/(1-r) = (" << a0 << " - " << an << "*" << r << ")/(1-" << r << ")" << endl;
        cout << "Ожидаемый результат: " << expected << endl;
        cout << "Все варианты функций дают одинаковый результат: " << result1 << endl;
        
        if (result1 == result2 && result2 == result3 && result3 == result4_1 && 
            result4_1 == result4_2 && result4_2 == result4_3) {
            cout << "Все функции работают корректно!" << endl;
        } else {
            cout << "Обнаружено расхождение в результатах!" << endl;
        }
        
    } catch (...) {
        cout << "Неожиданная ошибка при корректных параметрах!" << endl;
    }
    return 0;
}
