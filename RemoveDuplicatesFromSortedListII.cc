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
            if(!head || !head->next) {
                return head;
            }
            ListNode *last = NULL, *current = head;
            bool dup = false;
            while(current && current->next) {
                if(current->next->val == current->val) {
                    dup = true;
                    current = current->next;
                } else {
                    if(!dup) {
                        last = current;
                        current = current->next;
                    } else {
                        if(current->next->next) {
                            if(current->next->next->val == current->next->val) {
                                current = current->next;
                            } else {
                                if(!last) {
                                    last = head;
                                    ListNode *temp = last->next;
                                    while(last && last != current) {
                                        delete last;
                                        last = temp;
                                        temp = temp->next;
                                    }
                                    last = current->next;
                                    head = last;
                                    delete current;
                                    current = last->next;
                                    dup = false;
                                } else {
                                    ListNode *temp = last->next;
                                    ListNode *tempNext = temp->next;
                                    while(temp && temp != current) {
                                        delete temp;
                                        temp = tempNext;
                                        tempNext = tempNext->next;
                                    }
                                    last->next = current->next;
                                    p;
                                    temp = tempNext;
                                    tempNext = tempNext->next;
                                }
                                last->next = current->next;
                                delete current;
                                current = last->next;
                            }
                        }
                    }
                }
            }
            if(!last) {
                last = head;
                current = last->next;
                while(last) {
                    delete last;
                    last = current;
                    if(!last)
                        break;
                    current = current->next;
                }
                return NULL;
            }
            if(last->next != current) {
                ListNode *temp = last->next;
                current = temp->next;
                while(temp) {
                    delete temp;
                    temp = current;
                    if(!temp)
                        break;
                    current = current->next;
                }
                last->next = NULL;
            }
            return head;
        }
};
