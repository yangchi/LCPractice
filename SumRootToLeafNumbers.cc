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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        helper(root, &result);
        return result;
    }
    
    void helper(TreeNode * root, int * current)
    {
        if(!root){
            //*current = 0;
            return;
        }
        *current = *current * 10 + root->val;
        int left = *current, right = *current;
        if(root->left)
            helper(root->left, &left);
        else
            left = 0;
        if(root->right)
            helper(root->right, &right);
        else
            right = 0;
        if(left != 0 || right != 0)
            *current = left + right;
    }


};
