/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return NULL;
        }

        RandomListNode *current = head;
        while(current) {
            RandomListNode *original_next = current->next;
            current->next = new RandomListNode(current->label);
            current->next->next = original_next;
            current = current->next->next;
        }

        current = head;
        while(current) {
            current->next->random = current->random ? current->random->next : NULL;
            current = current->next->next;
        }

        RandomListNode *newList = head->next;
        RandomListNode *new_current = newList;
        current = head;
        while(current) {
            current->next = current->next->next;
            new_current->next = current->next ? current->next->next : NULL;
            current = current->next;
            new_current = new_current->next;
        }

        return newList;
    }
};
