class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            if (s1.size() + s2.size() != s3.size()) {
                return false;
            }

            /*
             * dp[i][j] means if the first (i + j) chars in s3 is a cmobo of first i in s1 and first j in s2
             *
             * Note first i chars in s1 are: s1[0 ... i - 1]
             */
            int dp[s1.size() + 1][s2.size()  + 1];
            for(int i = 0; i <= s1.size(); i++) {
                for(int j = 0; j <= s2.size(); j++) {
                    dp[i][j] = false;
                }
            }

            dp[0][0] = true;
            for(int i = 0; i < s1.size(); i++) {
                dp[i + 1][0] = s1[i] == s3[i];
            }

            for(int j = 0; j < s2.size(); j++) {
                dp[0][j + 1] = s2[j] == s3[j];
            }

            for(int i = 1; i < s1.size() + 1; i++) {
                for(int j = 1; j < s2.size() + 1; j++) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                    dp[i][j] = dp[i][j] || dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                }
            }

            return dp[s1.size()][s2.size()];
        }
};
