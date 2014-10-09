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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || !head->next)
            return head;
        ListNode *xnode = new ListNode(x);
        ListNode *current = head, *small;
        small = new ListNode(-1);
        ListNode *smallcurrent = small, *bigcurrent = xnode;
        while(current)
        {
            if(current->val < x)
            {
                smallcurrent->next = current;
                smallcurrent = smallcurrent->next;
            }
            else
            {
                bigcurrent->next = current;
                bigcurrent = bigcurrent->next;
            }
            current = current->next;
        }
        bigcurrent->next = NULL;
        head = small->next;
        delete small;
        smallcurrent->next = xnode->next;
        if(!head)
            head = xnode->next;
        delete xnode;
        return head;
    }
};