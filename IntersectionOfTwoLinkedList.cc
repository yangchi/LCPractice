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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }
        int lengthA = 0, lengthB = 0;
        ListNode *currentA = headA, *currentB = headB;
        while(currentA->next) {
            currentA = currentA->next;
            lengthA++;
        }
        while(currentB->next) {
            currentB = currentB->next;
            lengthB++;
        }
        if (currentA == currentB) { // there was intesection
            currentA = headA;
            currentB = headB;
            if (lengthA > lengthB) {
                for (int i = 0; i < lengthA - lengthB; i++) {
                    currentA = currentA->next;
                }
            } else if (lengthB > lengthA) {
                for (int i = 0; i < lengthB - lengthA; i++) {
                    currentB = currentB->next;
                }
            }
            while(currentA != currentB) {
                currentA = currentA->next;
                currentB = currentB->next;
            }
            return currentA;
        } else {
            return NULL;
        }
    }
};
