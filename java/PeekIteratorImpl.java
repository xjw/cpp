import java.util.Iterator;

public class PeekIteratorImpl<E> implements PeekIterator<E> {
    private final Iterator<? extends E> it;
    boolean hasPeeked = false; // this boolean is must have
    E peekedElement;

    public PeekIteratorImpl(Iterator<E> iterator) {
        this.it = iterator;
    }

    @Override
    public boolean hasNext() {
        return hasPeeked || it.hasNext();
    }

    @Override
    public E next() {
        if (!hasPeeked) {
            return it.next();
        }
        E element = peekedElement;
        peekedElement = null;
        hasPeeked = false;
        return element;
    }

    @Override
    public E peek() {
        if (!hasPeeked) {
            peekedElement = it.next();
            hasPeeked = true;
        }
        return peekedElement;
    }

    @Override 
    public void remove() {

    }
    
}
