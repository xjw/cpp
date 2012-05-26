import java.util.*;

public class TreePrint {
    /*
     * http://www.leetcode.com/2010/09/printing-binary-tree-in-zig-zag-level_18.html
     */
    void printZigZag(TreeNode<Integer> root) {
        if (root == null) return;
        boolean leftToright = true;
        Stack<TreeNode<Integer>> curr_stack = new Stack<TreeNode<Integer>>();
        Stack<TreeNode<Integer>> next_stack = new Stack<TreeNode<Integer>>();
        curr_stack.push(root);
        while (!curr_stack.isEmpty()) {
            TreeNode<Integer> node = curr_stack.pop();
            System.out.print(node.data + " ");
            if (leftToright) {
                if (node.right != null) next_stack.push(node.right);
                if (node.left != null) next_stack.push(node.left);
            } else {
                if (node.left != null) next_stack.push(node.left);
                if (node.right != null) next_stack.push(node.right);
            }
            if (curr_stack.isEmpty()) {
                System.out.println();
                curr_stack = next_stack;
                next_stack = new Stack<TreeNode<Integer>>();
                leftToright = !leftToright;
            }
        }
    }

    /*
     * http://www.leetcode.com/2010/10/print-edge-nodes-boundary-of-binary.html
     */
    void printEdgeNodes(TreeNode<Integer> root) {
        System.out.println(root.data + " ");
        printLeftEdges(root.left, true);
        printRightEdges(root.right, true);
    }

    void printLeftEdges(TreeNode<Integer> root, boolean print) {
        if (root == null) return;
        if (print || (root.left == null && root.right == null)) 
            System.out.println(root.data + " ");
        printLeftEdges(root.left, print);
        printRightEdges(root.right, (print && p.left == null)? true : false);
    }

    void printRightEdges(TreeNode<Integer> root, boolean print) {
        if (root == null) return;
        printLeftEdges(root.left, (print && p.right == null)? true : false);
        printRightEdges(root.right, print);
        if (print || (root.left == null && root.right == null)) 
            System.out.println(root.data + " ");
    }

    public static void main(String[] args) {
        TreePrint tp = new TreePrint();
        Tree tree = TreeUtils.buildAIntegerTree();
        tree.printByLevel();
        System.out.println();
        tp.printZigZag(tree.root);
        System.out.println();
        tp.printEdgeNodes(tree.root);
    }
}
