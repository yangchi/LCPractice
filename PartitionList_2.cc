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
    ListNode *partition(ListNode *head, int x) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *small_current = NULL, *big_current = NULL;
        ListNode *small_head = NULL, *big_head = NULL;
        ListNode *current = head;
        while(current) {
            if (current->val < x) {
                if (!small_head) {
                    small_head = current;
                }
                if (!small_current) {
                    small_current = current;
                } else {
                    small_current->next = current;
                    small_current = current;
                }
            } else {
                if (!big_head) {
                    big_head = current;
                }

                if (!big_current) {
                    big_current = current;
                } else {
                    big_current->next = current;
                    big_current = current;
                }
            }
            current = current->next;
        }

        if (big_current) {
            big_current->next = NULL;
        }

        if (!small_head) {
            return big_head;
        }

        small_current->next = big_head;
        return small_head;
    }
};
