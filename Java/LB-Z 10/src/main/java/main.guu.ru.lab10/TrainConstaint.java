package main.guu.ru.lab10;

import javax.validation.Constraint;
import javax.validation.Payload;
import java.lang.annotation.*;

//Аннотация
@Target({ElementType.TYPE})
@Retention(RetentionPolicy.RUNTIME)
@Constraint(validatedBy = TrainValidator.class)
public @interface TrainConstraint {
    String message() default "Длина состава не равна сумме длин вагонов.";
    Class<?>[] groups() default {};
    Class<? extends Payload>[] payload() default {};
}
