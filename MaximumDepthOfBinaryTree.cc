/**
 * Definition for binary tree
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        int maxDepth(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(!root)
                return 0;
            int leftdep = maxDepth(root->left);
            int rightdep = maxDepth(root->right);
            int max = leftdep > rightdep ? leftdep : rightdep;
            return max+1;
        }
};
