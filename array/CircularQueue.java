import java.util.*;
/*
 * 1. Dropbox ppt
 * 2. http://cs-technotes.blogspot.com/2010/11/thread-safe-circular-queue.html
 */
public class CircularQueue<T> {
    int capacity;
    T[] data;
    int head;
    int tail;
    int size;

    public CircularQueue(int n) {
        capacity = n;
        data = (T[]) new Object[n];
        head = tail = 0;
        size = 0;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public int size() {
        return size;
    }

    public T peek() {
        if (isEmpty()) throw new NoSuchElementException(); 
        return data[head];
    }

    public synchronized void offer(T t) {
        if (size() == capacity) throw new RuntimeException("full");
        data[(head+size)%capacity] = t;
        size++;
    }

    public synchronized T poll() {
        if (isEmpty()) throw new NoSuchElementException(); 
        T ret = data[head];
        head = (head+1)%capacity;
        return ret;
    }

}
