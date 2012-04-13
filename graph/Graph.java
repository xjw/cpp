import java.util.*;

public class Graph {
    class Edge {
        int v;
        int w;
        Edge (int vertex, int weight) {
            v = vertex;
            w = weight;
        }
    }

    class Node {
        int v;
        List<Edge> edges;
        Node (int v) {
            this.v = v;
            edges = new LinkedList<Edge>();
        }
        void addEdge(int v, int w) {
            edges.add(new Edge(v, w));
        }
    }

    int size;
    Node[] nodes;
    boolean isDirected;
    static boolean[] discovered;

    public Graph(int n, boolean is_directed) {
        if (n<=0) throw new IllegalArgumentException();
        isDirected = is_directed;
        size = n;
        nodes = new Node[n];
        discovered = new boolean[n];
    }

    void addEdge(int s, int d, int weight) {
        if (s>=size || d>=size) throw new IllegalArgumentException();
        if (nodes[s] == null) {
            nodes[s] = new Node(s);
        }
        if (nodes[d] == null) {
            nodes[d] = new Node(d);
        }
        nodes[s].addEdge(d, weight);
        if (!isDirected) {
            nodes[d].addEdge(s,weight);
        }
    }

    void resetDiscovered() {
        Arrays.fill(discovered, false);
    }


    void DFS(int s) {
        if (s>=size || nodes[s] == null) return;
        System.out.println(s);
        discovered[s] = true;
        for (Edge e : nodes[s].edges) {
            if (!discovered[e.v])  DFS(e.v);
        }
    }

    void DFS_iterative(int s) {
        if (s>=size || nodes[s] == null) return;
        resetDiscovered();
        Stack<Integer> st = new Stack<Integer>();
        st.push(s);
        discovered[s] = true;
        while (!st.isEmpty()) {
            int n = st.pop();
            System.out.println(n);
            for (Edge e : nodes[n].edges) {
                if (!discovered[e.v]) {
                    st.push(e.v);
                    discovered[e.v] = true;
                }
            }
        }
    }

    void BFS(int s) {
        if (s>=size || nodes[s] == null) return;
        resetDiscovered();
        Queue<Integer> q = new LinkedList<Integer>();
        q.offer(s);
        discovered[s] = true;
        while (!q.isEmpty()) {
            int n = q.poll();
            System.out.println(n);
            for (Edge e : nodes[n].edges) {
                if (!discovered[e.v]) {
                    q.offer(e.v);
                    discovered[e.v]=true;
                }
            }
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(4, false);
        g.addEdge(0,1,10);
        g.addEdge(0,2,8);
        g.addEdge(1,2,6);
        g.addEdge(1,3,7);
        g.addEdge(0,3,5);
        g.addEdge(3,2,4);
        g.DFS(0);
        System.out.println();
        g.DFS_iterative(0);
        System.out.println();
        g.BFS(0);
    }
}
