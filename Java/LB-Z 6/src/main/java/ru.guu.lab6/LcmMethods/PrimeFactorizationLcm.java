package ru.guu.lab6.LcmMethods;

import org.springframework.stereotype.Service;
import java.util.HashMap;
import java.util.Map;

//НОК через разложение на простые множители
@Service("primeFactorization")
public class PrimeFactorizationLcm implements ILcmCalculator {

    @Override
    public int calculate(int a, int b) {
        if (a == 0 || b == 0) {
            return 0;
        }

        Map<Integer, Integer> primeFactorsA = getPrimeFactors(Math.abs(a));
        Map<Integer, Integer> primeFactorsB = getPrimeFactors(Math.abs(b));

        Map<Integer, Integer> lcmFactors = new HashMap<>(primeFactorsA);

        for (Map.Entry<Integer, Integer> entry : primeFactorsB.entrySet()) {
            int prime = entry.getKey();
            int exponentB = entry.getValue();
            int exponentA = lcmFactors.getOrDefault(prime, 0);
            lcmFactors.put(prime, Math.max(exponentA, exponentB));
        }

        int result = 1;
        for (Map.Entry<Integer, Integer> entry : lcmFactors.entrySet()) {
            result *= Math.pow(entry.getKey(), entry.getValue());
        }

        return result;
    }

    //Разложение числа на простые мнодители
    private Map<Integer, Integer> getPrimeFactors(int n) {
        Map<Integer, Integer> factors = new HashMap<>();
        int num = n;

        for (int i = 2; i <= num / i; i++) {
            while (num % i == 0) {
                factors.put(i, factors.getOrDefault(i, 0) + 1);
                num /= i;
            }
        }

        if (num > 1) {
            factors.put(num, factors.getOrDefault(num, 0) + 1);
        }

        return factors;
    }

    @Override
    public String getMethodName() {
        return "НОК через разложение на простые множители";
    }
}
