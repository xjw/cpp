import java.util.*;

public class Tree<T> {
    TreeNode<T> root;

    public Tree(TreeNode<T> r) {
        root = r;
    }

    public String getInorder(TreeNode<T> node) {
        if (node == null) return "";
        return getInorder(node.left) + node.data + getInorder(node.right);
    }

    public String getPreOrder(TreeNode<T> node) {
        if (node == null) return "";
        return node.data + getPreOrder(node.left) + getInorder(node.right);
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


    public static void main(String[] args) {
        Tree<Integer> tree1 = TreeUtils.buildAIntegerTree();
        Tree<Integer> tree2 = TreeUtils.buildAIntegerTreeSmall();

        tree1.printByLevel();
        tree2.printByLevel();
        assert !tree1.equals(tree2);
    }
}
