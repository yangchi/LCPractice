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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result = NULL;
        ListNode *result_current = result;
        ListNode *l1_current = l1, *l2_current = l2;
        int carry = 0;
        int current_result = 0;
        while(l1_current && l2_current) {
            current_result = carry + l1_current->val + l2_current->val;
            carry = current_result / 10;
            current_result %= 10;
            if(!result) {
                result = new ListNode(current_result);
                result_current = result;
            } else {
                result_current->next = new ListNode(current_result);
                result_current = result_current->next;
            }
            l1_current = l1_current->next;
            l2_current = l2_current->next;
        }
        while(l1_current) {
            current_result = l1_current->val + carry;
            carry = current_result / 10;
            current_result %= 10;
            if(!result) {
                result = new ListNode(current_result);
                result_current = result;
            } else {
                result_current->next = new ListNode(current_result);
                result_current = result_current->next;
            }
            l1_current = l1_current->next;
        }
        while(l2_current) {
            current_result = l2_current->val + carry;
            carry = current_result / 10;
            current_result %= 10;
            if(!result) {
                result = new ListNode(current_result);
                result_current = result;
            } else {
                result_current->next = new ListNode(current_result);
                result_current = result_current->next;
            }
            l2_current = l2_current->next;
        }
        if(carry == 1) {
            result_current->next = new ListNode(1);
        }
        return result;
    }
};
