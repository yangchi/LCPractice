public class Solution {
	public void rotate(int[][] matrix) {
		int temp;
		int half = matrix.length / 2;
		for(int i = 0; i < half; i++) {
			for(int j = 0; j < (matrix.length % 2 == 0 ? half : half + 1); j++) {
				temp = matrix[i][j];
				matrix[i][j] = matrix[matrix.length - 1 - j][i];
				matrix[matrix.length - 1 - j][i] = matrix[matrix.length - 1 - i][matrix.length - 1 - j];
				matrix[matrix.length - 1 - i][matrix.length - 1 - j] = matrix[j][matrix.length - i - 1];
				matrix[j][matrix.length - i - 1] = temp;
			}
		}
	}
}
