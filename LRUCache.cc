#include <map>
#include <iostream>

using namespace std;

struct DoublyLinkedListNode {
    DoublyLinkedListNode *prev, *next;
    int key;
    int value;
    DoublyLinkedListNode(int key, int value)
        : key(key), value(value), prev(NULL), next(NULL)
    {}
};

class LRUCache{
    private:
        int capacity;
        DoublyLinkedListNode *list, *tail;
        map<int, DoublyLinkedListNode *> keynode_mapper;

    public:
        LRUCache(int capacity)
            : capacity(capacity)
        {
            list = NULL;
            tail = NULL;
        }

        void moveToFront(DoublyLinkedListNode *node) {
            if (node == list) {
                return;
            }
            node->prev->next = node->next;
            if (node->next)
                node->next->prev = node->prev;
            if(tail == node) {
                tail = node->prev;
            }
            node->prev = NULL;
            list->prev = node;
            node->next = list;
            list = node;
        }

        int get(int key) {
            if(keynode_mapper.find(key) != keynode_mapper.end()) {
                moveToFront(keynode_mapper.find(key)->second);
                return keynode_mapper[key]->value;
            } else {
                return -1;
            }
        }

        void set(int key, int value) {
            if (capacity <= 0) {
                return;
            }
            if(get(key) != -1) {
                keynode_mapper[key]->value = value;
            } else {
                DoublyLinkedListNode *newnode = new DoublyLinkedListNode(key, value);
                if (!list) {
                    list = newnode;
                    tail = newnode;
                } else if (list == tail) {
                    if (capacity > 1) {
                        list->prev = newnode;
                        newnode->next = list;
                        list = newnode;
                    } else {
                        keynode_mapper.erase(list->key);
                        delete list;
                        list = newnode;
                        tail = newnode;
                    }
                } else {
                    if (keynode_mapper.size() == capacity) {
                        int lastKey = tail->key;
                        keynode_mapper.erase(lastKey);
                        DoublyLinkedListNode *newLast = tail->prev;
                        if (newLast)
                            newLast->next = NULL;
                        delete tail;
                        tail = newLast;
                    }
                    list->prev = newnode;
                    newnode->next = list;
                    list = newnode;
                }
                keynode_mapper[key] = newnode;
            }
        }
};

int main()
{
    LRUCache sol(1);
    sol.set(2, 1);
    cout << sol.get(2) << endl;
    sol.set(3, 2);
    cout << sol.get(2) << endl;
    cout << sol.get(3) << endl;
}
