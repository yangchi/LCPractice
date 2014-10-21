public class Solution {
	public int findMin(int[] num) {
		for(int i = 1; i < num.length; i++) {
			if(num[i] < num[i-1])
				return num[i];
		}
		return num[0];
	}
}
