class LRUCache{
    public:
        int cap;
        map<int, int> keyvalue;
        map<int, int> keyage;

        LRUCache(int capacity) {
            cap = capacity;
        }

        int get(int key) {
            auto iter = keyvalue.find(key);
            int return_value;
            if(iter == keyvalue.end())
                return -1;
            for(iter = keyvalue.begin(); iter != keyvalue.end(); iter++) {
                if (iter->first != key)
                    keyage[key]++;
                else
                    return_value  = iter->second;
            }
            return return_value;
        }

        void set(int key, int value) {
            if(keyvalue.size() < cap) {
                keyvalue[key] = value;
                keyage[key] = keyage.find(key) == keyage.end() ? 0 : keyage[key] + 1;
            } else {
                auto iter = keyvalue.find(key);
                if (iter != keyvalue.end()) {
                    keyvalue[key] = value;
                } else {
                    int old_key = oldest();
                    keyvalue.erase(old_key);
                    keyage.erase(old_key);
                    keyvalue[key] = value;
                }
                for(iter = keyage.begin(); iter != keyage.end(); iter++) {
                    if(iter->first != key)
                        keyage[iter->first]++;
                }
            }
        }

        int oldest() {
            int age = 0;
            int oldkey = -1;
            map<int, int>::iterator iter;
            for(iter = keyage.begin(); iter != keyage.end(); iter++) {
                if (iter->second > age) {
                    age = iter->second;
                    oldkey = iter->first;
                }
            }
            return oldkey;
        }
};
