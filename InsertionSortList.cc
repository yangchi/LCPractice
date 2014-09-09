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
        ListNode *insertionSortList(ListNode *head) {
            if (!head || !head->next) {
                return head;
            }
            ListNode *pre_current = head;
            ListNode *current = head->next;
            ListNode *gun = head;
            while (current) {
                while(gun->next && gun->val <= current->val && gun->next->val <= current->val && gun->next != current) {
                    gun = gun->next;
                }
                if (!gun->next) {
                    /*gun doesn't have next. Should be all done. */
                    break;
                }
                else if (gun->val > current->val) { 
                    /* gun->val already bigger than current->val, insert current before gun.
                     * this also means gun never moved. So gun = head
                     */
                    pre_current->next = current->next;
                    current->next = gun;
                    head = current;
                    current = pre_current->next;
                    gun = head;
                } else if (gun->next == current) {
                    /* Gun and current adjacent. In this case, if gun->val > current-> value, already cover.
                     * Other wise, just move current and pre_current
                     */
                    pre_current = current;
                    current = current->next;
                    gun = head;
                } else if(gun->next->val > current->val) {
                    /* Gun and current not adjacent. Current should be moved between gun and gun->next */
                    pre_current->next = current->next;
                    current->next = gun->next;
                    gun->next = current;
                    current = pre_current->next;
                    gun = head;
                }
            }
            return head;
        }
};
