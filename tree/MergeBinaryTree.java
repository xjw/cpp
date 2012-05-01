/*
 * References:
 * http://www.leetcode.com/2010/11/convert-binary-search-tree-bst-to.html
 * http://cslibrary.stanford.edu/109/TreeListRecursion.html
 * http://olehuisha.wordpress.com/2011/04/06/tree-algorithm-1-in-pre-post-order-without-recursion-extra-memory-2-in-order-tree-iterator-3-same-level-in-a-line-4-whether-symerical-5-construct-a-tree-based-on-pre-in-order/
 */

public class MergeBinaryTree<T extends Comparable<T>> {
    public TreeNode<T> prev_node = null;
    public TreeNode<T> chain_head = null;

    // Problem 1. Simple Approach to convert binary search tree to sorted single linkedlist
    // need to use additional global variable because java can not be passed by reference
    public void chainTree(TreeNode<T> n) {
        if (n == null)
            return;
        chainTree(n.left);
        if (prev_node != null)
            prev_node.right = n;
        else
            chain_head = n;
        prev_node = n;
        chainTree(n.right);
    }

    // Problem 2. Similar to 1, but convert binary search tree to sorted doubled linkedlist
    // http://www.leetcode.com/2010/11/convert-binary-search-tree-bst-to.html
    // This is a modified in-order traversal adapted to this problem.
    // prev (init to NULL) is used to keep track of previously traversed node.
    // head pointer is updated with the list's head as recursion ends.
    public void chainDoubleFromTree(TreeNode<T> n) {
        if (n == null)
            return;
        chainDoubleFromTree(n.left);

        if (prev_node == null)
            chain_head = n; // current node (smallest element) is head of the list if previous node is not available
        else
            prev_node.right = n; // previous node's right points to current node

        TreeNode<T> right = n.right; // save right node

        n.left = prev_node; // current node's left points to previous node

        // as soon as the recursion ends, the head's left pointer
        // points to the last node, and the last node's right pointer
        // points to the head pointer
        chain_head.left = n;
        n.right = chain_head;

        // update prev node
        prev_node = n;

        chainDoubleFromTree(right);
    }

    // Problem 3: Use recursion to convert binary search tree to doubled linkedlist
    // Implement solution from
    // http://cslibrary.stanford.edu/109/TreeListRecursion.html
    public TreeNode<T> mergeDoubledLinkedList(TreeNode<T> n1, TreeNode<T> n2) {
        if (n1 == null) return n2;
        if (n2 == null) return n1;

        TreeNode<T> n1_last, n2_last;
        n1_last = n1.left;
        n2_last = n2.left;
        n1_last.right = n2;
        n2.left = n1_last;
        n1.left = n2_last;
        n2_last.right = n1;
        return n1;
    }

    public TreeNode<T> treeToDoubledList(TreeNode<T> root) {
        if (root == null)
            return null;

        TreeNode<T> l = treeToDoubledList(root.left);
        TreeNode<T> r = treeToDoubledList(root.right);

        root.left = root;
        root.right = root;

        return mergeDoubledLinkedList(mergeDoubledLinkedList(l, root), r);
    }

    // Problem 4: Flattern a binary tree (not search tree)
    // From http://stackoverflow.com/questions/3411793/convert-a-binary-tree-to-linked-list-breadth-first-constant-storage-destructiv
    public TreeNode<T> flattern(TreeNode<T> root, TreeNode<T> r) {
        if (root == null)
            return r;
        root.right = flattern(root.left, flattern(root.right, r));
        return root;
    }

    // Problem 5: convert list to binary search tree
    // http://www.leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html
    public TreeNode<T> listToBinarySearchTree(TreeNode<T> head, int start, int end) {
        if (head == null || start > end)
            return null;
        int middle = start + (end-start)/2;
        TreeNode<T> node = head;
        for (int i=start; i<middle; i++) {
            node = node.right;
        }
        node.left = listToBinarySearchTree(head, start, middle-1);
        node.right = listToBinarySearchTree(node.right, middle+1, end);
        return node;
    }


    void removeCycle(TreeNode<T> head) {
        head.left.right = null;
        head.left = null;
    }

    TreeNode<T> mergeSortDoubledLinkedList(TreeNode<T> h1, TreeNode<T> h2) {
        TreeNode<T> dummyHead = new TreeNode<T>(null);
        TreeNode<T> prev;
        prev = dummyHead;

        removeCycle(h1);
        removeCycle(h2);

        while (h1 != null && h2 != null) {
            if (h1.data.compareTo(h2.data)<0) {
                prev.right = h1;
                prev = h1;
                h1 = h1.right;
            } else {
                prev.right = h2;
                prev = h2;
                h2 = h2.right;
            }
        }
        prev.right = (null == h1)? h2 : h1;
        return dummyHead.right;
    }

    TreeNode<T> mergeTree(TreeNode<T> r1, TreeNode<T> r2) {
        return mergeSortDoubledLinkedList(treeToDoubledList(r1), treeToDoubledList(r2));
    }

    void printList(TreeNode<T> head) {
        TreeNode<T> node = head;
        while (node != null) {
            System.out.println(node.data);
            node = node.right;
            if (node == head) break;
        }
    }

    public static void main(String[] args) {
        Tree<Integer> tree1 = new Tree<Integer>();
        tree1.insert(3);
        tree1.insert(1);
        tree1.insert(2);
        tree1.insert(4);
        Tree<Integer> tree2 = new Tree<Integer>();
        tree2.insert(4);
        tree2.insert(6);
        tree2.insert(5);
        tree2.insert(1);
        MergeBinaryTree<Integer> mb = new MergeBinaryTree<Integer>();
        tree2.printByLevel();
        //mb.printList(mb.treeToDoubledList(tree1.root));
        //mb.printList(mb.treeToDoubledList(tree2.root));
        //mb.printList(mb.mergeTree(tree1.root, tree2.root));
        //mb.printList(mb.treeToList(tree1.root, null));
        mb.chainTree(tree2.root);
        mb.printList(mb.chain_head);
        TreeNode<Integer> node = mb.chain_head;
        int size = 0;
        while(node != null) {
            node = node.right;
            size++;
        }
        TreeNode<Integer> root = mb.listToBinarySearchTree(mb.chain_head, 0, size-1);
        Tree<Integer> tree3 = new Tree<Integer>(root);
        System.out.println();
        tree3.printByLevel();
    }
}
