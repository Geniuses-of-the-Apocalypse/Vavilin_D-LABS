package ru.guu.lab6.LcmMethods;

import org.springframework.stereotype.Service;

@Service("gcdBased")
public class GcdBasedLcm implements ILcmCalculator
{

    @Override
    public int calculate(int a, int b)
    {
        if (a == 0 || b == 0)
            return 0;
        return Math.abs(a * b) / gcd(a, b);
    }

    //НОК через Евклида
    private int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return Math.abs(a);
    }

    @Override
    public String getMethodName()
    {
        return "НОК через НОД (алгоритм Евклида)";
    }
}
