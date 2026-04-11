package main.guu.ru.lab9;

import javax.validation.ConstraintViolation;
import javax.validation.Validation;
import javax.validation.Validator;
import javax.validation.ValidatorFactory;
import java.util.ArrayList;
import java.util.Date;
import java.util.Set;
import org.hibernate.validator.messageinterpolation.ParameterMessageInterpolator;

public class Lab9Start
{
    public static void main(String args[]) throws Exception {

        ValidatorFactory factory = Validation.byDefaultProvider().configure().messageInterpolator(new ParameterMessageInterpolator()).buildValidatorFactory();
        Validator validator = factory.getValidator();

        try {
            //Проверка класса Wagon
            System.out.println("=== Валидация Wagon (аннотации) ===");

            //Неправильный вагон
            Wagon wagon = new Wagon();
            wagon.setId("1");
            wagon.setNomVag("22222");
            wagon.setEsrNazV("33");
            wagon.setNpp(-50);
            wagon.setUdl(0.3);
            //Проверка
            Set<ConstraintViolation<Wagon>> violationsWagon = validator.validate(wagon);

            //Ошибки
            System.out.println("Найдены следующие нарушения: ");
            for (ConstraintViolation<Wagon> viol : violationsWagon) {
                System.out.println("Поле: " + viol.getPropertyPath() +
                        " значение: " + viol.getInvalidValue() +
                        "   " + viol.getMessage());
            }

            //Проверка класса PureWagon
            System.out.println("\n=== Валидация PureWagon (XML) ===");

            PureWagon pureWagon = new PureWagon();
            pureWagon.setId("1");
            pureWagon.setNomVag("22222");        //ошибка
            pureWagon.setEsrNazV("33");
            pureWagon.setNpp(-50);
            pureWagon.setUdl(0.3);

            Set<ConstraintViolation<PureWagon>> violationsPureWagon = validator.validate(pureWagon);

            System.out.println("Найдены следующие нарушения: ");
            for (ConstraintViolation<PureWagon> viol : violationsPureWagon) {
                System.out.println("Поле: " + viol.getPropertyPath() +
                        " значение: " + viol.getInvalidValue() +
                        "   " + viol.getMessage());
            }

            //Проверка класса TrainComposition
            System.out.println("\n=== Валидация TrainComposition (аннотации + XML) ===");

            //Неправильный состав
            TrainComposition composition = new TrainComposition();
            composition.setCompositionId("INVALID");
            composition.setTrainNumber("123");
            composition.setFormationDate(new Date());
            composition.setDepartureStation("");
            composition.setArrivalStation("");
            composition.setTotalLength(-100);
            composition.setTotalWeight(-50);
            composition.setWagons(new ArrayList<>());

            Set<ConstraintViolation<TrainComposition>> violationsComposition =
                    validator.validate(composition);

            System.out.println("Найдены следующие нарушения: ");
            for (ConstraintViolation<TrainComposition> viol : violationsComposition) {
                System.out.println("Поле: " + viol.getPropertyPath() +
                        " значение: " + viol.getInvalidValue() +
                        "   " + viol.getMessage());
            }

            //Проверка правильного Состава
            System.out.println("\n=== Валидация корректного TrainComposition ===");

            TrainComposition validComposition = new TrainComposition();
            validComposition.setCompositionId("AB-1234");
            validComposition.setTrainNumber("1234А");
            validComposition.setFormationDate(new Date(System.currentTimeMillis() - 86400000));
            validComposition.setDepartureStation("Москва-Пассажирская");
            validComposition.setArrivalStation("Санкт-Петербург-Главный");
            validComposition.setTotalLength(850);
            validComposition.setTotalWeight(5500);

            //Добавление правильного вагона
            ArrayList<Wagon> wagons = new ArrayList<>();
            Wagon validWagon = new Wagon();
            validWagon.setId("123");
            validWagon.setNomVag("1234567890");
            validWagon.setNpf("15546");
            validWagon.setNpp(5);
            validWagon.setUdl(1.5);
            wagons.add(validWagon);
            validComposition.setWagons(wagons);

            Set<ConstraintViolation<TrainComposition>> validViolations =
                    validator.validate(validComposition);

            if (validViolations.isEmpty()) {
                System.out.println("Состав прошел валидацию успешно!");
            } else {
                System.out.println("Найдены нарушения: ");
                for (ConstraintViolation<TrainComposition> viol : validViolations) {
                    System.out.println("Поле: " + viol.getPropertyPath() + " - " + viol.getMessage());
                }
            }

        } finally {
            //Закрытие фабрики
            factory.close();
        }
    }
}