package main.guu.ru.lab10;

import javax.validation.ConstraintValidator;
import javax.validation.ConstraintValidatorContext;

//Валидатор для Состава
public class TrainValidator implements ConstraintValidator<TrainConstraint, Train> {

    @Override
    public boolean isValid(Train train, ConstraintValidatorContext context) {
        if (train == null || train.getDlinaVUslovnihVagonah() == null) {
            return true;
        }

        double zadannaya = train.getDlinaVUslovnihVagonah();
        double fakticheskaya = train.getFakticheskayaDlina();

        return Math.abs(zadannaya - fakticheskaya) < 0.0001;
    }
}
