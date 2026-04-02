//Графы - Декоратор (Decorator).
//================================

package main.guu.ru.lab7;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;
import main.guu.ru.lab7.component.AppStart;

@SpringBootApplication
public class Lab7Application {
    private static ConfigurableApplicationContext context;

    public static void main(String[] args) {
        SpringApplication app = new SpringApplication(Lab7Application.class);
        app.setBanner((environment, sourceClass, out) -> out.print("┏━╸┏━┓┏━┓┏━┓╻ ╻   ┏━┓┏━┓╺┳╸╻ ╻   ┏━╸╻┏┓╻╺┳┓┏━╸┏━┓\n" +
                "┃╺┓┣┳┛┣━┫┣━┛┣━┫   ┣━┛┣━┫ ┃ ┣━┫   ┣╸ ┃┃┗┫ ┃┃┣╸ ┣┳┛\n" +
                "┗━┛╹┗╸╹ ╹╹  ╹ ╹   ╹  ╹ ╹ ╹ ╹ ╹   ╹  ╹╹ ╹╺┻┛┗━╸╹┗╸\n".toUpperCase()));
        context = app.run(args);
        AppStart appStart = context.getBean(AppStart.class);
        appStart.start();
    }
}
