package main.guu.ru.lab7.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.ApplicationContext;
import org.springframework.stereotype.Service;
import java.util.List;

@Service
public class PathFinderBean {
    @Value("${use.decorators:}")
    private String useDecorators;

    private PathFinder pathFinder;

    @Autowired
    public void setPathFinder(ApplicationContext context) {
        if (useDecorators == null || useDecorators.isEmpty()) {
            pathFinder = (PathFinder) context.getBean("minVertex");
            return;
        }

        String[] beanNameList = useDecorators.split(",");
        pathFinder = (PathFinder) context.getBean("basePathFinder");

        for (String beanName : beanNameList) {
            PathFinder decorator = (PathFinder) context.getBean(beanName.trim());
            // Используем reflection для установки декорируемого объекта
            try {
                java.lang.reflect.Field field = decorator.getClass().getDeclaredField("pathFinder");
                field.setAccessible(true);
                field.set(decorator, pathFinder);
                pathFinder = decorator;
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public List<String> findPath(String start, String end) {
        return pathFinder.findPath(start, end);
    }
}
