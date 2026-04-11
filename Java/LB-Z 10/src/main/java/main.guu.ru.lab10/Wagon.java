package main.guu.ru.lab10;

//Вагон
public class Wagon {
    private String nomVag;
    private Double udl;

    public Wagon(String nomVag, Double udl) {
        this.nomVag = nomVag;
        this.udl = udl;
    }

    public Double getUdl() { return udl; }
    public void setUdl(Double udl) { this.udl = udl; }
    public String getNomVag() { return nomVag; }
    public void setNomVag(String nomVag) { this.nomVag = nomVag; }
}