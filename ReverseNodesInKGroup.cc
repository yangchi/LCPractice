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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !head->next || k == 1) {
            return head;
        }

        ListNode *kNode = head, *kNodePrev = NULL;
        int counter = k;
        while(kNode && counter > 0) {
            counter--;
            kNodePrev = kNode;
            kNode = kNode->next;
        }

        if (counter > 0) {//not enough nodes
            return head;
        }

        kNodePrev->next = NULL;

        reverseList(head);
        head->next = reverseKGroup(kNode, k);
        return kNodePrev;
    }

    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *current = head, *prev = NULL;
        while(current->next) {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        current->next = reverseList(head);
        return current;
    }
};
