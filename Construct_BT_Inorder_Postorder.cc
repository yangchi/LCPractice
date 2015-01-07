/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

typedef vector<int>::iterator iter;

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeRecur(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    TreeNode *buildTreeRecur(iter inorder_begin, iter inorder_end, iter postorder_begin, iter postorder_end) {
        if (inorder_begin == inorder_end || postorder_begin == postorder_end) {
            return NULL;
        }

        int tree_size = inorder_end - inorder_begin;
        if (postorder_end - postorder_begin != tree_size) {
            return NULL;
        }

        TreeNode *root = new TreeNode(*(postorder_end - 1));
        iter root_iter_inorder = find(inorder_begin, inorder_end, root->val);
        iter inorder_left_begin = inorder_begin;
        iter inorder_left_end = root_iter_inorder;
        iter inorder_right_begin = root_iter_inorder + 1;
        iter inorder_right_end = inorder_end;
        iter postorder_left_begin = postorder_begin;
        iter postorder_left_end = postorder_begin + (inorder_left_end - inorder_left_begin);
        iter postorder_right_begin = postorder_left_end;
        iter postorder_right_end = postorder_end - 1;
        root->left = buildTreeRecur(inorder_left_begin, inorder_left_end, postorder_left_begin, postorder_left_end);
        root->right = buildTreeRecur(inorder_right_begin, inorder_right_end, postorder_right_begin, postorder_right_end);
        return root;
    }
};
