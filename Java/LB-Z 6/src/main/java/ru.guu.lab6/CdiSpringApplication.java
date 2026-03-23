package ru.guu.lab6;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;
import ru.guu.lab6.Component.AppStart;

@SpringBootApplication //(конфигурация, авто Spring, скан компоентов в текущий пак)
public class CdiSpringApplication {

    //Запуск
    public static void main(String[] args) {
        try {
            SpringApplication app = new SpringApplication(CdiSpringApplication.class);

            ConfigurableApplicationContext context = app.run(args);
            AppStart appStart = context.getBean(AppStart.class);
            appStart.initTestPairs();
            appStart.start();

        } catch (Exception e) {
            //Для ошибки
            System.err.println("Ошибка при запуске приложения:");
            e.printStackTrace();
        }
    }
}
