#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void PrintList(ListNode *list, ListNode *end) {
    ListNode *print = list;
    while(print && print != end) {
        cout << print->val << " -> ";
        print = print->next;
    }
    if (print && print == end) {
        cout << end->val <<endl;
    } else {
        cout << "NULL\n";
    }
}

class Solution {
    public:
        ListNode *sortList(ListNode *head) {
            if (!head)
                return head;
            ListNode *last = head;
            while(last->next)
                last = last->next;
            head = mergesort(head, last);
            return head;
        }

        ListNode * mergesort(ListNode *list, ListNode *last) {
            cout << "mergesort: ";
            if (list) {
                cout << "list : " << list->val;
            }
            if (last) {
                cout << " last : " << last->val;
            }
            cout << endl;
            if (!list || !list->next || list == last)
                return list;
            ListNode *left = list, *right = list;
            ListNode *preleft = NULL;
            while (right && right->next && right != last) {
                preleft = left;
                left = left->next;
                right = right->next->next;
            }
            left = list;
            right = preleft->next;
            preleft->next = NULL;
            ListNode *newLeftHead = mergesort(left, preleft);
            ListNode *newRightHead = mergesort(right, last);
            list = merge(newLeftHead, newRightHead, last->next);
            cout<< "After merge: ";
            cout << "list : ";
            if (list )
                cout << list->val<<endl;
            else
                cout << "NULL\n";
            cout << "last : ";
            if (last)
                cout << last->val<<endl;
            else
                cout << "NULL\n";
            PrintList(list, NULL);
            return list;
        }

        ListNode * merge (ListNode *left, ListNode *right, ListNode *lastNext) {
            cout << "merge: ";
            if (left) {
                cout << "\tleft : " << left->val << endl;
                PrintList(left, NULL);
            }
            if (right) {
                cout << "\tright : " << right->val << endl;
                PrintList(right, NULL);
            }
            if(left == right)
                return left;
            ListNode *leftmost = left;
            ListNode *leftend = left, *rightend = right;
            while(leftend && leftend->next != NULL) {
                leftend = leftend->next;
            }
            while(rightend && rightend->next != lastNext) {
                rightend = rightend->next;
            }
            if(!left) {
                return right;
            }
            if (!right) {
                return left;
            }
            if(left->val < right->val) {
                leftmost = left;
                leftmost->next = merge(left->next, right, lastNext);
            } else {
                leftmost = right;
                leftmost->next = merge(left, right->next, lastNext);
            }
            cout << "End of merge: ";
            PrintList(leftmost, lastNext);
            return leftmost;
        }
};

int main()
{
    ListNode *first = new ListNode(3);
    ListNode *second = new ListNode(4);
    ListNode *third = new ListNode(1);
    first->next = second;
    second->next = third;
    Solution mySolution;
    ListNode *result = mySolution.sortList(first);
    PrintList(result, NULL);
}
