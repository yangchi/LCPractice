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
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *moving = head, *current_end = head;
        while(current_end->next) {
            ListNode *current = current_end->next;
            while(moving != current_end && moving->val <= current->val && moving->next->val <= current->val) {
                moving = moving->next;
            }

            if (moving->val > current->val) {
                current_end->next = current->next;
                current->next = moving;
                head = current;
                moving = head;
            } else if (moving == current_end) {
                current_end = current;
                moving = head;
            } else {
                current_end->next = current->next;
                current->next = moving->next;
                moving->next = current;
                moving = head;
            }
        }

        return head;
    }
};
