class Solution {
    public:
        vector<string> wordBreak(string s, unordered_set<string> &dict) {
            vector<vector<string>> broken_substr;
            for(int i = 0; i < s.size(); i++) {
                broken_substr.push_back(vector<string>());
            }

            for(int length = 1; length <= s.size(); length++) {
                string current = s.substr(0, length);
                if (dict.find(current) != dict.end()) {
                    broken_substr[length - 1].push_back(current);
                }
                for (int breakpoint = 1; breakpoint < length; breakpoint++) {
                    if (!broken_substr[breakpoint - 1].empty() && dict.find(s.substr(breakpoint, length - breakpoint)) != dict.end()) {
                        for (auto str : broken_substr[breakpoint - 1]) {
                            if (str != "") {
                                broken_substr[length - 1].push_back(str + " " + s.substr(breakpoint, length - breakpoint));
                            } else {
                                broken_substr[length = 1].push_back(s.substr(breakpoint, length - breakpoint));
                            }
                        }
                    }
                }
            }

            return broken_substr[s.size() - 1];
        }
};
