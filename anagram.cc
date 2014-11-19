class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, vector<string>> sorted_to_raw;
        for(auto str : strs) {
            string temp{str};
            sort(temp.begin(), temp.end());
            if(sorted_to_raw.find(temp) == sorted_to_raw.end()) {
                sorted_to_raw[temp] = vector<string>();
            }
            sorted_to_raw[temp].push_back(str);
        }
        for(auto kv : sorted_to_raw) {
            if(kv.second.size() > 1) {
                result.insert(result.end(), kv.second.begin(), kv.second.end());
            }
        }
        return result;
    }
};
