import java.util.*;

public class LCA {
    // Solution 1: if BST, just use bst search 
    public TreeNode<Integer> LCA_BST(TreeNode<Integer> root,
            TreeNode<Integer> n1, TreeNode<Integer> n2) {
        if (root == null) return null;
        int smaller = Math.min(n1.data,n2.data);
        int bigger  = Math.max(n1.data,n2.data);
        if (root.data < smaller) 
            return LCA_BST(root.right, n1, n2);
        else if (root.data > bigger)
            return LCA_BST(root.left, n1, n2);
        else 
            return root;
    }

    // Solution 2: for general tree
    // Need to check n1/n2 relationship first
    public TreeNode<Integer> getLCA(TreeNode<Integer> root,
            TreeNode<Integer> n1, TreeNode<Integer> n2) {
        if (root == n1 || root == n2) return root;
        if (isAChildOfB(n1, n2)) return n2;
        if (isAChildOfB(n2, n1)) return n1;
        return LCA(root, n1, n2);
    }

    public boolean isAChildOfB(TreeNode<Integer> n1, TreeNode<Integer> n2) {
        if (n2 == null) return false;
        if (n1 == n2) return true;
        return isAChildOfB(n1, n2.left) || isAChildOfB(n1, n2.right);
    }

    public TreeNode<Integer> LCA(TreeNode<Integer> root,
            TreeNode<Integer> n1, TreeNode<Integer> n2) {
        if (root == null) return null;
        if (root.left == n1 || root.left == n2 
                || root.right == n1 || root.right == n2) {
            return root;
        }
        TreeNode<Integer> left = LCA(root.left, n1, n2);
        TreeNode<Integer> right = LCA(root.right, n1, n2);
        if (left != null && right != null)
            return root;
        return left != null? left : right;
    }

    // Solution 3: find path for n1, n2, 
    // and get Longest common path
    public boolean LCA_PATH_Helper(TreeNode<Integer> root,
            TreeNode<Integer> n,
            List<TreeNode<Integer>> l) {
        if (root == null) return false;
        if ((root.data == n.data) || LCA_PATH_Helper(root.left,n,l) || LCA_PATH_Helper(root.right,n,l)) {
            l.add(root);
            return true;
        }
        return false;
    }

    public TreeNode<Integer> LCA_PATH(TreeNode<Integer> root,
            TreeNode<Integer> n1, TreeNode<Integer> n2) {
        if (root == null) return null;
        if (n1.left == n2 || n1.right == n2) return n1;
        if (n2.left == n1 || n2.right == n2) return n2;
        List<TreeNode<Integer>> l1 = new ArrayList<TreeNode<Integer>>();
        List<TreeNode<Integer>> l2 = new ArrayList<TreeNode<Integer>>();
        LCA_PATH_Helper(root, n1, l1);
        LCA_PATH_Helper(root, n2, l2);
        int i = l1.size()-1;
        int j = l2.size()-1;
        TreeNode<Integer> lca = null;
        while (i>=0 && j>=0) {
            if (l1.get(i) != l2.get(j)) break;
            lca = l1.get(i);
            i--;
            j--;
        }
        return lca;
    }

    public void testLCA() {
        Tree<Integer> tree1 = new Tree<Integer>();
        TreeNode<Integer> n4 = new TreeNode<Integer>(4);
        TreeNode<Integer> n2 = new TreeNode<Integer>(2);
        TreeNode<Integer> n5 = new TreeNode<Integer>(5);
        TreeNode<Integer> n1 = new TreeNode<Integer>(1);
        TreeNode<Integer> n3 = new TreeNode<Integer>(3);
        TreeNode<Integer> n0 = new TreeNode<Integer>(0);
        tree1.root = n4;
        n4.left = n2;
        n4.right = n5;
        n2.left = n1;
        n2.right = n3;
        n1.left = n0;
        tree1.printByLevel();
        System.out.println(LCA_PATH(tree1.root, n1, n2).data);
        System.out.println(LCA_BST(tree1.root, n1, n2).data);
        System.out.println(getLCA(tree1.root, n0, n2).data);
    }

    public static void main(String[] args) {
        LCA LCA = new LCA();
        LCA.testLCA();
    }
}
