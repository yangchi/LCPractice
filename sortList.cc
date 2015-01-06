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

        /* merge [first ... second/NULL) and [second ... last/NULL) */
        ListNode *merge_2(ListNode *first, ListNode *second, ListNode *last) {
            if (!first) {
                return second;
            }

            if (!second) {
                return first;
            }

            ListNode *head = NULL, *current = NULL;
            ListNode *first_current = first, *second_current = second;
            if (first->val < second->val) {
                head = first;
                head->next = merge(first->next, second, last);
            } else {
                head = second;
                head->next = merge(first, second->next, last);
            }

            return head;

            /*
               current = head;
               while(first_current && first_current != second && second && second_current != last) {
               if (first_current->val < second_current->val) {
               current->next = first_current;
               first_current = first_current->next;
               } else {
               current->next = second_current;
               second_current = second_current->next;
               }
               current = current->next;
               }

               if(first_current && first_current != second) {
               current = first_current;
               while(current->next != second) {
               current = current->next;
               }
               current->next = last;
               }

               if (second_current && second_current != last) {
               current = second_current;
               }
               return head;
               */
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
