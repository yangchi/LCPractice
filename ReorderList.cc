/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 **/
class Solution {
    public:
        void reorderList(ListNode *head) {
            if (!head || !head->next)
                return;
            int length = 0;
            ListNode * current = head;
            while(current) {
                current = current->next;
                length++;
            }

            for(int i = 0; i < length/2; i++) {
                int count = 0;
                current = head;
                ListNode * tail = head;
                while (tail->next->next) {
                    tail = tail->next;
                    count++;
                    if (count < i*2) 
                        current = current->next;
                }
                tail->next->next = current->next;
                current->next = tail->next;
                tail->next = NULL;
            }
        }
};
