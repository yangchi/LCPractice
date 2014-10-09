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
        void flatten(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(!root)
                return;
            if(root->left)
                flatten(root->left);
            TreeNode *lefttail = root;
            if(root->left)
            {
                lefttail = root->left;
                while(lefttail->right)
                    lefttail = lefttail->right;
            }
            if(root->right)
                flatten(root->right);
            lefttail->right = root->right;
            if(root->left)
            {
                root->right = root->left;
                root->left = NULL;
            }
        }
};
