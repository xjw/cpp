import java.util.*;

/*
 * http://stevedaskam.wordpress.com/2009/05/28/trie-structures/
 */
class TrieNode<T> {
    T val;
    char key;
    boolean terminal = false;
    Map<Character, TrieNode<T>> children = new HashMap<Character, TrieNode<T>>();

    TrieNode() {
    }

    TrieNode (char c) {
        key = c;
    }
}


public class Trie<T> {
    TrieNode<T> root = null;

    Trie() {
        root = new TrieNode<T>();
    }

    boolean contains(String word) {
        TrieNode<T> curr = root;
        for (int i=0; i<word.length(); i++) {
            char c = word.charAt(i);
            curr = curr.children.get(c);
            if (curr == null) return false;
        }
        return curr != null && curr.terminal;
    }

    void insert(String word) {
        TrieNode<T> curr = root;
        for (int i=0; i<word.length(); i++) {
            char c = word.charAt(i);
            TrieNode<T> next = curr.children.get(c);
            if (next == null) {
                next = new TrieNode<T>(c);
                curr.children.put(c, next);
            }
            curr = next;
            if (i == word.length()-1) {
                next.terminal = true;
            }
        }
    }

    void remove(String word) {
        // need to add counter to the TrieNode
        // only if counter == 1, remove
        // otherwise, can't remove current node
    }

    public static void main(String[] args) {
        Trie<Integer> trie = new Trie<Integer>();
        trie.insert("abc");
        System.out.println(trie.contains("abc"));
        System.out.println(trie.contains("abb"));
        System.out.println(trie.contains("ab"));
    }
}

