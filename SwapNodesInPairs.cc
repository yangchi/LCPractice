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
        ListNode *swapPairs(ListNode *head) {
            ListNode *curr = head;
            ListNode *nextpair = head, *prevpair = NULL;
            while(curr) {
                if(!nextpair || !nextpair->next) {
                    break;
                }
                ListNode *firstnode = nextpair;
                ListNode *secondnode = nextpair->next;
                nextpair = secondnode->next;
                if(!prevpair) {
                    head = secondnode;
                }
                else {
                    prevpair->next = secondnode;
                }
                prevpair = firstnode;
                secondnode->next = firstnode;
                firstnode->next = nextpair;
                curr = nextpair;
            }
            return head;
        }
};
