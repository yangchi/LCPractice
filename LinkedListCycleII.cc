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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return NULL;
        }

        ListNode *fast = head, *slow = head;

        while (true) {
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
                if (slow == fast) {
                    break;
                }
            } else {
                return NULL;
            }
        }

        fast = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
