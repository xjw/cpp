import java.util.*;

public class Heap {
    private int p; // current pointer
    private int SIZE; // total size
    private int[] data; // data array

    public Heap(int size) {
        if (size<=0) throw new IllegalArgumentException();
        SIZE = size;
        p = -1;
        data = new int[size];
    }

    public boolean isEmpty() {
        return p<0;
    }

    public int size() {
        return p+1;
    }

    public int peek() {
        if (isEmpty()) throw new NoSuchElementException();
        return data[0]; 
    }

    public void add(int d) {
        if (p == SIZE-1) expandHeap();
        data[++p] = d;
        siftUp(p);
    }

    public void expandHeap() {
        data = Arrays.copyOf(data,data.length*2);
    }

    public void pop() {
        if (isEmpty()) throw new NoSuchElementException();
        data[0]=data[p--];
        siftDown(0);
    }

    public void siftUp(int n) {
        if (n>p) return;
        while (n>=1) {
            int parent = (n-1)/2;
            if (data[n]>=data[parent]) return;
            Partition.swap(data,n,parent);
            n = parent;
        }
    }

    public void siftDown(int n) {
        if (n<0) return;
        while (2*n+1<=p) {
            int child = 2*n+1;
            if (child<p && data[child+1]<data[child]) child++;
            if (data[child]>=data[n]) return;
            Partition.swap(data,n,child);
        }
    }
    
    public void print() {
        for (int i=0; i<=p; i++) {
            System.out.print(data[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Heap heap = new Heap(3);
        heap.add(5);
        heap.add(2);
        heap.add(6);
        heap.add(10);
        heap.print();
        heap.pop();
        heap.print();
    }
}
