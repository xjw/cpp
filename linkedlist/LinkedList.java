import java.util.*;

public class LinkedList {
    Node head;
    LinkedList() {head=null;}

    public void add(int x) {
        Node n = new Node(x);
        n.next = head;
        head = n;
    }

    public static void print(Node head) {
        Node n = head;
        while (n != null) {
            System.out.print(n.data + " ");
            n = n.next;
        }
        System.out.println();
    }

    public Node findMiddle(Node head) {
        if (head == null) return null;
        Node i, j;
        i = head;
        j = head.next;
        while (j != null && j.next != null) {
            i = i.next;
            j = j.next.next;
        }
        return i;
    }

    public Node reverse(Node head) {
        Node prev, curr, next;
        curr = head;
        prev = null;
        while(curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public Node reverse_recursive(Node node) {
        if (node == null || node.next == null) return node;
        Node tail = node.next;
        Node head = reverse_recursive(tail);
        tail.next = node;
        node.next = null;
        return head;
    }

    public void reverse_cool(Node node) {
    }

    public Node mergeList(Node a, Node b) {
        Node head = new Node(0);
        Node prev = head;
        while(a != null && b != null) {
            if (a.compareTo(b)<=0) {
                prev.next = a;
                prev = a;
                a = a.next;
            }
            else {
                prev.next = b;
                prev = b;
                b = b.next;
            }
        }
        prev.next = (a==null)? b : a;
        return head.next;
    }

    /*
     * http://www.leetcode.com/onlinejudge
     */
    public Node mergeKLists(ArrayList<Node> lists) {
        if (lists == null || lists.isEmpty()) return null;
        
        Node head = new Node(0);
        Node prev = head;
        Comparator<Node> nodeComparator = new Comparator<Node>() {
            public int compare(Node l1, Node l2) {
                return l1.data - l2.data;
            }
        };
        PriorityQueue<Node> pq = new PriorityQueue<Node>(lists.size(),
                nodeComparator);
        for (Node node : lists) {
            if (node != null) {
                pq.add(node);
            }
        }
        while (!pq.isEmpty()) {
            Node min = pq.poll();
            prev.next = min;
            prev = min;
            if (min.next != null) pq.add(min.next);
        }
        return head.next;
    }

    public Node mergeSort(Node head) {
        if (head == null || head.next == null) return head; 
        Node m = findMiddle(head);
        Node n = m.next;
        m.next = null;
        return mergeList(mergeSort(head), mergeSort(n));
    }

    class Node implements Comparable<Node> {
        Node next;
        int data;
        Node (int d) {data = d; next=null;}
        public String toString() {return String.valueOf(data);}
        public int compareTo(Node n) {
            return this.data - n.data;
        }
    }

    public boolean existCircle(Node head) {
        if (head == null) return false;
        Node fast = head.next;
        while(fast != null && fast.next != null) {
            if (head == fast) return true;
            head = head.next;
            fast = fast.next.next;
        }
        return false;
    }

    /*
     * Reasoning:
     * 2*(a + y) = a + 2y + x 
     * a = x 
     * x is when slow and fast pointer meets, the distance to circle start
     * a is the distance of head to circle start
     */
    public Node find_start_of_loop(Node head) {
        if (head == null) return null;
        Node fast = head;
        Node n = head;
        while(fast != null && fast.next != null) {
            n = n.next;
            fast = fast.next.next;
            if (n == fast) {
                n = head;
                while (n != fast) {
                    n = n.next;
                    fast = fast.next;
                }
            }
        }
        return n;
    }

    public Node get_n_to_last(Node head, int n) {
        if (head == null || n<0) return null;
        Node fast = head;
        while (n-->0) {
            fast = fast.next;
            if (fast == null) {
                throw new IllegalArgumentException();
            }
        }
        while(fast != null && fast.next != null) {
            fast = fast.next;
            head = head.next;
        }
        return head;
    }

    /*
     Given a list, rotate the list to the right by k places, where k is non-negative.
     For example:
     Given 1->2->3->4->5->NULL and k = 2,
     return 4->5->1->2->3->NULL.
     http://www.leetcode.com/onlinejudge
     */
    public Node rotateList(Node head, int n) {
        if (n <= 0 || head == null) return head;

        Node p, q;
        p = head;
        int i = 0;
        while(p != null) {
            i++;
            p = p.next;
        }
        n = n%i;
        if (n==0) return head;

        p = q = head;
        while (n-- >0) {
            q = q.next;
        }

        while(q.next != null) {
            p = p.next;
            q = q.next;            
        }
        q.next = head;
        head = p.next;
        p.next = null;
        return head;
    }
    
    /*
     * 1-4-5-6-3
     * 4-1-6-5-3
     */
    public Node swapAdjacentNode(Node head) {
        if (head == null || head.next == null) return head;
        Node c, n;
        c = head;
        while (c != null && c.next != null) {
            n = c.next;
            int t = c.val;
            c.val = n.val;
            n.val = t;
            c = n;
        }
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.add(3);
        list.add(2);
        list.add(1);
        list.add(4);
        list.add(2);
        print(list.head);
        System.out.println("middle point " + list.findMiddle(list.head));
        System.out.println("After sorting");
        Node head = list.mergeSort(list.head);
        list.print(head);
        //list.print(list.reverse_recursive(head));
        //System.out.println(list.get_n_to_last(head, 5));
        LinkedList list2 = new LinkedList();
        list2.add(8);
        list2.add(6);
        list2.add(5);
        print(list2.head);
        ArrayList<Node> nodeArray = new ArrayList<Node>();
        nodeArray.add(head);
        nodeArray.add(list2.head);
        print(list.mergeKLists(nodeArray));
    }
}
