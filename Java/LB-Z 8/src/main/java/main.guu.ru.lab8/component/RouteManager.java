package main.guu.ru.lab8.component;

import lombok.extern.log4j.Log4j2;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationEventPublisher;
import org.springframework.context.ApplicationEventPublisherAware;
import org.springframework.stereotype.Service;
import main.guu.ru.lab8.events.RouteChangeEvent;

//Управление маршрутом
@Service
@Log4j2
public class RouteManager implements ApplicationEventPublisherAware {
    private ApplicationEventPublisher applicationEventPublisher;
    private String startPoint;
    private String endPoint;

    @Override
    public void setApplicationEventPublisher(ApplicationEventPublisher applicationEventPublisher) {
        this.applicationEventPublisher = applicationEventPublisher;
    }

    public void setRoute(String startPoint, String endPoint) {
        this.startPoint = startPoint;
        this.endPoint = endPoint;
        RouteChangeEvent event = new RouteChangeEvent(this, startPoint, endPoint);
        applicationEventPublisher.publishEvent(event);
        log.info("Маршрут изменён: {} -> {}", startPoint, endPoint);
    }

    public String getStartPoint() { return startPoint; }
    public String getEndPoint() { return endPoint; }
}
