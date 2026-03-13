package JAVA.GUU.RU.LAB4;

public class CharComparator implements Comparator<Character> {
    @Override
    public int compare(Character a, Character b) {
        return Character.compare(a, b);
    }
}
