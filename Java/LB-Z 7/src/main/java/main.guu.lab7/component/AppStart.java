package main.guu.ru.lab7.component;

import lombok.extern.log4j.Log4j2;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import main.guu.ru.lab7.service.PathFinderBean;
import java.util.List;

@Service
@Log4j2
public class AppStart {
    @Value("${graph.start}")
    private String startVertex;

    @Value("${graph.end}")
    private String endVertex;

    @Autowired
    private PathFinderBean pathFinderBean;

    @Autowired
    private Graph graph;

    public void start() {
        // Инициализируем граф
        graph.initDefaultGraph();

        log.info("=== Поиск кратчайшего пути в графе ===");
        log.info("Начальная вершина: " + startVertex);
        log.info("Конечная вершина: " + endVertex);

        List<String> path = pathFinderBean.findPath(startVertex, endVertex);

        if (path.isEmpty()) {
            log.info("Путь не найден!");
        } else {
            log.info("Найденный путь: " + path);
            log.info("Длина пути (количество вершин): " + path.size());

            // Вычисляем общий вес пути
            int totalWeight = calculatePathWeight(path);
            if (totalWeight > 0) {
                log.info("Общий вес пути: " + totalWeight);
            }
        }
    }

    private int calculatePathWeight(List<String> path) {
        int totalWeight = 0;
        for (int i = 0; i < path.size() - 1; i++) {
            Integer weight = graph.getWeight(path.get(i), path.get(i + 1));
            if (weight != null) {
                totalWeight += weight;
            } else {
                totalWeight += 1; // Если вес не задан, считаем за 1
            }
        }
        return totalWeight;
    }
}
