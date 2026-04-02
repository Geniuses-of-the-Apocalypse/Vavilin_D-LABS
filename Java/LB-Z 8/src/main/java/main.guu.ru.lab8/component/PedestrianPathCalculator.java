package main.guu.ru.lab8.component;

import lombok.extern.log4j.Log4j2;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.event.EventListener;
import org.springframework.stereotype.Service;
import main.guu.ru.lab8.events.RouteChangeEvent;
import main.guu.ru.lab8.model.TransportType;

import java.util.List;

@Service
@Log4j2
public class PedestrianPathCalculator {
    @Autowired
    private GraphManager graphManager;

    private List<String> currentPath;
    private double currentDistance;

    @EventListener
    public void onRouteChange(RouteChangeEvent event) {
        String start = event.getStartPoint();
        String end = event.getEndPoint();

        if (start == null || end == null) {
            log.warn("Начальная или конечная точка не задана");
            return;
        }

        currentPath = graphManager.getPath(start, end, TransportType.PEDESTRIAN);
        currentDistance = calculateDistance();

        log.info("Пешеход: путь пересчитан");
    }

    private double calculateDistance() {
        if (currentPath == null || currentPath.size() < 2) return 0;

        double total = 0;
        for (int i = 0; i < currentPath.size() - 1; i++) {
            String from = currentPath.get(i);
            String to = currentPath.get(i + 1);

            for (var edge : graphManager.getEdgesFrom(from)) {
                if (edge.getTo().equals(to) && edge.isAvailableForPedestrian()) {
                    total += edge.getWeight();
                    break;
                }
            }
        }
        return total;
    }

    public List<String> getPath() { return currentPath; }
    public double getDistance() { return currentDistance; }

    @Override
    public String toString() {
        return "Пешеход{путь=" + currentPath + ", расстояние=" + currentDistance + '}';
    }
}