
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head)
            return NULL;
        if(m == n || !head->next)
            return head;
        int counter = 0;
        ListNode *zero = head, *first, *second, *third, *originalfirst;
        first = head;
        counter = m;
        while(--counter)
        {
            zero = first;
            first = first->next;
        }
        originalfirst = first;
        second = first->next;
        third = second ? second->next : NULL;
        counter = n-m;
        while(counter--)
        {
            second->next = first;
            first = second;
            second = third;
            third = third ? third->next : NULL;
        }
        if(m == 1)
            head = first;
        else
            zero->next = first;
        originalfirst->next = second;
        return head;
    }
};
