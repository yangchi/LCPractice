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
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

            if(inorder.empty() || postorder.empty())
                return NULL;
            TreeNode *root = NULL;
            if(inorder.size() == 1 && postorder.size() == 1)
            {
                root = new TreeNode(inorder[0]);
                return root;
            }
            int rootval = *(postorder.end()-1);
            root = new TreeNode(rootval);

            vector<int>::iterator root_inorder_pos = find(inorder.begin(), inorder.end(), rootval);
            int leftsize = root_inorder_pos - inorder.begin();
            vector<int> inorder_left(inorder.begin(), root_inorder_pos);
            vector<int> inorder_right(root_inorder_pos+1, inorder.end());
            vector<int> postorder_left(postorder.begin(), postorder.begin() + leftsize);
            vector<int> postorder_right(postorder.begin()+leftsize, postorder.end()-1);
            root->left = buildTree(inorder_left, postorder_left);
            root->right = buildTree(inorder_right, postorder_right);
            return root;
        }
};
