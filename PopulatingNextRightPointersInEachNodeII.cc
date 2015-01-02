#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

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

int main()
{
    Solution sol;
    TreeLinkNode *root = new TreeLinkNode(2);
    root->left = new TreeLinkNode(1);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(0);
    root->left->right = new TreeLinkNode(7);
    root->right->left = new TreeLinkNode(9);
    root->right->right = new TreeLinkNode(1);
    root->left->left->left = new TreeLinkNode(2);
    root->left->right->left = new TreeLinkNode(1);
    root->left->right->right = new TreeLinkNode(0);
    root->right->right->left = new TreeLinkNode(8);
    root->right->right->right = new TreeLinkNode(8);
    root->left->right->right->left = new TreeLinkNode(7);

    sol.connect(root);
}
