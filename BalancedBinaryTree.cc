#include<iostream>

/**
 ** Definition for binary tree
 ** struct treenode {
 * *     int val;
 * *     treenode *left;
 * *     treenode *right;
 * *     treenode(int x) : val(x), left(null), right(null) {}
 * * };
 * */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        bool isBalanced(TreeNode *root) {
            int maxdepth = 0;
            return isBalancedRecur(root, &maxdepth);
        }

        bool isBalancedRecur(TreeNode *root, int *depth) {
            if(!root){
                *depth = 0;
                return true;
            }
            int leftDepth = 0, rightDepth = 0;
            bool leftBalanced = true, rightBalanced = true;
            if(root->left)
                leftBalanced = isBalancedRecur(root->left, &leftDepth);
            if(root->right)
                rightBalanced = isBalancedRecur(root->right, &rightDepth);
            if(!leftBalanced || !rightBalanced)
                return false;
            *depth = std::max(leftDepth, rightDepth) + 1;
            return abs(leftDepth - rightDepth) < 2;
        }
};

int main() {
    Solution sol;
    TreeNode *root = new TreeNode(1);
    
}
