class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> parlin_table;
        for (int i = 0; i < s.size(); i++) {
            parlin_table.push_back(vector<bool>(s.size(), false));
            parlin_table[i][i] = true;
        }

        for(int length = 2; length <= s.size(); length++) {
            for(int start = 0; start + length <= s.size(); start++) {
                if (length > 2) {
                    parlin_table[start][start + length - 1] = parlin_table[start + 1][start + length - 1 - 1] && s[start] == s[start + length - 1];
                } else {
                    parlin_table[start][start + length - 1] = s[start] == s[start + length - 1];
                }

            }
        }

        vector<vector<string>> result;
        vector<string> temp;
        partition_recur(s, 0, s.size() - 1, parlin_table, result, temp);
        return result;
    }

    void partition_recur(string s, int start, int end, const vector<vector<bool>> & table, vector<vector<string>> & result, vector<string> & current_vec) {
        if (start > end) {
            result.push_back(current_vec);
        }

        for (int split = start; split <= end; split++) {
            if (table[start][split]) {
                current_vec.push_back(s.substr(start, split - start + 1));
                partition_recur(s, split + 1, end, table, result, current_vec);
                current_vec.pop_back();
            }
        }
    }
};
