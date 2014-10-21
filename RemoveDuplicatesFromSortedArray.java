public class Solution {
	public int removeDuplicates(int[] A) {
		if(A.length == 0) {
			return 0;
		}
		int value = A[0];
		int index = 1;
		for(int i = 1; i < A.length; i++) {
			if(A[i] == value) {
				continue;
			} else {
				A[index++] = A[i];
				value = A[i];
			}
		}
		return index;
	}
}
