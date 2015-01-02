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
        connectRecur(root);
    }

    void connectRecur(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            } else if (root->next) {
                TreeLinkNode *current = root->next;
                while(current) {
                    if (current->left) {
                        root->left->next = current->left;
                        break;
                    } else if (current->right) {
                        root->left->next = current->right;
                        break;
                    } else {
                        current = current->next;
                    }
                }
            }
        }
        if (root->right) {
            if (root->next) {
                TreeLinkNode *current = root->next;
                while(current) {
                    if (current->left) {
                        root->right->next = current->left;
                        break;
                    } else if (current->right) {
                        root->right->next = current->right;
                        break;
                    } else {
                        current = current->next;
                    }
                }
            } else {
                root->right->next = NULL;
            }
        }
        connectRecur(root->right);
        connectRecur(root->left);
    }
};
