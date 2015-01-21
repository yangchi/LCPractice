class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if (dungeon.empty()) {
            return 1;
        }

        if (dungeon[0].empty()) {
            return 1;
        }
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[rows - 1][cols - 1] = dungeon[rows - 1][cols - 1] >= 0 ? 1 : -dungeon[rows - 1][cols - 1] + 1;

        for(int i = rows - 1; i >= 0; i--) {
            for(int j = cols - 1; j >= 0; j--) {
                int future_needs = INT_MIN;
                if (i == rows - 1 && j == cols - 1) {
                    continue;
                } else if (i == rows - 1) {
                    future_needs = dp[i][j + 1];
                } else if (j == cols - 1) {
                    future_needs = dp[i + 1][j];
                } else {
                    future_needs = min(dp[i + 1][j], dp[i][j + 1]);
                }

                if (dungeon[i][j] >= future_needs) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = future_needs - dungeon[i][j];
                }
            }
        }
        return dp[0][0];
    }
};
