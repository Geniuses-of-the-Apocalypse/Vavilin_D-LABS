package main.guu.ru.lab10;

import javax.validation.*;
import java.util.*;
import org.hibernate.validator.messageinterpolation.ParameterMessageInterpolator;

public class Lab10Start {
    public static void main(String[] args) {

        ValidatorFactory factory = Validation.byDefaultProvider().configure().messageInterpolator(new ParameterMessageInterpolator()).buildValidatorFactory();
        Validator validator = factory.getValidator();

        //Вагоны
        Wagon w1 = new Wagon("001", 0.5);
        Wagon w2 = new Wagon("002", 1.0);
        Wagon w3 = new Wagon("003", 0.8);

        //Первый тест: правильный Состав
        Train train1 = new Train("T1", "Поезд-1", 2.3);
        train1.addWagon(w1);
        train1.addWagon(w2);
        train1.addWagon(w3);

        System.out.println("ТЕСТ 1 - Корректный состав:");
        printViolations(validator.validate(train1));

        //Тест 2: Неправильный Состав (сумма 2.3, указано 5.0)
        Train train2 = new Train("T2", "Поезд-2", 5.0);
        train2.addWagon(w1);
        train2.addWagon(w2);
        train2.addWagon(w3);

        System.out.println("\nТЕСТ 2 - Некорректный состав:");
        printViolations(validator.validate(train2));

        //Тест 3: пустой Состав
        Train train3 = new Train("T3", "Поезд-3", 0.0);

        System.out.println("\nТЕСТ 3 - Пустой состав:");
        printViolations(validator.validate(train3));

        factory.close();
    }

    static void printViolations(Set<? extends ConstraintViolation<?>> violations) {
        if (violations.isEmpty()) {
            System.out.println("  >>ВАЛИДАЦИЯ ПРОЙДЕНА.");
        } else {
            System.out.println("  >>НАЙДЕНЫ НАРУШЕНИЯ:");
            for (ConstraintViolation<?> v : violations) {
                System.out.println("     - " + v.getMessage());
            }
        }
    }
}