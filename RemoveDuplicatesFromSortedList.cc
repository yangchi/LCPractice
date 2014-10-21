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
        ListNode *deleteDuplicates(ListNode *head) {
            ListNode *current = head;
            ListNode *last = NULL;
            if(!head)
                return head;
            if(!head->next)
                return head;
            while(current) {
                if (!last) {
                    last = current;
                    current = current->next;
                } else {
                    if (current->val == last->val) {
                        current = current->next;
                    } else {
                        if (last->next != current) {
                            ListNode *temp = last->next;
                            ListNode *tempNext = temp->next;
                            while(temp != current) {
                                delete temp;
                                temp = tempNext;
                                if (!temp)
                                    break;
                                tempNext = temp->next;
                            }
                            last->next = current;
                            last = current;
                            current = current->next;
                        } else {
                            last = current;
                            current = current->next;
                        }
                    }
                }
            }
            if(last->next != current) {
                ListNode *temp = last->next;
                ListNode *tempNext = temp->next;
                while(temp != current) {
                    delete temp;
                    temp = tempNext;
                    if(!temp)
                        break;
                    tempNext = temp->next;
                }
                last->next = current;
            }
            return head;
        }
};
