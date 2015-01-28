class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2) {
            return 0;
        }
        vector<int> length(s.size(), 0);
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                length[i] = 0;
            } else {
                if (i == 0) {
                    length[i] = 0;
                } else {
                    if (s[i - 1] == '(') {
                        length[i] = 2;
                        if (i > 1) {
                            length[i] += length[i - 2];
                        }
                    } else {
                        int index_to_check = i - 1 - length[i - 1];
                        if (index_to_check >= 0) {
                            if (s[index_to_check] == '(') {
                                length[i] = i - index_to_check + 1;
                                if (index_to_check > 0) {
                                    length[i] += length[index_to_check - 1];
                                }
                            }
                        }
                    }
                }
            }
        }
        return *max_element(length.begin(), length.end());
    }
};
