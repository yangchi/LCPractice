public class Solution {
	public int maxProduct(int[] A) {
		int[] maxUntil = new int[A.length];
		int[] minUntil = new int[A.length];
		maxUntil[0] = A[0];
		minUntil[0] = A[0];
		int maxprd = A[0];
		for(int i = 1; i < A.length; i++) {
			maxUntil[i] = Math.max(maxUntil[i - 1] * A[i], minUntil[i - 1] * A[i]);
			maxUntil[i] = Math.max(maxUntil[i], A[i]);
			minUntil[i] = Math.min(maxUntil[i-1] * A[i], minUntil[i - 1] * A[i]);
			minUntil[i] = Math.min(minUntil[i], A[i]);
			maxprd = Math.max(maxprd, maxUntil[i]);
		}
		return maxprd;
	}
}
