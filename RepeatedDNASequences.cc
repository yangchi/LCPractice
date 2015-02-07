class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) {
            return vector<string>();
        }
        vector<string> result;
        hash<string> hash_fn;
        map<int, int> substr_occurrance;
        for(int i = 0; i <= s.size() - 10; i++) {
            string current = s.substr(i, 10);
            if (++substr_occurrance[hash_fn(current)] == 2) {
                result.push_back(current);
            }
        }
        return result;
    }
};
