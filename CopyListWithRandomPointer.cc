/**
 ** Definition for singly-linked list with a random pointer.
 ** struct RandomListNode {
 **     int label;
 **     RandomListNode *next, *random;
 **     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 ** };
 **/
class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            if (!head)
                return NULL;
            map<RandomListNode*, int> original_addr_pos;
            map<int, RandomListNode*> original_pos_addr;
            map<int, int> original_source_dest_pos;
            map<int, RandomListNode *> new_pos_addr;
            RandomListNode *current = head;
            int position = 0;
            while(current) {
                original_addr_pos[current] = position;
                original_pos_addr[position] = current;
                current = current->next;
                position++;
            }
            current = head;
            position = 0;
            while(current) {
                if (!current->random)
                    original_source_dest_pos[position++] = -1;
                else
                    original_source_dest_pos[position++] = original_addr_pos[current->random];
                current = current->next;
            }

            /* establish new list */
            RandomListNode * newHead = new RandomListNode(head->label);
            new_pos_addr[0] = newHead;
            current = newHead;
            int newlist_pos = 1;
            while(newlist_pos < position) {
                RandomListNode * newNode = new RandomListNode(original_pos_addr[newlist_pos]->label);
                new_pos_addr[newlist_pos] = newNode;
                current->next = newNode;
                newlist_pos++;
                current = newNode;
            }
            current = newHead;
            newlist_pos = 0;
            while(current) {
                if (original_source_dest_pos[newlist_pos] == -1)
                    current->random = NULL;
                else
                    current->random = new_pos_addr[original_source_dest_pos[newlist_pos]];
                newlist_pos++;
                current = current->next;
            }
            return newHead;
        }
};
