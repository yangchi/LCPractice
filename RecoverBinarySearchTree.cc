#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *pre = NULL, *first = NULL, *second = NULL;
        recoverTree(root, &pre, &first, &second);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        return;
    }

    void recoverTree(TreeNode *node, TreeNode **pre, TreeNode **first, TreeNode **second) {
        if (!node) {
            return;
        }

        recoverTree(node->left, pre, first, second);
        if (pre && *pre && (*pre)->val > node->val) {
            if (!*first) {
                *first = *pre;
            }
            *second = node;
        } else {
            *pre = node;
        }

        recoverTree(node->right, pre, first, second);
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    sol.recoverTree(root);
}
