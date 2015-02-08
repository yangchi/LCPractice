class Solution {
    public:
        int calculateMinimumHP(vector<vector<int> > &dungeon) {
            int rows = dungeon.size();
            int cols = dungeon[0].size();
            int dp[rows][cols];
            int blood;
            dp[rows - 1][cols - 1] = dungeon[rows - 1][cols - 1] < 0 ? -dungeon[rows - 1][cols - 1] + 1 : 1;
            for(int i = cols - 2; i >= 0; i--) {
                int needs = dp[rows - 1][i + 1] - dungeon[rows - 1][i];
                dp[rows - 1][i] = needs > 0 ? needs : 1;
            }

            for(int i = rows - 2; i >= 0; i--) {
                int needs = dp[i + 1][cols - 1] - dungeon[i][cols - 1];
                dp[i][cols - 1] = needs > 0 ? needs: 1;
            }

            for(int i = rows - 2; i>= 0; i--) {
                for(int j = cols - 2; j >= 0; j--) {
                    int needs = -dungeon[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
                    dp[i][j] = needs > 0 ? needs: 1;
                }
            }

            return dp[0][0] == 0 ? 1 : dp[0][0];
        }
};
