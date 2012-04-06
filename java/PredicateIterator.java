import java.util.*;

/*
 * http://chaoticjava.com/posts/how-to-write-iterators-really-really-fast/
 */
class PredicateIterator<T> implements Iterator<T> {
    Iterator<? extends T> it;
    private final Predicate pr;
    private T nextElement;
    boolean hasNextElement; // this boolean is required

    public PredicateIterator(Iterator<T> iterator, Predicate predicate) {
        this.it = iterator;
        this.pr = predicate;
        seekNext();
    }

    public T next() {
        if (!hasNextElement) throw new NoSuchElementException();
        T ret = nextElement;
        seekNext();
        return ret;
    }

    public boolean hasNext() {
        return hasNextElement;
    }

    public void seekNext() {
        hasNextElement = false;
        nextElement = null;
        while (it.hasNext() && !hasNextElement) {
            T e = it.next();
            if (pr.evaluate(e)) {
                nextElement = e;
                hasNextElement = true;
            }
        }
    }

}
