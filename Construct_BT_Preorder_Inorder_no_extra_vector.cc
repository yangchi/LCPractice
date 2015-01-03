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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeRecur(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode *buildTreeRecur(vector<int> & preorder, int pre_begin, int pre_end, vector<int> & inorder, int in_begin, int in_end) {
        TreeNode *root = NULL;
        if (preorder.empty() || pre_begin == pre_end) {
            return root;
        }
        int root_value = preorder[pre_begin];
        root = new TreeNode(root_value);

        vector<int>::iterator root_iter = find(inorder.begin() + in_begin, inorder.begin() + in_end, root_value);
        int left_tree_size = root_iter - inorder.begin() - in_begin;
        root->left = buildTreeRecur(preorder, pre_begin + 1, pre_begin + left_tree_size + 1, inorder, in_begin, in_begin + left_tree_size);
        root->right = buildTreeRecur(preorder, pre_begin + 1 + left_tree_size, pre_end, inorder, in_begin + left_tree_size + 1, in_end);
        return root;
    }
};
