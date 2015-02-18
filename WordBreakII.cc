#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        vector<string> wordBreak(string s, unordered_set<string> &dict) {
            vector<vector<string>> broken(s.size(), vector<string>());
            for (int i = s.size() - 1; i>= 0; i--) {
                string current = s.substr(i, s.size() - i);
                if (dict.find(current) != dict.end()) {
                    broken[i].push_back(current);
                }

                for (int j = i + 1; j < s.size(); j++) {
                    string first = s.substr(i, j - i);
                    string second = s.substr(j, s.size() - j);
                    if (!broken[j].empty() && dict.find(first) != dict.end()) {
                        for (auto sub : broken[j]) {
                            if (sub == "") {
                                broken[i].push_back(first);
                            } else {
                                broken[i].push_back(first + " " + sub);
                            }
                        }
                    }
                }
            }

            return broken[0];
        }
};

int main()
{
    Solution sol;
    unordered_set<string> dict = {"a", "b"};
    vector<string> res = sol.wordBreak("ab", dict);
}
