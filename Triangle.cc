class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>());
        for(int i = 0; i < triangle.size(); i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[i].push_back(triangle[i][j]);
            }
        }

        for(int i = dp.size() - 2; i >= 0; i--) {
            for(int j = 0; j < dp[i].size(); j++) {
                dp[i][j] += min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
