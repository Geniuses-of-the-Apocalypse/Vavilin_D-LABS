package ru.guu.lab6.Component;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import java.util.ArrayList;
import java.util.List;

@Service  //Сервисный компонент
public class AppStart {
    private static final Logger log = LoggerFactory.getLogger(AppStart.class);

    //Чтение количества тестовых пар из конфигурации
    @Value("${test.pairs.count:5}")
    private int testPairsCount;

    //Компонент для вычисления НОК
    @Autowired
    private LcmCalculatorComponent lcmCalculator;

    //Список для хранения тестовых пар чисел
    private List<NumberPair> testPairs = new ArrayList<>();

    //Генерация случайных пар чисел
    public void initTestPairs() {
        log.info(" Инициализация тестовых пар, количество: {}", testPairsCount);

        //Генерим указанное количество пар
        for (int i = 0; i < testPairsCount; i++) {
            // Генерируем случайные числа от 1 до 1000
            int a = (int) (Math.random() * 1000) + 1;
            int b = (int) (Math.random() * 1000) + 1;

            //Закидываем в список
            testPairs.add(new NumberPair(a, b));
        }

        log.info(" Создано {} тестовых пар", testPairs.size());
    }

    //НОК для всех пар
    public void start() {
        //Оформляем
        log.info("============================================================");
        log.info("            ТЕСТИРОВАНИЕ МЕТОДОВ ВЫЧИСЛЕНИЯ НОК             ");
        log.info("============================================================");
        log.info(" Используемый метод: {}", lcmCalculator.getCurrentMethodName());
        log.info("");

        //Тестовые пары
        for (int i = 0; i < testPairs.size(); i++) {
            NumberPair pair = testPairs.get(i);  // Получаем текущую пару

            //Расчёт времени
            long startTime = System.nanoTime();

            //НОК
            int result = lcmCalculator.calculate(pair.getA(), pair.getB());

            //Время окончания
            long endTime = System.nanoTime();

            //В наносекундах
            long timeNano = endTime - startTime;
            long timeMicro = timeNano / 1000;

            //Вывод
            log.info(" Пара #{}{}: НОК({}, {}) = {} |  Время: {} мкс ({} нс)",
                    i + 1,
                    i + 1 < 10 ? " " : "",
                    pair.getA(), pair.getB(),
                    result,
                    timeMicro,
                    timeNano);
        }

        log.info("");
        log.info("============================================================");
        log.info("                   ТЕСТИРОВАНИЕ ЗАВЕРШЕНО                   ");
        log.info("============================================================");
    }

    //Хранение пар чисел
    private static class NumberPair {
        private final int a;  // final - значение нельзя изменить после создания
        private final int b;

        //Конструкторы и геттеры
        public NumberPair(int a, int b) {
            this.a = a;
            this.b = b;
        }

        public int getA() { return a; }
        public int getB() { return b; }
    }
}
