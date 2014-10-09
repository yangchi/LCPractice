/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return;
        else
            root->next = NULL;
        DFSwithDangling(root, root->next);
    }    
    void DFSwithDangling(TreeLinkNode *root, TreeLinkNode *dangling)
    {
        if(!root)
            return;
        if(root->left)
            root->left->next = root->right;
        while(dangling && !dangling->left && !dangling->right)
            dangling = dangling->next;
        if(dangling && root->right)
        {
            if(dangling->left)
                root->right->next = dangling->left;
            else
                root->right->next = dangling->right;
        }
        else if(dangling && root->left)
        {
            if(dangling->left)
                root->left->next = dangling->left;
            else
                root->left->next = dangling->right;
        }
        else if(root->right)
            root->right->next = NULL;
        DFSwithDangling(root->right, root->right ? root->right->next: NULL);
        DFSwithDangling(root->left, root->left ? root->left->next: NULL);
    }
};
