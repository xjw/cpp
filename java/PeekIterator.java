import java.util.Iterator;

interface PeekIterator<E> extends Iterator<E> {
    E peek();

    @Override
        E next();

    @Override
        boolean hasNext();
}
