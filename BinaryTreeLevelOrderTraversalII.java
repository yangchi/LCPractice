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
	public List<List<Integer>> levelOrderBottom(TreeNode root) {
		LinkedList<List<Integer>> result = new LinkedList<List<Integer>>();
		if(root == null) {
			return result;
		}
		LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
		result.add(new ArrayList<Integer>());
		HashMap<TreeNode, Integer> mapper = new HashMap<TreeNode, Integer>();
		queue.add(root);
		mapper.put(root, 0);
		result.get(0).add(root.val);
		int maxlevel = 0;
		while(!queue.isEmpty()) {
			TreeNode parent = queue.remove();
			int parent_level = mapper.get(parent);
			boolean hasLeft = false;
			if(parent.left != null) {
				hasLeft = true;
				queue.add(parent.left);
				mapper.put(parent.left, parent_level + 1);
				if(maxlevel < parent_level + 1) {
					maxlevel = parent_level + 1;
					result.addFirst(new ArrayList<Integer>());
					result.get(result.size() - 1 - parent_level - 1).add(parent.left.val);
				} else {
					result.get(result.size() - 1 - parent_level - 1).add(parent.left.val);
				}
			}
			if(parent.right != null) {
				queue.add(parent.right);
				mapper.put(parent.right, parent_level + 1);
				if(maxlevel < parent_level + 1) {
					maxlevel = parent_level + 1;
					result.addFirst(new ArrayList<Integer>());
					result.get(result.size() - 1 - parent_level - 1).add(parent.right.val);
				} else {
					result.get(result.size() - 1 - parent_level - 1).add(parent.right.val);
				}
			}
		}
		return result;
	}
}
