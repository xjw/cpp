import java.util.*;

/*
 * effective java, prefer composition over inheritance
 */
public class LinkedListWithCounter<T> {
    List list = new LinkedList<T>();
    int counter = 0;
    public void add(T t) {
        count++;
        list.add(t);
    }

    public void addAll(Collection <? extends T> c) {
        count += c.size();
        list.addAll(c);
    }
}
