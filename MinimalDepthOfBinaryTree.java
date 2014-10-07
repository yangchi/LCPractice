/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
	public int minDepth(TreeNode root) {
		if(root == null) {
			return 0;
		}    
		int minLeft = minDepth(root.left);
		int minRight = minDepth(root.right);
		if(minLeft == 0)
			return (1 + minRight);
		if(minRight == 0)
			return (1 + minLeft);
		return (1 + Math.min(minLeft, minRight));
	}

}
