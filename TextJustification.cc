#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> fullJustify(vector<string> &words, int L) {
            if (L == 0) {
                return words;
            }
            int index = 0;
            vector<string> result;
            vector<string> cur_line;
            int cur_length = 0;
            while(index < words.size()) {
                int cur_word_l = words[index].size();
                if (cur_line.empty() || cur_length + cur_word_l + cur_line.size() <= L) {
                    cur_length += cur_word_l;
                    cur_line.push_back(words[index]);
                    index++;
                } else {
                    int avg_space = 0;
                    int extra_space = 0;
                    if (cur_line.size() > 2) {
                        avg_space = (L - cur_length) / (cur_line.size() - 1);
                        extra_space = L - cur_length - avg_space * (cur_line.size() - 1);
                    } else {
                        avg_space = L - cur_length;
                    }
                    string cur_line_res = "";
                    for (int i = 0; i < cur_line.size(); i++) {
                        if (i == cur_line.size() - 1) {
                            cur_line_res += cur_line[i];
                        } else {
                            cur_line_res += cur_line[i];
                            cur_line_res += string(avg_space, ' ');
                            if (extra_space-- > 0) {
                                cur_line_res += " ";
                            }
                        }
                    }
                    if (L > cur_line_res.size()) {
                        cur_line_res += string(L - cur_line_res.size(), ' ');
                    }
                    result.push_back(cur_line_res);
                    cur_line.clear();
                    cur_line.push_back(words[index]);
                    cur_length = cur_word_l;
                    index++;
                }
            }

            if (!cur_line.empty()) {
                string lastline = "";
                for (int i = 0; i < cur_line.size(); i++) {
                    lastline += cur_line[i] + " ";
                }
                lastline = lastline.substr(0, lastline.size() - 1);
                lastline += string(L - lastline.size() > 0 ? L - lastline.size() : 0, ' ');
                result.push_back(lastline);
            }

            return result;
        }
};

int main()
{
    Solution sol;
    vector<string> input = {"What", "must", "be", "shall", "be."};
    vector<string> result = sol.fullJustify(input, 12);
    for (auto line : result) {
        cout << "|" << line << "|" << endl;
    }
}
