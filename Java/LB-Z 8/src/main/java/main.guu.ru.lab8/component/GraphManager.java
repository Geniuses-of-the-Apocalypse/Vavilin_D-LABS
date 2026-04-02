package main.guu.ru.lab8.component;

import org.springframework.stereotype.Service;
import main.guu.ru.lab8.model.Edge;
import main.guu.ru.lab8.model.TransportType;
import java.util.*;

//Хранитель графа
@Service
public class GraphManager {
    private final Map<String, List<Edge>> adjacencyList = new HashMap<>();
    private final Set<String> vertices = new HashSet<>();

    public void addEdge(Edge edge) {
        adjacencyList.computeIfAbsent(edge.getFrom(), k -> new ArrayList<>()).add(edge);
        vertices.add(edge.getFrom());
        vertices.add(edge.getTo());
    }

    public List<Edge> getEdgesFrom(String vertex) {
        return adjacencyList.getOrDefault(vertex, new ArrayList<>());
    }

    public Set<String> getVertices() {
        return vertices;
    }

    public Map<String, Double> dijkstra(String start, TransportType transportType) {
        Map<String, Double> distances = new HashMap<>();
        Map<String, String> previous = new HashMap<>();
        PriorityQueue<String> queue = new PriorityQueue<>(Comparator.comparingDouble(distances::get));

        for (String vertex : vertices) {
            distances.put(vertex, Double.POSITIVE_INFINITY);
        }
        distances.put(start, 0.0);
        queue.add(start);

        while (!queue.isEmpty()) {
            String current = queue.poll();
            double currentDist = distances.get(current);

            for (Edge edge : getEdgesFrom(current)) {
                if (!edge.isAvailableForTransport(transportType)) continue;

                String neighbor = edge.getTo();
                double newDist = currentDist + edge.getWeight();

                if (newDist < distances.get(neighbor)) {
                    distances.put(neighbor, newDist);
                    previous.put(neighbor, current);
                    queue.add(neighbor);
                }
            }
        }
        return distances;
    }

    public List<String> getPath(String start, String end, TransportType transportType) {
        Map<String, Double> distances = new HashMap<>();
        Map<String, String> previous = new HashMap<>();
        PriorityQueue<String> queue = new PriorityQueue<>(Comparator.comparingDouble(distances::get));

        for (String vertex : vertices) {
            distances.put(vertex, Double.POSITIVE_INFINITY);
        }
        distances.put(start, 0.0);
        queue.add(start);

        while (!queue.isEmpty()) {
            String current = queue.poll();
            if (current.equals(end)) break;

            for (Edge edge : getEdgesFrom(current)) {
                if (!edge.isAvailableForTransport(transportType)) {
                    continue;
                }

                String neighbor = edge.getTo();
                double newDist = distances.get(current) + edge.getWeight();

                if (newDist < distances.get(neighbor)) {
                    distances.put(neighbor, newDist);
                    previous.put(neighbor, current);
                    queue.add(neighbor);
                }
            }
        }

        List<String> path = new ArrayList<>();
        if (distances.get(end) == Double.POSITIVE_INFINITY) return path;

        for (String at = end; at != null; at = previous.get(at)) {
            path.add(at);
        }
        Collections.reverse(path);
        return path;
    }

    @Override
    public String toString() {
        return "{вершины=" + vertices + ", рёбра=" + adjacencyList + '}';
    }
}
