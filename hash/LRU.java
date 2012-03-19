import java.util.*;

public class LRU<K,V> {

    // 1: use composition instead of inheritance
    public static Map<K,V> LRUCache(final int maxSize) {
        return Collections.synchronizedMap(new LinkedHashMap<K,V>(maxSize, 0.75f, true) {
            @Override
                protected boolean removeEldestEntry(Map.Entry<K,V> eldest) {
                    return size()>maxSize;
                }
        });
    }

    /* 2: use ConcurrentLinkedMap
     * http://code.google.com/p/concurrentlinkedhashmap/
     * return new ConcurrentLinkedMap<K,V>()
     * .maxiumWeightedCapacity(maxSize)
     * .build();
     */
}
