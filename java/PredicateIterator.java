import java.util.*;

class PredicateIterator<T> implements Iterator<T> {
    Iterator<? extends T> it;
    private final Predicate pr;
    private T nextElement;

    public PredicateIterator(Iterator<T> iterator, Predicate predicate) {
        this.it = iterator;
        this.pr = predicate;
        seekNext();
    }

    public T next() {
        T ret = nextElement;
        nextElement = null;
        seekNext();
        return ret;
    }

    public boolean hasNext() {
        return null != nextElement;
    }

    public void seekNext() {
        while (it.hasNext()) {
            T e = it.next();
            if (pr.evaluate(e)) {
                nextElement = e;
            }
        }
    }

}
