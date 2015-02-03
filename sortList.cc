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
    ListNode *sortList(ListNode *head) {
        return merge(head);
    }

    ListNode *merge(ListNode *node) {
        if (!node || !node->next) {
            return node;
        }

        ListNode *fast = node, *slow = node, *half = NULL;
        while(fast && slow && slow->next && fast->next) {
            half = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = half;
        half = slow;
        fast->next = NULL;
        //now fast is the last of first half, half is the first of second half

        node = merge(node);
        half = merge(half);
        node = mergeTwoList(node, half);
        return node;
    }

    ListNode* mergeTwoList(ListNode *first, ListNode *second) {
        if (!first) {
            return second;
        }

        if (!second) {
            return first;
        }

        ListNode *first_next = first->next;
        ListNode *second_next = second->next;

        if (first->val < second->val) {
            first->next = mergeTwoList(first_next, second);
        } else {
            first_next = first;
            first = second;
            first->next = mergeTwoList(first_next, second_next);
        }

        return first;
    }
};
