import java.util.*;

public class GeneralTree<T> {
    Node<T> root;

    public void setRoot(Node<T> r) {
        root = r;
    }

    public void printByLevel() {
        if (root == null) return;
        Node<T> node = root;
        int count_this_level = 1;
        int count_next_level = 0;
        Queue<Node<T>> q = new LinkedList<Node<T>>();
        q.offer(node);
        while(!q.isEmpty()) {
            node = q.poll();
            count_this_level--;
            System.out.print(node.data + " ");
            if (node.childrens != null && 
                    !node.childrens.isEmpty())
            {
                for (Node<T> child : node.childrens) {
                    q.offer(child);
                    count_next_level++;
                }
            }
            if (count_this_level == 0) {
                count_this_level = count_next_level;
                count_next_level = 0;
                System.out.println("");
            }
        }
    }

    public String serialize(Node<T> root) {
        if (root != null) {
            String s = String.valueOf(root.data);
            List<Node<T>> list = root.childrens;
            for (Node<T> node : list) {
                s += serialize(node);
            }
            s += ")";
            return s;
        }
        return "";
    }

    public static void main(String[] args) {
        Node<Integer> n1 = new Node<Integer>(1);
        Node<Integer> n2 = new Node<Integer>(2);
        Node<Integer> n3 = new Node<Integer>(3);
        Node<Integer> n4 = new Node<Integer>(4);
        n1.addChildren(n2);
        n1.addChildren(n3);
        n1.addChildren(n4);
        GeneralTree<Integer> tree = new GeneralTree<Integer>();
        tree.setRoot(n1);
        tree.printByLevel();
        System.out.println(tree.serialize(tree.root));
    }
}

class Node<T> {
    T data;
    List<Node<T>> childrens; 
    Node(T d) {
        data = d;
        childrens = new LinkedList<Node<T>>();
    }
    void addChildren(Node<T> node) {
        childrens.add(node);
    }
}
