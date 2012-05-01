import java.util.*;

public class SkipList {
    class Node {
        ArrayList<Integer> width;
        ArrayList<Node> next;
    }
    Node head;
    int level;

    SkipList(int l) {
        level = l;
        head = null;
    }

    public Node findByIndex(int idx) {
        Node n = head;
        for (int i=0; i<level; i++) {
           while (n.width.get(i) <= idx) {
               idx -= n.width.get(i);
               n = n.next.get(i);
           }
           if (idx==0) return n;
        }
        return null;
    }

}
