package main.guu.ru.lab9;

//Правильный вагон - без аннотаций
public class PureWagon {

    //Поля класса без аннотаций
    private String nomVag = null;     //Номер вагона
    private String id;                //Системный идентификатор
    private String idPoezd = null;    //Идентификатор поезда
    private String npf = null;        //Код НПФ
    private Integer npp;              //Порядковый номер вагона в составе
    private String esrNazV = null;    //Единая Сетевая Разметка станции назначения
    private Integer vesGruz;          //Вес груза в килограммах
    private Double udl;               //Условная длина вагона

    //Конструктор
    public PureWagon() {
    }

    //Геттеры и Сеттеры
    public String getNomVag() {
        return nomVag;
    }

    public void setNomVag(String nomVag) {
        this.nomVag = nomVag;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getIdPoezd() {
        return idPoezd;
    }

    public void setIdPoezd(String idPoezd) {
        this.idPoezd = idPoezd;
    }

    public String getNpf() {
        return npf;
    }

    public void setNpf(String npf) {
        this.npf = npf;
    }

    public int getNpp() {
        return npp;
    }

    public void setNpp(int npp) {
        this.npp = npp;
    }

    public String getEsrNazV() {
        return esrNazV;
    }

    public void setEsrNazV(String esrNazV) {
        this.esrNazV = esrNazV;
    }

    public int getVesGruz() {
        return vesGruz;
    }

    public void setVesGruz(int vesGruz) {
        this.vesGruz = vesGruz;
    }

    public double getUdl() {
        return udl;
    }

    public void setUdl(double udl) {
        this.udl = udl;
    }
}
