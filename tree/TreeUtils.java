public class TreeUtils {
    public static Tree<Integer> buildAIntegerTree() {
        TreeNode<Integer> n1 = new TreeNode<Integer>(4);
        TreeNode<Integer> n2 = new TreeNode<Integer>(2);
        TreeNode<Integer> n3 = new TreeNode<Integer>(6);
        TreeNode<Integer> n4 = new TreeNode<Integer>(1);
        TreeNode<Integer> n5 = new TreeNode<Integer>(3);
        TreeNode<Integer> n6 = new TreeNode<Integer>(7);
        Tree<Integer> tree = new Tree<Integer>(n1);

        n1.left = n2;
        n1.right = n3;
        n2.left = n4;
        n2.right = n5;
        n3.right = n6;
        return tree;
    }

    public static Tree<Integer> buildAIntegerTreeSmall() {
        TreeNode<Integer> n1 = new TreeNode<Integer>(2);
        TreeNode<Integer> n2 = new TreeNode<Integer>(1);
        TreeNode<Integer> n3 = new TreeNode<Integer>(3);
        Tree<Integer> tree = new Tree<Integer>(n1);

        n1.left = n2;
        n1.right = n3;
        return tree;
    }

    public static void printSucceed(String msg) {
        System.out.println(msg + " pass!");
    }
}
