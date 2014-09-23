/**
 ** Definition for binary tree
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/
class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            return validateBSTLimits(root, INT_MAX, INT_MIN);
        }

        bool validateBSTLimits(TreeNode *node, int max, int min) {
            if (!node) {
                return true;
            }
            if (node->val >= max || node->val <= min)
                return false;
            if (!node->left && !node->right) {
                return true;
            }
            bool validLeft = validateBSTLimits(node->left, node->val, min);
            bool validRight = validateBSTLimits(node->right, max, node->val);
            return validLeft && validRight;
        }
};
