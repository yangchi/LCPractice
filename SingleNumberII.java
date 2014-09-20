public class Solution {
	public int singleNumber(int[] A) {
		int result[] = new int[32];
		for (int i = 0; i < A.length; i++) {
			for(int j = 0; j < 32; j++) {
				result[j] += takeNthBit(A[i], j);
			}
		}
		int result_number = 0;
		for (int i = 0; i < 32; i++) {
			result[i] %= 3;
			result_number |= result[i] << i;
		}
		return result_number;
	}

	public int takeNthBit(int input, int n) {
		int temp = 1;
		temp = temp << n;
		return (input & temp) >> n;
	}
}
