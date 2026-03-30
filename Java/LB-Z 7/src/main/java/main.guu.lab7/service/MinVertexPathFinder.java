package main.guu.ru.lab7.service;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;
import main.guu.ru.lab7.component.Graph;
import java.util.*;

@Service("minVertex")
public class MinVertexPathFinder implements PathFinder {
    private final PathFinder pathFinder;
    private final Graph graph;

    public MinVertexPathFinder(@Qualifier("basePathFinder") PathFinder pathFinder, Graph graph) {
        this.pathFinder = pathFinder;
        this.graph = graph;
    }

    @Override
    public List<String> findPath(String start, String end) {
        // Сначала применяем декорируемый метод (если есть)
        List<String> basePath = pathFinder.findPath(start, end);

        if (start.equals(end)) {
            return List.of(start);
        }

        Queue<List<String>> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        List<String> startPath = new ArrayList<>();
        startPath.add(start);
        queue.offer(startPath);
        visited.add(start);

        while (!queue.isEmpty()) {
            List<String> currentPath = queue.poll();
            String lastNode = currentPath.get(currentPath.size() - 1);

            for (String neighbor : graph.getNeighbors(lastNode)) {
                if (neighbor.equals(end)) {
                    List<String> newPath = new ArrayList<>(currentPath);
                    newPath.add(neighbor);
                    return newPath;
                }

                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    List<String> newPath = new ArrayList<>(currentPath);
                    newPath.add(neighbor);
                    queue.offer(newPath);
                }
            }
        }

        return new ArrayList<>();
    }
}
