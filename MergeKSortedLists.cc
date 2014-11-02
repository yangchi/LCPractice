#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            cout << "Level 1" << endl;
            return mergeHelper(lists, 0, lists.size());
        }

        ListNode *merge(ListNode *first, ListNode *second) {
            cout << "Level 3" << endl;
            if(!first && !second)
                return NULL;
            if(!first)
                return second;
            if(!second)
                return first;
            ListNode *fake_head = new ListNode(INT_MIN);
            ListNode *current = fake_head;
            while(first && second) {
                cout << "While loop. " << endl;
                if(first->val < second->val) {
                    cout << "Take first" << endl;
                    current->next = first;
                    current = current->next;
                    first = first->next;
                } else {
                    cout << "Take second" << endl;
                    current->next = second;
                    current = current->next;
                    second = second->next;
                }
            }
            if(first) {
                current->next = first;
            }
            if(second) {
                current->next = second;
            }
            current = fake_head->next;
            ListNode *printptr = fake_head;
            while(printptr) {
                cout << "Take a look: " << printptr->val << endl;
                printptr = printptr->next;
            }
            delete fake_head;
            return current;
        }

        ListNode *mergeHelper(vector<ListNode *> & list, int begin, int end) {
            cout << "Level 2 " << begin << " " << end << endl;
            if(begin >= end) {
                cout << "begin le end" << endl;
                return NULL;
            }
            if(end - begin == 1) {
                cout << "gap 1" << endl;
                return list[begin];
            }
            int mid = begin + (end - begin) / 2;
            ListNode *firsthalf = mergeHelper(list, begin, mid);
            ListNode *secondhalf = mergeHelper(list, mid, end);
            ListNode *merged = merge(firsthalf, secondhalf);
            return merged;
        }
};

int main()
{
    Solution sol;
    vector<ListNode *> vec;
    ListNode *firstList = new ListNode(1);
    ListNode *secondList = new ListNode(0);
    vec.push_back(firstList);
    vec.push_back(secondList);
    ListNode *result = sol.mergeKLists(vec);
    if(!result) {
        cout << "Empty" << endl;
    } else {
        while(result) {
            cout << result->val << "\t";
            result = result->next;
        }
        cout << endl;
    }
}
