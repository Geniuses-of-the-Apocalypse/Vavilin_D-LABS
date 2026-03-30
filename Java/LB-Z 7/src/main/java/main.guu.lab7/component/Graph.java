package main.guu.ru.lab7.component;

import org.springframework.stereotype.Component;
import java.util.*;

@Component
public class Graph {
    private Map<String, List<String>> adjacencyList = new HashMap<>();
    private Map<String, Map<String, Integer>> weights = new HashMap<>();
    private Set<String> vertices = new HashSet<>();

    public void addVertex(String vertex) {
        adjacencyList.putIfAbsent(vertex, new ArrayList<>());
        weights.putIfAbsent(vertex, new HashMap<>());
        vertices.add(vertex);
    }

    public void addEdge(String from, String to) {
        addVertex(from);
        addVertex(to);
        adjacencyList.get(from).add(to);
    }

    public void addWeightedEdge(String from, String to, int weight) {
        addEdge(from, to);
        weights.get(from).put(to, weight);
    }

    public List<String> getNeighbors(String vertex) {
        return adjacencyList.getOrDefault(vertex, new ArrayList<>());
    }

    public Integer getWeight(String from, String to) {
        return weights.getOrDefault(from, new HashMap<>()).get(to);
    }

    public boolean hasWeight(String from, String to) {
        return weights.getOrDefault(from, new HashMap<>()).containsKey(to);
    }

    public Set<String> getAllVertices() {
        return new HashSet<>(vertices);
    }

    // Инициализация графа с данными
    public void initDefaultGraph() {
        // Добавляем ребра
        addEdge("A", "B");
        addEdge("A", "C");
        addEdge("B", "D");
        addEdge("C", "D");
        addEdge("C", "E");
        addEdge("D", "F");
        addEdge("E", "F");
        addEdge("B", "E");

        // Добавляем веса
        addWeightedEdge("A", "B", 1);
        addWeightedEdge("A", "C", 4);
        addWeightedEdge("B", "D", 2);
        addWeightedEdge("C", "D", 1);
        addWeightedEdge("C", "E", 3);
        addWeightedEdge("D", "F", 1);
        addWeightedEdge("E", "F", 2);
        addWeightedEdge("B", "E", 5);
    }
}
