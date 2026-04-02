package main.guu.ru.lab8;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;
import main.guu.ru.lab8.component.AppStart;

@SpringBootApplication
public class Lab8Application {

    private static ConfigurableApplicationContext context;

    public static void main(String[] args) {
        SpringApplication app = new SpringApplication(Lab8Application.class);

        app.setBanner((environment, sourceClass, out) -> out.print("┏━╸┏━┓┏━┓┏━┓╻ ╻   ┏━┓┏━┓╺┳╸╻ ╻   ┏━╸╻┏┓╻╺┳┓┏━╸┏━┓   ┏━┓\n" +
                "┃╺┓┣┳┛┣━┫┣━┛┣━┫   ┣━┛┣━┫ ┃ ┣━┫   ┣╸ ┃┃┗┫ ┃┃┣╸ ┣┳┛   ┏━┛\n" +
                "┗━┛╹┗╸╹ ╹╹  ╹ ╹   ╹  ╹ ╹ ╹ ╹ ╹   ╹  ╹╹ ╹╺┻┛┗━╸╹┗╸   ┗━╸\n".toUpperCase()));

        context = app.run(args);

        //Запуск через бин AppStart
        AppStart appStart = context.getBean(AppStart.class);
        appStart.start();
    }
}
