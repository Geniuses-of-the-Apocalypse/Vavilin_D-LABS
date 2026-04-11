package main.guu.ru.lab9;

import javax.validation.Valid;
import javax.validation.constraints.*;
import java.util.Date;
import java.util.List;

//Класс Состав с аннотациями
public class TrainComposition {

    //Аннотации
    @NotNull(message = "Идентификатор состава должен быть задан")
    @Pattern(regexp = "^[A-Z]{2}-\\d{4}$",
            message = "Идентификатор состава должен соответствовать формату XX-1234")
    private String compositionId;     //ID Состава

    @NotNull(message = "Номер поезда должен быть задан")
    @Pattern(regexp = "^\\d{4}[А-Я]$",
            message = "Номер поезда должен быть формата 1234А")
    private String trainNumber;       //Номер поезда

    @NotNull(message = "Дата формирования состава должна быть задана")
    @Past(message = "Дата формирования не может быть в будущем")
    private Date formationDate;       //Дата формирования Состава

    @Size(min = 1, max = 100, message = "Станция отправления должна быть от 1 до 100 символов")
    @NotBlank(message = "Станция отправления не может быть пустой")
    private String departureStation;  //Станция отправления

    @Size(min = 1, max = 100, message = "Станция назначения должна быть от 1 до 100 символов")
    @NotBlank(message = "Станция назначения не может быть пустой")
    private String arrivalStation;    //Станция назначения

    @Min(value = 1, message = "Общая длина состава должна быть больше 0")
    @Max(value = 1500, message = "Общая длина состава не может превышать 1500 метров")
    private Integer totalLength;      //Общая длина в метрах

    @Min(value = 1, message = "Вес состава должен быть больше 0 тонн")
    @Max(value = 20000, message = "Вес состава не может превышать 20000 тонн")
    private Integer totalWeight;      //Общий вес в тоннах

    @NotNull(message = "Список вагонов не может быть null")
    @Size(min = 1, max = 200, message = "Состав должен содержать от 1 до 200 вагонов")
    private List<@Valid Wagon> wagons;  //Список выгонов в Составе

    //Конструкторы
    public TrainComposition() {}

    public TrainComposition(String compositionId, String trainNumber, Date formationDate,
                            String departureStation, String arrivalStation, List<Wagon> wagons) {
        this.compositionId = compositionId;
        this.trainNumber = trainNumber;
        this.formationDate = formationDate;
        this.departureStation = departureStation;
        this.arrivalStation = arrivalStation;
        this.wagons = wagons;
    }

    //Геттеры и Сеттеры
    public String getCompositionId() {
        return compositionId;
    }

    public void setCompositionId(String compositionId) {
        this.compositionId = compositionId;
    }

    public String getTrainNumber() {
        return trainNumber;
    }

    public void setTrainNumber(String trainNumber) {
        this.trainNumber = trainNumber;
    }

    public Date getFormationDate() {
        return formationDate;
    }

    public void setFormationDate(Date formationDate) {
        this.formationDate = formationDate;
    }

    public String getDepartureStation() {
        return departureStation;
    }

    public void setDepartureStation(String departureStation) {
        this.departureStation = departureStation;
    }

    public String getArrivalStation() {
        return arrivalStation;
    }

    public void setArrivalStation(String arrivalStation) {
        this.arrivalStation = arrivalStation;
    }

    public Integer getTotalLength() {
        return totalLength;
    }

    public void setTotalLength(Integer totalLength) {
        this.totalLength = totalLength;
    }

    public Integer getTotalWeight() {
        return totalWeight;
    }

    public void setTotalWeight(Integer totalWeight) {
        this.totalWeight = totalWeight;
    }

    public List<Wagon> getWagons() {
        return wagons;
    }

    public void setWagons(List<Wagon> wagons) {
        this.wagons = wagons;
    }
}
