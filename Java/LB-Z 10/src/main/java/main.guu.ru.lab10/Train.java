package main.guu.ru.lab10;

import javax.validation.Valid;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;
import java.util.ArrayList;
import java.util.List;

//Состав
@TrainConstraint
public class Train {

    @NotNull(message = "ID состава обязателен")
    private String id;

    @NotNull(message = "Номер поезда обязателен")
    private String nomPoezd;

    @Min(value = 1, message = "Длина должна быть больше 0")
    private Double dlinaVUslovnihVagonah;

    @Valid
    private List<Wagon> spisokVagonov;

    public Train() {
        this.spisokVagonov = new ArrayList<>();
    }

    public Train(String id, String nomPoezd, Double dlina) {
        this();
        this.id = id;
        this.nomPoezd = nomPoezd;
        this.dlinaVUslovnihVagonah = dlina;
    }

    public double getFakticheskayaDlina() {
        return spisokVagonov.stream()
                .mapToDouble(w -> w.getUdl() != null ? w.getUdl() : 0)
                .sum();
    }

    public void addWagon(Wagon wagon) {
        spisokVagonov.add(wagon);
    }

    //Геттеры
    public Double getDlinaVUslovnihVagonah() { return dlinaVUslovnihVagonah; }
    public List<Wagon> getSpisokVagonov() { return spisokVagonov; }
    public String getId() { return id; }
    public String getNomPoezd() { return nomPoezd; }

    //Сеттеры
    public void setDlinaVUslovnihVagonah(Double dlina) { this.dlinaVUslovnihVagonah = dlina; }
    public void setSpisokVagonov(List<Wagon> list) { this.spisokVagonov = list; }
    public void setId(String id) { this.id = id; }
    public void setNomPoezd(String nom) { this.nomPoezd = nom; }
}
