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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *first = head, *second = head->next;
        if (first->val != second->val) {
            first->next = deleteDuplicates(second);
        } else {
            int dupValue = second->val;
            ListNode *newValueNode = second->next;
            delete [] first;
            delete [] second;
            while(newValueNode && newValueNode->val == dupValue){
                ListNode *temp = newValueNode;
                newValueNode = newValueNode->next;
                delete [] temp;
            }

            if (!newValueNode) {
                return NULL;
            } else {
                first = deleteDuplicates(newValueNode);
                return first;
            }
        }
    }
};
