/**
 * Created by yangchi on 10/15/14.
 */
public class RecoverBST {

    public TreeNode first = null;
    public TreeNode second = null;
    public TreeNode pre = null;

    public void recoverTree(TreeNode root) {
        if (root == null) {
            return;
        }
        //inOrder(root, first, second, pre);
        inOrder(root);
        if(first == null)
            System.out.println("First is empty");
        if (second == null)
            System.out.println("Second is empty");
        if(first == null || second == null)
            return;
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }

    public void inOrder(TreeNode root) { //, TreeNode first, TreeNode second, TreeNode pre) {
        if(root == null) {
            return;
        }
        inOrder(root.left); //, first, second, pre);
        if(pre == null) {
            pre = root;
        } else {
            if(pre.val > root.val) {
                if(first == null) {
                    first = pre;
                    System.out.println("Changed first to " + pre.val);
                }
                second = root;
                System.out.println("Changed second to " + root.val);
            }
            pre = root;
        }
        inOrder(root.right); //, first, second, pre);
    }

    public static void main(String args[]) {
        TreeNode root = new TreeNode(0);
        root.left = new TreeNode(1);
        RecoverBST bst = new RecoverBST();
        bst.recoverTree(root);

    }

}
