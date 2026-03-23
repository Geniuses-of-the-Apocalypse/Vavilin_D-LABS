package ru.guu.lab6.Interceptors;

import lombok.extern.log4j.Log4j2;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.stereotype.Component;

@Component //компонент Spring
@Aspect
@Log4j2
public class LcmProfileInterceptor
{

    @Pointcut("within(ru.rut_miit.lab1cdispring.Component.AppStart)")
    public void lcmMethods() {}

    //Измеряет время всех методов в AppStart
    @Around("lcmMethods()")
    public Object logExecutionTime(ProceedingJoinPoint joinPoint) throws Throwable
    {
        long start = System.currentTimeMillis();
        Object proceed = joinPoint.proceed();
        long executionTime = System.currentTimeMillis() - start;

        log.info("Метод: {} - время выполнения: {} мс",
                joinPoint.getSignature().getName(), executionTime);

        return proceed;
    }
}
