package main.guu.ru.lab7.service;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import java.util.*;

@Service("throughVertices")
public class ThroughVerticesDecorator implements PathFinder {
    private final PathFinder pathFinder;

    @Value("${required.vertices:}")
    private String requiredVerticesStr;

    public ThroughVerticesDecorator(@Qualifier("basePathFinder") PathFinder pathFinder) {
        this.pathFinder = pathFinder;
    }

    public List<String> getRequiredVertices() {
        if (requiredVerticesStr == null || requiredVerticesStr.isEmpty()) {
            return new ArrayList<>();
        }
        return Arrays.asList(requiredVerticesStr.split(","));
    }

    public void setRequiredVertices(List<String> vertices) {
        this.requiredVerticesStr = String.join(",", vertices);
    }

    @Override
    public List<String> findPath(String start, String end) {
        List<String> basePath = pathFinder.findPath(start, end);
        List<String> requiredVertices = getRequiredVertices();

        if (requiredVertices.isEmpty()) {
            return basePath;
        }

        List<String> fullPath = new ArrayList<>();
        String currentStart = start;

        List<String> points = new ArrayList<>();
        points.add(start);
        points.addAll(requiredVertices);
        points.add(end);

        for (int i = 0; i < points.size() - 1; i++) {
            // Создаем временный PathFinder для поиска между точками
            List<String> segment = findSegment(currentStart, points.get(i + 1));
            if (segment.isEmpty()) {
                return new ArrayList<>();
            }

            if (i == 0) {
                fullPath.addAll(segment);
            } else {
                fullPath.addAll(segment.subList(1, segment.size()));
            }
            currentStart = points.get(i + 1);
        }

        return fullPath;
    }

    private List<String> findSegment(String start, String end) {
        return pathFinder.findPath(start, end);
    }
}
