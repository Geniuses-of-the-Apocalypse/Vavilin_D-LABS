package ru.guu.lab6.LcmMethods;

import org.springframework.stereotype.Service;

//НОК методом перебора кратных
@Service("iterationBased")
public class IterationBasedLcm implements ILcmCalculator {

    //Перебор кратных
    @Override
    public int calculate(int a, int b) {
        if (a == 0 || b == 0) {
            return 0;
        }

        a = Math.abs(a);
        b = Math.abs(b);

        int max = Math.max(a, b);
        int lcm = max;

        while (true) {
            if (lcm % a == 0 && lcm % b == 0) {
                break;
            }
            lcm += max;
        }

        return lcm;
    }

    @Override
    public String getMethodName() {
        return "НОК методом перебора кратных";
    }
}
