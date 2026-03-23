package ru.guu.lab6.Component;

import lombok.extern.log4j.Log4j2;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.ApplicationContext;
import org.springframework.stereotype.Service;
import ru.guu.lab6.LcmMethods.ILcmCalculator;

@Service //Сервисный компонент
@Log4j2 //Логирование
public class LcmCalculatorComponent
{
//Выбор нужно метода для расчётов
    @Value("${lcm.method}")
    private String methodName;

    private ILcmCalculator lcmCalculator;

    @Autowired
    public void setLcmCalculator(ApplicationContext context)
    {
        this.lcmCalculator = (ILcmCalculator) context.getBean(methodName);
        log.info("Инициализирован метод вычисления НОК: {}", lcmCalculator.getMethodName());
    }

    public String getCurrentMethodName()
    {
        return lcmCalculator.getMethodName();
    }

    public int calculate(int a, int b)
    {
        return lcmCalculator.calculate(a, b);
    }
}
