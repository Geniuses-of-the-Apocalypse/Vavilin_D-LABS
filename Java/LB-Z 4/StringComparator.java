package JAVA.GUU.RU.LAB4;

public class StringComparator implements Comparator<String> {
    @Override
    public int compare(String a, String b) {
        return a.compareTo(b);
    }
}
