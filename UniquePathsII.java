public class Solution {
	public int uniquePathsWithObstacles(int[][] obstacleGrid) {
		int num_rows = obstacleGrid.length;
		if(num_rows == 0)
			return 0;
		int num_cols = obstacleGrid[0].length;
		int [][] choices = new int [num_rows][num_cols];
		int index = num_rows - 1;
		while(index >= 0 && obstacleGrid[index][num_cols - 1] != 1)
			choices[index--][num_cols - 1] = 1;
		index = num_cols - 1;
		while(index >= 0 && obstacleGrid[num_rows - 1][index] != 1) {
			choices[num_rows - 1][index--] = 1;
		}
		for(int i = num_rows - 2; i >= 0; i--) {
			for(int j = num_cols - 2; j >= 0; j--) {
				if(obstacleGrid[i][j] == 1)
					choices[i][j] = 0;
				else {
					choices[i][j] = choices[i][j + 1] + choices[i + 1][j];
				}
			}
		}
		return choices[0][0];
	}
}
