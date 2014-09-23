/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int carry = 0;
            int current = 0;
            ListNode *result = NULL, *restore = NULL;
            ListNode *l1pos = l1, *l2pos = l2;
            while(l1pos && l2pos){
                current = l1pos->val + l2pos->val + carry;
                carry = current / 10;
                current %= 10;
                ListNode *tempNode = new ListNode(current);
                if(result)
                    result->next = tempNode;
                else
                    restore = tempNode;
                result = tempNode;
                l1pos = l1pos->next;
                l2pos = l2pos->next;
            }
            while(l1pos){
                ListNode *tempNode = new ListNode((carry + l1pos->val)%10);
                carry = (carry + l1pos->val) / 10;
                if(result)
                    result->next = tempNode;
                else
                    restore = tempNode;
                result = tempNode;
                l1pos = l1pos->next;
            }
            while(l2pos){
                ListNode *tempNode = new ListNode((carry + l2pos->val)%10);
                carry = (carry + l2pos->val) / 10;
                if(result)
                    result->next = tempNode;
                else
                    restore = tempNode;
                result = tempNode;
                l2pos = l2pos->next;
            }
            if(carry){
                ListNode *tempNode = new ListNode(carry);
                result->next = tempNode;
            }
            return restore;
        }
};
