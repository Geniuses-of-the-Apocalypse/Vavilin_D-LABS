package ru.guu.lab6.LcmMethods;

//Интерфейс для стратегий вычисления НОК
public interface ILcmCalculator
{
    int calculate(int a, int b);
    String getMethodName();
}
