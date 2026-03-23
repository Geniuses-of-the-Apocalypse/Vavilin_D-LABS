package ru.guu.lab6;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import ru.guu.lab6.Component.LcmCalculatorComponent;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class LcmCalculatorTest
{

    @Autowired
    private LcmCalculatorComponent lcmCalculator;

    @Test
    void testLcmCalculation()
    {
        assertEquals(12, lcmCalculator.calculate(4, 6));
        assertEquals(15, lcmCalculator.calculate(3, 5));
        assertEquals(24, lcmCalculator.calculate(8, 12));
        assertEquals(0, lcmCalculator.calculate(0, 5));
        assertEquals(0, lcmCalculator.calculate(7, 0));
    }

    @Test
    void testLcmWithLargeNumbers()
    {
        assertTrue(lcmCalculator.calculate(100, 200) > 0);
        assertEquals(1000, lcmCalculator.calculate(100, 125));
    }
}
