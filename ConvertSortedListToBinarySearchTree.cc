/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            return new TreeNode(head->val);
        }
        ListNode *prev = NULL, *slow = head, *fast = head;
        while(fast && fast->next && fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        if (prev) {
            prev->next = NULL;
            root->left = sortedListToBST(head);
        } else {
            root->left = NULL;
        }
        ListNode *second_half = slow->next;
        slow->next = NULL;
        root->right = sortedListToBST(second_half);
        return root;
    }

};
