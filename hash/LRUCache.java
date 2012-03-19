import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

/*
 * http://code.google.com/p/sureinterview/source/browse/src/solution/misc/CacheStrategies.java
 * Store doubled-linkedlist node in hashmap
 */
public class LRUCache<K, V> {
	private Map<K, Node<V>> map;
	private Node<V> head, tail;
	private int maxSize;

    /*
     * Have a dedicated head and tail will make code simpler
     */
	public LRUCache(int size) {
		maxSize = size;
		head = new Node<V>(null);
		tail = new Node<V>(null);
		head.next = tail;
		tail.prev = head;
		map = new ConcurrentHashMap<K, Node<V>>();
	}

	public V get(K key) {
		Node<V> node = map.get(key);
		if (node != null) {
			remove(node);
			addToTail(node);
			return node.data;
		}
		return null;
	}

	public void addToTail(Node<V> newNode) {
		insertBefore(tail, newNode);
	}

	public void insertBefore(Node<V> node, Node<V> newNode) {
		newNode.prev = node.prev;
		newNode.next = node;
		newNode.prev.next = newNode;
		node.prev = newNode;
	}

	public void remove(Node<V> node) {
		if (node != null) {
			node.prev.next = node.next;
			node.next.prev = node.prev;
		}
	}

	public void put(K key, V val) {
		Node<V> node = map.get(key);
		if (node == null) {
			if (size() >= maxSize) {
				remove(head.next);
			}
			node = new Node<V>(val);
			map.put(key, node);
		} else {
			remove(node);
		}
		insertBefore(tail,node);
	}

	public int size() {
		return map.size();
	}

	public List<V> toList() {
		List<V> list = new ArrayList<V>();
		Node<V> node = head.next;
		while (node != tail) {
			list.add(node.data);
            node = node.next;
		}
		return list;
	}

	public String toString() {
		StringBuilder result = new StringBuilder();
		Node<V> node = head.next;
		while (node != tail) {
			result.append(node.data).append(" ");
			node = node.next;
		}
		return result.toString();
	}

	private class Node<V> {
		Node<V> prev;
		Node<V> next;
		V data;
		public Node(V val) {
			prev = next = null;
			data = val;
		}
	}

	public static void test() {
		Integer[][] expectedResults = {
				{0, 1}, { 1 },  // put 1, add
				{0, 2}, { 1, 2}, // put 2, add
				{0, 3}, { 1, 2, 3}, // put 3, add
				{0, 2}, { 1, 3, 2}, // put 2, move 2
				{1, 1}, { 3, 2, 1}, // get 1, move 1
				{0, 3}, { 2, 1, 3}, // put 3, move
				{1, 4}, { 2, 1, 3}, // get 4, miss
				{0, 4}, { 1, 3, 4}, // put 4, 2 is gone
				{0, 0}, { 3, 4, 0}  // put 0, 1 is gone
		};
		LRUCache<Integer, Integer> cache = new LRUCache<Integer, Integer>(3);
		for (int i=0; i<expectedResults.length; i+=2) {
			int action = expectedResults[i][0];
			int val = expectedResults[i][1];
			if (action == 0) {
				cache.put(val, val);
			} else {
				cache.get(val);
			}
			List<Integer> list = Arrays.asList(expectedResults[i+1]);
			assert cache.toList().equals(list);
            System.out.println(cache.toList() + "=" + list);
		}
	}

	public static void main(String args[]) {
		test();
	}
}


