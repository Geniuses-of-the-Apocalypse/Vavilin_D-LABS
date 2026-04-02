package main.guu.ru.lab8.model;

//Ребро графа
public class Edge {
    private final String from;
    private final String to;
    private final double weight;
    private final boolean availableForCar;
    private final boolean availableForPedestrian;
    private final boolean availableForPublicTransport;

    public Edge(String from, String to, double weight,
                boolean availableForCar,
                boolean availableForPedestrian,
                boolean availableForPublicTransport) {
        this.from = from;
        this.to = to;
        this.weight = weight;
        this.availableForCar = availableForCar;
        this.availableForPedestrian = availableForPedestrian;
        this.availableForPublicTransport = availableForPublicTransport;
    }

    public String getFrom() { return from; }
    public String getTo() { return to; }
    public double getWeight() { return weight; }

    public boolean isAvailableForCar() { return availableForCar; }
    public boolean isAvailableForPedestrian() { return availableForPedestrian; }
    public boolean isAvailableForPublicTransport() { return availableForPublicTransport; }

    public boolean isAvailableForTransport(TransportType type) {
        return switch (type) {
            case CAR -> availableForCar;
            case PEDESTRIAN -> availableForPedestrian;
            case PUBLIC_TRANSPORT -> availableForPublicTransport;
        };
    }

    @Override
    public String toString() {
        return String.format("%s -> %s (%.1f)", from, to, weight);
    }
}
