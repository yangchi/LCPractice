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
    bool isValidBST(TreeNode *root) {
        TreeNode * prev = NULL;
        inorderValidate(root, prev);
    }

    bool inorderValidate(TreeNode *root, TreeNode * & prev) {
        if (!root) {
            return true;
        }
        if (!inorderValidate(root->left, prev)) {
            return false;
        }
        if (prev && prev->val >= root->val) {
            return false;
        }
        prev = root;
        return inorderValidate(root->right, prev);
    }
};
