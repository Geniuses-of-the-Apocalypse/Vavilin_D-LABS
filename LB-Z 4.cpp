//Геометрическая прогрессия (6) - Исключения
//==========================================
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

//Sn = (a0 - an*r)/(1-r) Формула прогрессии.

class GeomProgressionERR {};

class GeomProgressionERRwithParams
{
public:
    double a0;
    double an;
    double r;
    string message;
    
    GeomProgressionERRwithParams(double a0Val, double anVal, double rVal, const string& mes);
};

GeomProgressionERRwithParams::GeomProgressionERRwithParams(double a0Val, double anVal, double rVal, const string& mes)
{
    a0 = a0Val;
    an = anVal;
    r = rVal;
    message = mes;
}

class GeomProgressionStdERR : public exception
{
public:
    double a0;
    double an;
    double r;
    string errMes;
    
    GeomProgressionStdERR(double a0Val, double anVal, double rVal, const string& mes);
    
    const char* what() const noexcept override;
};

GeomProgressionStdERR::GeomProgressionStdERR(double a0Val, double anVal, double rVal, const string& mes)
{
    a0 = a0Val;
    an = anVal;
    r = rVal;
    errMes = mes;
}

const char* GeomProgressionStdERR::what() const noexcept
{
    return errMes.c_str();
}

//Функции
double geomProgressionSum1(double a0, double an, double r)
{
    if (r == 1.0)
        throw "Знаменатель прогрессии не может быть равен 1";
    //isnan - проверка на число
    if (isnan(a0) || isnan(an) || isnan(r))
        throw "Параметры не могут быть Nan";
    //isinf - Проверка на бесконечность
    if (isinf(a0) || isinf(an) || isinf(r))
        throw "Параметры не могут быть бесконечными";
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15)
        throw "Деление на очень маленькое число";
    return (a0 - an * r) / denominator;
}

double geomProgressionSum2(double a0, double an, double r)
{
    if (r == 1.0)
        return NAN;
    if (isnan(a0) || isnan(an) || isnan(r))
        return NAN;
    if (isinf(a0) || isinf(an) || isinf(r))
        return NAN;
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15)
        return NAN;
    return (a0 - an * r) / denominator;
}

double geomProgressionSum3(double a0, double an, double r)
{
    if (r == 1.0)
        throw string("Знаменатель прогрессии не может быть равен 1");
    if (isnan(a0) || isnan(an) || isnan(r))
        throw string("Параметры не могут быть Nan");
    if (isinf(a0) || isinf(an) || isinf(r))
        throw string("Параметры не могут быть бесконечными");
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15)
        throw string("Деление на очень маленькое число");
    return (a0 - an * r) / denominator;
}

double geomProgressionSum4_1(double a0, double an, double r)
{
    if (r == 1.0)
        throw GeomProgressionERR();
    if (isnan(a0) || isnan(an) || isnan(r))
        throw GeomProgressionERR();
    if (isinf(a0) || isinf(an) || isinf(r))
        throw GeomProgressionERR();
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15)
        throw GeomProgressionERR();
    return (a0 - an * r) / denominator;
}

double geomProgressionSum4_2(double a0, double an, double r)
{
    if (r == 1.0)
        throw GeomProgressionERRwithParams(a0, an, r, "Знаменатель прогрессии не может быть равен 1");
    if (isnan(a0) || isnan(an) || isnan(r))
        throw GeomProgressionERRwithParams(a0, an, r, "Параметры не могут быть Nan");
    if (isinf(a0) || isinf(an) || isinf(r))
        throw GeomProgressionERRwithParams(a0, an, r, "Параметры не могут быть бесконечными");
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15)
        throw GeomProgressionERRwithParams(a0, an, r, "Деление на очень маленькое число");
    return (a0 - an * r) / denominator;
}

