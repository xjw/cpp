import java.util.*;

/*
 * http://algs4.cs.princeton.edu/32bst/BST.java.html
 */
public class Tree<T extends Comparable<T>> {
    TreeNode<T> root;

    public Tree() {
    }

    public Tree(TreeNode<T> r) {
        root = r;
    }

    public void insert(T data) {
        if (root == null) {
            root = new TreeNode<T>(data);
            return;
        }

        TreeNode<T> node = root;
        while (node != null) {
            int cmp = data.compareTo(node.data);
            if (cmp == 0) return;
            if (cmp>0) {
                if (node.right == null) {
                    node.right = new TreeNode<T>(data);
                    return;
                }
                node = node.right;
            }
            else {
                if (node.left == null) {
                    node.left = new TreeNode<T>(data);
                    return;
                }
                node = node.left;
            }
        }
    }

    public void insertRecursive(T x) {
        root = insertRecursive(root, x);
    }

    public TreeNode<T> insertRecursive(TreeNode<T> n, T x) {
        if (n == null)
            n = new TreeNode<T>(x);
        else if (x.compareTo(n.data) > 0)
            n.right = insertRecursive(n.right, x);
        else if (x.compareTo(n.data) < 0)
            n.left = insertRecursive(n.left, x);
        return n;
    }

    public void remove(T x) {
        root = remove(root, x);
    }

    public TreeNode<T> remove(TreeNode<T> n, T x) {
        if (n == null)
            return null;
        int cmp = x.compareTo(n.data);
        if (cmp < 0)
            n.left = remove(n.left, x);
        else if (cmp > 0)
            n.right = remove(n.right, x);
        else if (n.left == null || n.right == null)
            n = (n.left == null)? n.right : n.left;
        else {
            n.data = findMin(n.right).data;
            n.right = remove(n.right, n.data);
        }
        return n;
    }


    public void findKthLargest(TreeNode<T> n, int k, int i) {
        if (n == null) return;
        findKthLargest(n.right, k, i);
        i++;
        if (i == k) {
            // print out node
            return;
        } 
        findKthLargest(n.left, k, i);
    }

    /*
     * Find smallest node in substree rooted at n
     */
    public TreeNode<T> findMin(TreeNode<T> n) {
        if (n == null)
            return n;
        while (n.left != null) 
            n = n.left;
        return n;
    }


    public String InOrder(TreeNode<T> node) {
        if (node == null) return "";
        return InOrder(node.left) + node.data + InOrder(node.right);
    }

    public String PreOrder(TreeNode<T> node) {
        if (node == null) return "";
        return node.data + PreOrder(node.left) + PreOrder(node.right);
    }

    /*
     * http://www.geeksforgeeks.org/archives/6358
     * Use Morris Traversal
     */
    public void inOrderNonRecursiveNoStack() {

    }

    /*
     * print by level using a token so no need to add null into Queue
     */
    public void printByLevel() {
        if (root == null) return;
        Queue<TreeNode<T>> q = new LinkedList<TreeNode<T>>();
        q.offer(root);
        int count_this_level = 1;
        int count_next_level = 0;
        while(!q.isEmpty()) {
            TreeNode<T> node = q.poll();
            count_this_level--;
            System.out.print(node.data+" ");
            if (node.left != null) {
                q.offer(node.left);
                count_next_level++;
            }
            if (node.right != null) {
                q.offer(node.right);
                count_next_level++;
            }
            if (count_this_level == 0) {
                System.out.println("");
                count_this_level = count_next_level;
                count_next_level = 0;
            }
        }
    }

    public boolean equals(Tree<T> t2) {
        return equalNode(this.root, t2.root);
    }

    public boolean equalNode(TreeNode<T> n1, TreeNode<T> n2) {
        return (n1 == null && n2 == null) || 
            ((n1 != null && n2 != null) 
            && (n1.data == n2.data)
            && equalNode(n1.left, n1.left) 
            && equalNode(n1.right, n2.right));
    }

    public int height(TreeNode<T> n) {
        return (n == null)? 0
            : 1 + Math.max(height(n.left), height(n.right));
    }

    public int width(TreeNode<T> root) {
        if (root == null)
            return 0;
        Queue<TreeNode<T>> q = new LinkedList<TreeNode<T>>();
        q.offer(root);
        int max, cur, next;
        next = 0;
        max = cur = 1;
        while (!q.isEmpty()) {
            TreeNode<T> n = q.poll();
            cur--;
            if (n.left != null) {
                q.offer(n.left);
                next++;
            }
            if (n.right != null) {
                q.offer(n.right);
                next++;
            }
            if (cur == 0) {
                max = Math.max(max, next);
                cur = next;
                next = 0;
            }
        }
        return max;
    }

    /*
     * Using parent pointer
     */
    public TreeNode<T> inOrderSucessorWithParent(TreeNode<T> node) {
        TreeNode<T> succ = null;

        if (node == null)
            return succ;
        if (node.right != null) {
            succ = node.right;
            while (succ.left != null)
                succ = succ.left;
        }
        return succ;
        /*
        while (node.parent != null 
                && node == node.parent.right)
            node = node.parent;
        return node.parent;
        */
    }

    /*
     * No parent pointer, top down from root
     * Assuming binary search tree
     */
    public TreeNode<T> inOrderSucessor(TreeNode<T> node, TreeNode<T> root) {
        if (node == null || root == null)
            return null;
        TreeNode<T> succ = null;
        if (node.right != null) {
            succ = node.right;
            while (succ.left != null)
                succ = succ.left;
            return succ;
        }
        while (root != null) {
            if (root == node)
                break;
            else if (node.data.compareTo(root.data) > 0) 
                root = root.right;
            else {
                root = root.left;
                succ = root;
            }
        }
        return succ;
    }

    public static void main(String[] args) {
        Tree<Integer> tree1 = new Tree<Integer>();
        tree1.insert(3);
        tree1.insert(1);
        tree1.insert(2);
        tree1.insert(4);

        //Tree<Integer> tree1 = TreeUtils.buildAIntegerTree();
        //Tree<Integer> tree2 = TreeUtils.buildAIntegerTreeSmall();

        tree1.printByLevel();
        //tree1.remove(3);
        tree1.printByLevel();
        System.out.println(tree1.width(tree1.root));
        //assert !tree1.equals(tree2);
    }
}
