/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            if (!head || !head->next || m == n) {
                return head;
            }
            ListNode *third = head;
            int counter = n;
            while(--counter > 0) {
                third = third->next;
            }

            ListNode *temp = third;
            third = third->next;
            temp->next = NULL;

            ListNode *second = head;
            counter = m ;
            while(--counter > 0) {
                temp = second;
                second = second->next;
            }
            if (second == head) {
                temp = reverseList(second);
                second->next = third;
                return temp;
            } else {
                temp->next = reverseList(second);
                second->next = third;
                return head;
            }

        }

        ListNode *reverseList(ListNode *list) {
            if (!list || !list->next) {
                return list;
            }

            ListNode *tail = list, *prev = NULL;
            while(tail->next) {
                prev = tail;
                tail = tail->next;
            }
            prev->next = NULL;
            tail->next = reverseList(list);
            return tail;
        }
};
