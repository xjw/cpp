import java.util.*;

public class Tree<T> {
    TreeNode<T> root;

    public void setRoot(TreeNode<T> r) {
        root = r;
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
            System.out.println(node.data);
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

    public void serialize(TreeNode<T> root) {

    }


    public static void main(String[] args) {
        Tree<Integer> tree = new Tree<Integer>();
        TreeNode<Integer> n1 = new TreeNode<Integer>(4);
        TreeNode<Integer> n2 = new TreeNode<Integer>(2);
        TreeNode<Integer> n3 = new TreeNode<Integer>(6);
        TreeNode<Integer> n4 = new TreeNode<Integer>(1);
        TreeNode<Integer> n5 = new TreeNode<Integer>(3);
        TreeNode<Integer> n6 = new TreeNode<Integer>(5);
        tree.setRoot(n1);

        n1.left = n2;
        n1.right = n3;
        n2.left = n4;
        n2.right = n5;
        n

        tree.printByLevel();
    }

}
