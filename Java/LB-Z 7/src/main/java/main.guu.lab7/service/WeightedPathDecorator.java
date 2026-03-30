package main.guu.ru.lab7.service;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;
import main.guu.ru.lab7.component.Graph;
import java.util.*;

@Service("weighted")
public class WeightedPathDecorator implements PathFinder {
    private final PathFinder pathFinder;
    private final Graph graph;

    public WeightedPathDecorator(@Qualifier("basePathFinder") PathFinder pathFinder, Graph graph) {
        this.pathFinder = pathFinder;
        this.graph = graph;
    }

    @Override
    public List<String> findPath(String start, String end) {
        List<String> basePath = pathFinder.findPath(start, end);

        if (start.equals(end)) {
            return List.of(start);
        }

        Map<String, Integer> distances = new HashMap<>();
        Map<String, String> previous = new HashMap<>();
        Set<String> visited = new HashSet<>();
        PriorityQueue<VertexDistance> pq = new PriorityQueue<>(Comparator.comparingInt(vd -> vd.distance));

        distances.put(start, 0);
        pq.offer(new VertexDistance(start, 0));

        while (!pq.isEmpty()) {
            VertexDistance current = pq.poll();
            String currentVertex = current.vertex;

            if (currentVertex.equals(end)) break;

            if (current.distance > distances.getOrDefault(currentVertex, Integer.MAX_VALUE)) {
                continue;
            }

            for (String neighbor : graph.getNeighbors(currentVertex)) {
                int weight = graph.getWeight(currentVertex, neighbor);
                if (weight == 0 && !graph.hasWeight(currentVertex, neighbor)) {
                    weight = 1;
                }

                int newDist = distances.get(currentVertex) + weight;
                if (newDist < distances.getOrDefault(neighbor, Integer.MAX_VALUE)) {
                    distances.put(neighbor, newDist);
                    previous.put(neighbor, currentVertex);
                    pq.offer(new VertexDistance(neighbor, newDist));
                }
            }
        }

        List<String> path = new ArrayList<>();
        String current = end;
        while (previous.containsKey(current)) {
            path.add(0, current);
            current = previous.get(current);
        }

        if (path.isEmpty() && !start.equals(end)) {
            return new ArrayList<>();
        }

        path.add(0, start);
        return path;
    }

    private static class VertexDistance {
        String vertex;
        int distance;

        VertexDistance(String vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }
    }
}
