#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if(!head)
                return NULL;
            ListNode *first = head, *second = head;
            int count = 0;
            int length = 0;
            while(first) {
                first = first->next;
                length++;
            }
            k = k % length;
            k = length - k; //without this, it will be right rotate instead of left rotate
            if(k == 0)
                return head;
            first = head;
            while(count++ < k - 1) {
                first = first->next;
            }
            ListNode *newhead = first->next;
            if(!newhead)
                return head;
            second = newhead;
            while(second->next)
                second = second->next;
            first->next = NULL;
            second->next = head;
            head = newhead;
            return head;
        }
};

int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode *newlist = sol.rotateRight(head, 1);
    ListNode *print_ptr = newlist;
    while(print_ptr) {
        std::cout << "node: " << print_ptr->val << std::endl;
        print_ptr = print_ptr->next;
    }
}
