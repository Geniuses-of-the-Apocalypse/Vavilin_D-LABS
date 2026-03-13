package JAVA.GUU.RU.LAB4;

//Класс для хранения данных
public class DataElement<T> {
    private T data;

    public DataElement(T data) {
        this.data = data;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return data.toString();
    }
}
