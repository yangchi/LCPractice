class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            vector<bool> valid(s.size() + 1, false);
            for (int length = 1; length <= s.size(); length++) {
                if (dict.find(s.substr(0, length)) != dict.end()) {
                    valid[length] = true;
                } else {
                    for (int cut = 1; cut < length; cut++) {
                        if (valid[cut] && dict.find(s.substr(cut, length - cut)) != dict.end()) {
                            valid[length] = true;
                            break;
                        }
                    }
                }
            }
            return valid[s.size()];
        }
};
