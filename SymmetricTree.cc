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
        bool isSymmetric(TreeNode *root) {
            return (!root || isSymmetricRecur(root->left, root->right));
        }

        bool isSymmetricRecur(TreeNode *tree1, TreeNode *tree2) {
            if(!tree1 && !tree2)
                return true;
            if(!tree1 || !tree2)
                return false;
            if(tree1->val != tree2->val)
                return false;
            return isSymmetricRecur(tree1->left, tree2->right) && isSymmetricRecur(tree1->right, tree2->left);
        }
};
