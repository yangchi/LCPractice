public class Solution {
	public boolean canJump(int[] A) {
		boolean [] makeit = new boolean[A.length];
		makeit[0] = true;
		for(int i = 0; i < A.length; i++) {
			int current = A[i];
			if(i + current >= A.length)
				current = A.length - i - 1;
			while(current > 0) {
				makeit[i + current--] = true;
			}
		}
		return makeit[makeit.length - 1];
	}
}
