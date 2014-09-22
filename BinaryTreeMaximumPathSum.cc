/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
	int maxPathSum(TreeNode *root) {
	    // Start typing your C/C++ solution below
	    // DO NOT write int main() function
	    int cmax, maxmax = INT_MIN;
	    MaxDFS(root, &cmax, &maxmax);
	    return maxmax;
	}

	void MaxDFS(TreeNode *node, int *max_nothrough, int *maxmax)
	{
	    if(!node)
	    {
		*max_nothrough = 0;
	    }
	    int left_length = 0;
	    int right_length = 0;
	    if(node->left)
		MaxDFS(node->left, &left_length, maxmax);
	    if(node->right)
		MaxDFS(node->right, &right_length, maxmax);
	    *max_nothrough = max(node->val, max(left_length+node->val, right_length+node->val));
	    *maxmax = max(*maxmax, max(*max_nothrough, node->val+left_length+right_length));
	}
};
