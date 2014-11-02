#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *reverseKGroup(ListNode *head, int k) {
            if(k == 0 || k == 1)
                return head;
            ListNode *fast = head, *slow = head;
            int count = 0;
            for(count = 0 ; count < k - 1; count++) {
                if(!fast || !fast->next) {
                    break;
                }
                fast = fast->next;
            }
            if(count < k - 1)
                return head;
            ListNode *prev = NULL;
            while(fast) {
                reverseWholeList(slow, fast, prev, fast->next);
                if(!prev)
                    head = fast;
                prev = slow;
                ListNode *temp = slow;
                slow = fast;
                fast = temp;
                count = movePointers(&fast, &slow, k);
                if(count != k) {
                    cout << "no enough move : " << count << endl;
                    break;
                }
            }
            return head;
        }

        int movePointers(ListNode **fast, ListNode **slow, int k) {
            cout << "Moving : " << (*fast)->val << " and " << (*slow)->val << endl;
            int count = 0;
            while(count < k) {
                cout << "while in move" << endl;
                if(!(*fast) || !(*fast)->next)
                    break;
                *fast = (*fast)->next;
                *slow = (*slow)->next;
                count++;
            }
            return count;
        }

        void reverseWholeList(ListNode *first, ListNode *last, ListNode *prev, ListNode *next) {
            cout << "reversing : " << first->val << " to " << last->val << endl;
            //cout << " and the next is " << next->val << endl;
            ListNode *curr = first;
            ListNode *beforecurr = NULL, *aftercurr = curr->next;
            while(curr != last) {
                cout << "while in reverse: " << curr->val << endl;
                ListNode *nextnext = aftercurr->next;
                aftercurr->next = curr;
                if(beforecurr)
                    curr->next = beforecurr;
                beforecurr = curr;
                curr = aftercurr;
                aftercurr = nextnext;
            }
            if(prev)
                prev->next = last;
            first->next = next;
        }
};

int main()
{
    Solution sol;
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    ListNode *newhead = sol.reverseKGroup(list, 2);
    ListNode *ptr = newhead;
    while(ptr) {
        cout << ptr->val << "\t" ;
        ptr = ptr->next;
    }
    cout << endl;
}
