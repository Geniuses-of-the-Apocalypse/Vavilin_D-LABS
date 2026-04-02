package main.guu.ru.lab8.events;

import org.springframework.context.ApplicationEvent;

//Посылка от RouteManager к подписчикам(евентлистенерам) - передаёт данные подписчикам при изменении
public class RouteChangeEvent extends ApplicationEvent {
    private final String startPoint;
    private final String endPoint;

    public RouteChangeEvent(Object source, String startPoint, String endPoint) {
        super(source);
        this.startPoint = startPoint;
        this.endPoint = endPoint;
    }

    public String getStartPoint() {
        return startPoint;
    }

    public String getEndPoint() {
        return endPoint;
    }
}