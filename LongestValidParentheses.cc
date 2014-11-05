#include <vector>
#include <iostream>
#include <string>

using namespace std;


class Solution {
    public:
        int longestValidParentheses(string s) {
            if(s.empty()) {
                return 0;
            }
            vector<int> dp(s.size(), 0);
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == '(') { // no need to update
                    continue;
                } else {
                    if(i == 0) { //no need to update
                        continue;
                    } else {
                        if(s[i - 1] == '(') { //s_i is ) and s_i-1 is (
                            dp[i] = 2;
                            if(i > 1) {
                                dp[i] += dp[i - 2];
                            }
                        } else { //s_i is ) and s_i-1 is also ), need to check dp[i - dp[i-1] - 1]  
                            if(dp[i - 1] > 0) {
                                if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                                    dp[i] = dp[i - 1] + 2;
                                    if(i - dp[i-1] - 1 > 0) {
                                        dp[i] += dp[i - dp[i - 1] - 2];
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return *max_element(dp.begin(), dp.end());
        }
};


int main()
{
    Solution sol;
    cout << sol.longestValidParentheses("") << endl;
}
