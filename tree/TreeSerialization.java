import java.util.*;

public class TreeSerialization {
    public void testPreOrderSerialization(Tree<Integer> tree) {
        SerializationPreOrder s1 = new SerializationPreOrder(tree.root);
        String preorder = s1.serialize();
        System.out.println(preorder);
        Tree<Integer> tree1 = new Tree<Integer>(s1.deserialize(preorder)); 
        assert(tree.equals(tree1));
        System.out.println("PreOrder passes!");
        tree1.printByLevel();
    }

    public void testInorderPreOrderSerialization(Tree<Integer> tree) {
        String preorder = tree.getPreOrder(tree.root);
        String inorder =  tree.getInorder(tree.root);

        SerializationInterface s1 = new SerializationInorderPreOrder(preorder, inorder);
        Tree<Integer> tree1 = new Tree<Integer>(s1.deserialize()); 
        assert(tree.equals(tree1));
        System.out.println("InOrderPreOrder passes!");
        tree1.printByLevel();
    }

    public static void main(String[] args) {
        Tree<Integer> tree = TreeUtils.buildAIntegerTree();
        TreeSerialization s = new TreeSerialization();
        // testing preorder & null pointer serialization
        s.testPreOrderSerialization(tree);
        System.out.println();
        // testing inorder & preorder serialization
        s.testInorderPreOrderSerialization(tree);
    }
}

interface SerializationInterface {
    public String serialize();
    public TreeNode<Integer> deserialize();
}

/*
 * Approach 1:
 * Store preorder with nul pointers
 */
class SerializationPreOrder implements SerializationInterface {
    private TreeNode<Integer> root;
    private String NULL_CHILDREN = "/";
    private String SEPARATOR = " ";

    SerializationPreOrder(TreeNode<Integer> node) {
        root = node;
    }

    public String serialize() {
        return serialize(root);
    }

    public String serialize(TreeNode<Integer> node) {
        return (node == null) ? NULL_CHILDREN + SEPARATOR :
            node.data + SEPARATOR + serialize(node.left) + serialize(node.right);
    }

    public TreeNode<Integer> deserialize() {
        return null;
    }

    public TreeNode<Integer> deserialize(String s) {
        Queue<String> q = new LinkedList<String>(Arrays.asList(s.split("\\s")));
        return deserialize(q);
    }

    public TreeNode<Integer> deserialize(Queue<String> q) {
        if (q.isEmpty()) {
            return null;
        }
        String s = q.poll();
        if (s.equals(NULL_CHILDREN)) {
            return null;
        }
        TreeNode<Integer> node = new TreeNode<Integer>(Integer.parseInt(s));
        node.left = deserialize(q);
        node.right = deserialize(q);
        return node;
    }


}

/*
 * Approach 2:
 *
 *     4
 *    / \
 *   2   6
 *  / \   \
 * 1   3   7
 *
 * pre: 421367 4(213)(67)
 * in: 123467  (123)4(67)
 *
 * look for 4 in inorder, to find the length of left tree, use that to recursively
 * deserialize left tree and right tree
 * divide and conquer
 */
class SerializationInorderPreOrder implements SerializationInterface {
    String pre, in;

    public SerializationInorderPreOrder(String preorder, String inorder) {
        pre = preorder;
        in = inorder;
    }

    public String serialize() {
        return "";
    }

    public TreeNode<Integer> deserialize() {
        return deserialize(pre, in);
    }

    public TreeNode<Integer> deserialize(String pre, String in) {
        if (pre.isEmpty() || in.isEmpty()) return null;
        char c = pre.charAt(0);
        int i = in.indexOf(c);
        //System.out.println(pre + "-" + in + "-" +  i + "-" + c);
        TreeNode<Integer> node = new TreeNode<Integer>(Character.getNumericValue(c));
        node.left  = deserialize(pre.substring(1,i+1), in.substring(0,i));
        node.right = deserialize(pre.substring(i+1), in.substring(i+1));
        return node;
    }
}

/*
 * Is it possible to rebuild from postorder preorder?
 * The answer is NO!
 *   1    1
 *  /      \
 * 2        2
 * both are the smae, postorder 21, preorder 12
 *
 * only doable with the restriction that 
 * no node can have a right child without having a left child
 * similar idea as above
 * http://www.cmi.ac.in/~madhavan/courses/programming06/lecture12-21sep2006.txt
 */
class SerializationPostorderPreOrder {
}
