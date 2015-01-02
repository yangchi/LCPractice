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
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) {
            return vector<int>();
        }
        stack<TreeNode *> s;
        vector<int> result;
        s.push(root);
        while(!s.empty()) {
            TreeNode *current = s.top();
            s.pop();
            result.push_back(current->val);
            if (current->right) {
                s.push(current->right);
            }
            if (current->left) {
                s.push(current->left);
            }
        }
        return result;
    }
};
