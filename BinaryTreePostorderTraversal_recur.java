/**
 ** Definition for binary tree
 ** public class TreeNode {
 **     int val;
 **     TreeNode left;
 **     TreeNode right;
 **     TreeNode(int x) { val = x; }
 ** }
 **/
public class Solution {
	public List<Integer> postorderTraversal(TreeNode root) {
		ArrayList<Integer> l = new ArrayList<Integer>();
		if(null == root) {
			return l;
		}
		l.addAll(postorderTraversal(root.left));
		l.addAll(postorderTraversal(root.right));
		l.add(root.val);
		return l;
	}
}
