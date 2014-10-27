public class Solution {
	public boolean canJump(int[] A) {
		int target = A.length - 1;
		for(int index = A.length - 2; index >= 0; index--) {
			if(A[index] + index >= target)
				target = index;
		}
		return target <= 0;
	}
}
