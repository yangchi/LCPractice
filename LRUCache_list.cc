class LRUCache{
private:
    map<int, int> data; //original key->value
    list<int> keylist; // a list of keys, FIFO
    map<int, list<int>::iterator> prevs; //map from key to an iter in the keylist, for random access
    int capacity;

public:
    LRUCache(int capacity)
        : capacity(capacity) {}

    int refresh(int key) {
        list<int>::iterator iter = prevs.find(key)->second;
        keylist.erase(iter);
        keylist.push_back(key);
        prevs.erase(key);
        prevs.insert(std::pair<int, list<int>::iterator>(key, --keylist.end()));
    }

    int get(int key) {
        if (data.find(key) == data.end()) {
            return -1;
        }

        refresh(key);
        return data[key];
    }

    void set(int key, int value) {
        if (data.find(key) != data.end()) {
            //already exists: update list and prevs
            refresh(key);
            data[key] = value;
        } else {
            // not exists, need to check current size
            if (data.size() == capacity) {
                // full size, pop oldest one, push new one in
                int oldest_key = keylist.front();
                data.erase(oldest_key);
                keylist.pop_front();
                prevs.erase(oldest_key);
            }
            data[key] = value;
            keylist.push_back(key);
            prevs.insert(std::pair<int, list<int>::iterator>(key, --keylist.end()));
        }
    }
};
