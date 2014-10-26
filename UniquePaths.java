public class Solution {
	public int uniquePaths(int m, int n) {
		int [][]choices = new int[m][n];
		for(int i = 0; i < m; i++)
			choices[i][n - 1] = 1;
		for(int i = 0; i < n; i++)
			choices[m - 1][i] = 1;
		for(int i = m - 2; i>=0; i--) {
			for(int j = n - 2; j >=0; j--) {
				choices[i][j] = choices[i + 1][j] + choices[i][j + 1];
			}
		}
		return choices[0][0];
	}
}
