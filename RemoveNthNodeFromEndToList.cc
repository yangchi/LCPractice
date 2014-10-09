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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return head;
        if(!head)
            return head;
        if(!head->next && n == 1)
        {
            free(head);
            return NULL;
        }
        ListNode *fast = head, *slow = head;
        int i = 0;
        while(i++ < n && fast->next)
            fast = fast->next;
        if(!fast->next && i == n)
        {
            head = head->next;
            free(slow);
            return head;
        }
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next->next;
        free(slow->next);
        slow->next = temp;
        return head;
    }
};