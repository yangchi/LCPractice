class Solution {
    public:
        int uniquePaths(int m, int n) {
            int ways[m][n];
            for(int i = 0; i < m; i++) {
                ways[i][n-1] = 1;
            }
            for(int i = 0; i < n; i++) {
                ways[m-1][i] = 1;
            }
            for(int i = m - 2; i >=0; i--) {
                for(int j = n - 2; j >= 0; j--) {
                    ways[i][j] = ways[i][j + 1] + ways[i + 1][j];
                }
            }
            return ways[0][0];
        }
};
