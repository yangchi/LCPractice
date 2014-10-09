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
        bool hasPathSum(TreeNode *root, int sum) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(!root)
                return false;
            if(root->val == sum && !root->left && !root->right)
                return true;
            if(root->left)
            {
                bool leftworks = hasPathSum(root->left, sum - root->val);
                if(leftworks)
                    return true;
            }
            if(root->right)
            {
                bool rightworks = hasPathSum(root->right, sum - root->val);
                if(rightworks)
                    return true;
            }
            return false;
        }
};
