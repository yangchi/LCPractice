/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *current = head, *current_next = head->next;
        while(current_next) {
            if (current->val == current_next->val) {
                current->next = current_next->next;
                delete [] current_next;
                current_next = current->next;
                if (!current->next) {
                    break;
                }
            } else {
                current_next = current_next->next;
                current = current->next;
            }
        }

        return head;
    }
};
