//MLE

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
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            if(preorder.empty() || inorder.empty())
                return NULL;
            TreeNode *root;
            if(preorder.size() == 1 && inorder.size() == 1)
            {
                root = new TreeNode(inorder[0]);
                return root;
            }
            int rootval = preorder[0];
            root = new TreeNode(rootval);
            int leftsize = find(inorder.begin(), inorder.end(), rootval) - inorder.begin();
            vector<int> inorder_left(inorder.begin(), inorder.begin() + leftsize);
            vector<int> inorder_right(inorder.begin() + leftsize + 1, inorder.end());
            vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + leftsize);
            vector<int> preorder_right(preorder.begin() + 1 + leftsize, preorder.end());
            root->left = buildTree(preorder_left, inorder_left);
            root->right = buildTree(preorder_right, inorder_right);
            return root;
        }
};
