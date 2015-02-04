class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            vector<bool> breakable(s.size(), false);
            for(int length = 1; length <= s.size(); length++) {
                if (dict.find(s.substr(0, length)) != dict.end()) {
                    breakable[length - 1] = true;
                    continue;
                }

                for (int breakpoint = 1; breakpoint < length; breakpoint++) {
                    if (breakable[breakpoint - 1] && dict.find(s.substr(breakpoint, length - breakpoint)) != dict.end()) {
                        breakable[length - 1] = true;
                        continue;
                    }
                }
            }

            return breakable[s.size() - 1];
        }
};
