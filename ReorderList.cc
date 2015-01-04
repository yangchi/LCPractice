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
    void reorderList(ListNode *head) {
        if (!head || !head->next) {
            return;
        }
        int length = 0;
        ListNode *current = head;
        while(current) {
            length++;
            current = current->next;
        }
        if (length < 3) {
            return;
        }
        current = head;
        int half = length / 2;
        while(--half > 0) {
            current = current->next;
        }
        if (length % 2 == 1) {
            current = current->next;
        }
        ListNode *second_half = reverseList_2(current->next);
        if (!second_half) {
            return;
        }
        /* tangle them */
        current = head;
        ListNode *first_half_next = head->next;
        ListNode *second_half_next = second_half->next;
        while(second_half) {
            current->next = second_half;
            second_half->next = first_half_next;
            second_half = second_half_next;
            if (second_half_next) {
                second_half_next = second_half_next->next;
            }
            current = first_half_next;
            first_half_next = first_half_next->next;
        }
        current->next = NULL;
    }

    ListNode *reverseList(ListNode *node) {
        if (!node || !node->next) {
            return node;
        }

        ListNode *newhead = reverseList(node->next);
        node->next->next = node;
        node->next = NULL;
        return newhead;
    }

    ListNode * reverseList_2(ListNode *node) {
        if (!node) {
            return NULL;
        }

        if (!node->next) {
            return node;
        }

        ListNode *current = node;
        ListNode *prev = NULL;
        while(current) {
            ListNode *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        return prev;
    }
};