double geomProgressionSum4_3(double a0, double an, double r)
{
    if (r == 1.0)
        throw GeomProgressionStdERR(a0, an, r, "Знаменатель прогрессии не может быть равен 1");
    if (isnan(a0) || isnan(an) || isnan(r))
        throw GeomProgressionStdERR(a0, an, r, "Параметры не могут быть Nan");
    if (isinf(a0) || isinf(an) || isinf(r))
        throw GeomProgressionStdERR(a0, an, r, "Параметры не могут быть бесконечными");
    double denominator = 1.0 - r;
    if (abs(denominator) < 1e-15)
        throw GeomProgressionStdERR(a0, an, r, "Деление на очень маленькое число");
    return (a0 - an * r) / denominator;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    
    struct Test
    {
        double a0;
        double an;
        double r;
        string description;
    };
    
    Test tests[] = {
        {1.0, 8.0, 0.5, "Нормальный случай"},
        {2.0, 32.0, 2.0, "Нормальный случай с r=2"},
        {1.0, 1.0, 1.0, "r = 1 (ошибка)"},
        {1.0, 2.0, 1.0 + 1e-16, "r почти 1 (ошибка деления)"},
        {NAN, 2.0, 0.5, "a0 = Nan (ошибка)"},
        {1.0, 2.0, INFINITY, "r = INF (ошибка)"}
    };
    
    for (int var = 1; var <= 4; ++var)
    {
        cout << ">>Тест" << var << "." << endl;
        
        for (const auto& test : tests)
        {
            cout << "Тест: " << test.description << " (a0 = " << test.a0 << ", an = " << test.an << ", r = " << test.r << ")" << endl;
            
            try
            {
                double res;
                switch (var)
                {
                case 1:
                    res = geomProgressionSum1(test.a0, test.an, test.r);
                    cout << ">Результат: " << res << endl;
                    break;
                case 2:
                    res = geomProgressionSum2(test.a0, test.an, test.r);
                    if (isnan(res))
                        cout << "Ошибка: возвращено Nan." << endl;
                    else
                        cout << ">Результат: " << res << endl;
                    break;
                case 3:
                    res = geomProgressionSum3(test.a0, test.an, test.r);
                    cout << ">Результат: " << res << endl;
                    break;
                //Тест вариантов с собственными исключениями
                case 4:
                    cout << "[Вариант 4.1]" << endl;
                    try
                    {
                        res = geomProgressionSum4_1(test.a0, test.an, test.r);
                        cout << ">Результат: " << res << endl;
                    }
                    catch (const GeomProgressionERR&)
                    {
                        cout << "Поймана ошибка Геометрической прогрессии." << endl;
                    }
                    
                    cout << "[Вариант 4.2]" << endl;
                    try 
                    {
                        res = geomProgressionSum4_2(test.a0, test.an, test.r);
                        cout << ">Результат: " << res << endl;
                    }
                    catch (const GeomProgressionERRwithParams& e)
                    {
                        cout << "Поймана ошибка c параметром: " << e.message << " (a0 = " << e.a0 << ", an = " << e.an << ", r = " << e.r << ")" << endl;
                    }
                    
                    cout << "[Вариант 4.3]" << endl;
                    try
                    {
                        res = geomProgressionSum4_3(test.a0, test.an, test.r);
                        cout << ">Результат: " << res << endl;
                    }
                    catch (const GeomProgressionStdERR& e)
                    {
                        cout << "Поймана ошибка std: " << e.what() << " (a0 = " << e.a0 << ", an = " << e.an << ", r = " << e.r << ")" << endl;
                    }
                    break;
                }
            }
            catch (const char* e) 
            {
                cout << "Поймано исключение типа const char*: " << e << endl;
            }
            catch (const string& e)
            {
                cout << "Поймано исключение типа string: " << e << endl;
            }
            catch (const GeomProgressionERR&)
            {
                cout << "Поймана обычная ошибка" << endl;
            }
            catch (const GeomProgressionERRwithParams& e)
            {
                cout << "Поймана ошибка с параметрами: " << e.message << " (a0 = " << e.a0 << ", an = " << e.an << ", r = " << e.r << ")" << endl;
            }
            catch (const GeomProgressionStdERR& e)
            {
                cout << "Поймана ошибка std: " << e.what() << " (a0 = " << e.a0 << ", an = " << e.an << ", r = " << e.r << ")" << endl;
            }
            catch (const exception& e)
            {
                cout << "Поймано исключение: " << e.what() << endl;
            }
            catch (...)
            {
                cout << "Поймано неизвестное исключение" << endl;
            }
        }
    }
    
    cout << ">>Демонстрация корректных вычислений. " << endl;
    try
    {
        double a0 = 1.0, an = 8.0, r = 0.5;
        double expected = (a0 - an * r) / (1 - r);
        
        double res1 = geomProgressionSum1(a0, an, r);
        double res2 = geomProgressionSum2(a0, an, r);
        double res3 = geomProgressionSum3(a0, an, r);
        double res4_1 = geomProgressionSum4_1(a0, an, r);
        double res4_2 = geomProgressionSum4_2(a0, an, r);
        double res4_3 = geomProgressionSum4_3(a0, an, r);
        
        cout << "Геометрическая прогрессия: a0=" << a0 << ", an=" << an << ", r=" << r << endl;
        cout << "Формула: Sn = (a0 - an*r)/(1-r) = (" << a0 << " - " << an << "*" << r << ")/(1-" << r << ")" << endl;
        cout << "Ожидаемый результат: " << expected << endl;
        cout << "Все варианты функций дают одинаковый результат: " << res1 << endl;
        
        if (res1 == res2 && res2 == res3 && res3 == res4_1 && res4_1 == res4_2 && res4_2 == res4_3)
            cout << "Все функции работают правильно!" << endl;
        else
            cout << "Обнаружено несхождение в результатх!" << endl;
    }
    catch (...)
    {
        cout << "Неожиданная ошибка при нормальных значениях!" << endl;
    }
    return 0;
}
